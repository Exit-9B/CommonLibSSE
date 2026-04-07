#include "SKSE/Logger.h"

#include "SKSE/API.h"

#include <ShlObj.h>

namespace SKSE
{
	namespace log
	{
		std::optional<std::filesystem::path> log_directory()
		{
			wchar_t*                                               buffer{ nullptr };
			const auto                                             result = ::SHGetKnownFolderPath(::FOLDERID_Documents, ::KNOWN_FOLDER_FLAG::KF_FLAG_DEFAULT, nullptr, std::addressof(buffer));
			std::unique_ptr<wchar_t[], decltype(&::CoTaskMemFree)> knownPath(buffer, ::CoTaskMemFree);
			if (!knownPath || result != S_OK) {
				error("failed to get known folder path"sv);
				return std::nullopt;
			}

			std::filesystem::path path = knownPath.get();
			path /= "My Games"sv;
#ifdef SKYRIMVR
			path /= "Skyrim VR"sv;
#else
			if (::GetModuleHandle(TEXT("Galaxy64"))) {
				path /= "Skyrim Special Edition GOG"sv;
			} else {
				path /= "Skyrim Special Edition"sv;
			}
#endif
			path /= "SKSE"sv;
			return path;
		}
	}
}
