#include "RE/B/BSPointerHandleManager.h"

namespace RE
{
	auto BSPointerHandleManager::GetHandleEntries()
	{
		REL::Relocation<Entry(*)[0x100000]> entries{ Offset::BSPointerHandleManager::GetHandleEntries };
		return std::span<Entry, 0x100000>{ *entries };
	}
}
