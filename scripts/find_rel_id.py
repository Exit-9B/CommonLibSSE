import argparse
import csv
import fileinput
import os
import re
from typing import List

HEADER_TYPES = (".h", ".hpp", ".hxx")
SOURCE_TYPES = (".c", ".cpp", ".cxx")
ALL_TYPES = HEADER_TYPES + SOURCE_TYPES
PATTERN = r"rel::id\([^)]+\)"
PATTERN_GROUPS = r"(rel::id\((?:([0-9]+)|(?:([0-9]+)[^)]*(0x[0-9a-f]*)))\))"
REPLACEMENT = """
#ifndef SKYRIMVR
	{} 
#else
	{}  // TODO: VERIFY
#endif
"""
id_sse = {}
id_vr = {}


def add_hex_strings(input1: str, input2: str = "0") -> str:
    """Return sum of two hex strings.

    Args:
        input1 (str): Hex formatted string.
        input2 (str, optional): Hex formatted string. Defaults to "0".

    Returns:
        str: Hex string sum.
    """
    return hex(int(input1, 16) + int(input2, 16))


def load_database(addresslib="addrlib.csv", offsets="offsets-1.5.97.0.csv") -> int:
    """Load databases.

    Args:
        addresslib (str, optional): Name of csv with VR Address, SSE Address, ID (e.g., 0x1400010d0,0x1400010d0,2). Defaults to "addrlib.csv".
        offsets (str, optional): Name of csv with ID, SSE Address (e.g., 2,10d0). SSE Address is an offset that needs to be added to a base and is dumped from Address Library. Defaults to "offsets-1.5.97.0.csv".

    Returns:
        int: Number of successfully loaded csv files. 0 means none were loaded.
    """
    loaded = 0
    try:
        with open(addresslib, mode="r") as infile:
            reader = csv.reader(infile)
            for row in reader:
                id = int(row[2])
                sse = add_hex_strings(row[1])
                vr = add_hex_strings(row[0])
                id_sse[id] = sse
                id_vr[id] = vr
                loaded += 1
    except FileNotFoundError:
        print(f"{addresslib} not found")

    try:
        with open(offsets, mode="r") as infile:
            reader = csv.reader(infile)
            for row in reader:
                id = int(row[0])
                sse = add_hex_strings(f"0x{row[1]}", "0x140000000")
                if id_sse.get(id) and id_sse.get(id) != sse:
                    print(f"Warning: {id} mismatch {sse}	{id_sse.get(id)}")
                elif id_sse.get(id) is None:
                    id_sse[id] = sse
                loaded += 1
    except FileNotFoundError:
        print(f"{offsets} not found")
    return loaded


def find_rel_id(
    a_directory: str, a_exclude: List[str], in_file_replace: bool = False
) -> None:
    """Find uses of rel::id.

    Args:
        a_directory (str): Root directory to walk.
        a_exclude (List[str]): List of file names to ignore.
        in_file_replace (bool, optional): Whether to replace discovered items based on REPLACEMENT. Defaults to False.
    """

    tmp = []
    for dirpath, dirnames, filenames in os.walk(a_directory):
        rem = []
        for dirname in dirnames:
            if dirname in a_exclude:
                rem.append(dirname)
        for todo in rem:
            dirnames.remove(todo)

        for filename in filenames:
            if (
                filename not in a_exclude
                and not filename.lower().startswith("offset")
                and filename.endswith(ALL_TYPES)
            ):
                with open(f"{dirpath}/{filename}") as f:
                    for i, line in enumerate(f):
                        matches = re.findall(
                            PATTERN_GROUPS, line, flags=re.IGNORECASE | re.MULTILINE
                        )
                        offset = 0
                        for match in matches:
                            try:
                                id = int(match[1])
                            except ValueError:
                                # match has offset
                                id = int(match[2])
                                offset = match[3]
                            try:
                                conversion = f"REL::Offset(0x{id_vr[id][4:]})"
                            except KeyError:
                                try:
                                    conversion = f"UNKNOWN SSE_{id_sse[id]}{f'+{offset}={add_hex_strings(id_sse[id], offset)}' if offset else ''}"
                                except KeyError:
                                    conversion = f"UNKNOWN"

                            tmp.append(
                                f"{dirpath[len(a_directory)+1:]}/{filename}:{i+1} {match[0]} {conversion}"
                            )
    if tmp:
        tmp.sort()
        if in_file_replace:
            for line in tmp:
                parts = line.split(" ")
                filename, line_number = parts[0].split(":")
                text_to_replace = parts[1]
                replacement = (
                    parts[2] if parts[2] != "UNKNOWN" else f"REL::Offset({parts[3]})"
                )
                with fileinput.FileInput(filename, inplace=True) as file:
                    print(f"Performing replace for {parts[0]}")
                    found_ifndef = False
                    for i, line in enumerate(file):
                        if "#ifndef SKYRIMVR".lower() in line.lower():
                            found_ifndef = True
                            print(line, end="")
                        elif found_ifndef and text_to_replace in line:
                            found_ifndef = False
                            print(line, end="")
                        else:
                            print(
                                line.replace(
                                    text_to_replace,
                                    REPLACEMENT.format(text_to_replace, replacement),
                                ),
                                end="",
                            )
        else:
            print(*tmp, sep="\n")
            print(f"Found {len(tmp)} items")
            exit(len(tmp))


def main():
    parser = argparse.ArgumentParser(
        description="Find uses of REL::ID in cpp files. By default, will display a list of files besides Offsets*.h which are using REL::ID and should be converted to REL::Offset for VR. Unknown addresses will be prefaced SSE_. The list is intended for linting."
    )
    parser.add_argument(
        "--replace",
        action="store_true",
        help="Replace files automatically inline #ifndef SKYRIMVR with bin-diffed discovered addresses. Unknown addresses will be prefaced SSE_ and need to be manually fixed. This should be used for quick address testing because it is preferred to save all values in Offsets*.h",
    )

    args = parser.parse_args()

    root = os.path.split(os.path.dirname(os.path.realpath(__file__)))[0]
    os.chdir(root)
    exclude = []
    if load_database(addresslib="scripts/addrlib.csv", offsets="scripts/offsets-1.5.97.0.csv") == 0:
        print("Error, no databases loaded. Exiting.")
        exit(1)
    else:
        find_rel_id(root, exclude, in_file_replace=args.replace)


if __name__ == "__main__":
    main()
