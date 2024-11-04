#include "RE/B/BGSEntryPoint.h"

namespace RE
{
	BGSEntryPoint::EntryPoint* BGSEntryPoint::GetEntryPoint(ENTRY_POINT a_entryPoint)
	{
		if (a_entryPoint < ENTRY_POINT::kTotal) {
			REL::Relocation<EntryPoint*> entryPoints{ STATIC_OFFSET(BGSEntryPoint::EntryPoints) };
			return &entryPoints.get()[a_entryPoint];
		}

		return nullptr;
	}
}
