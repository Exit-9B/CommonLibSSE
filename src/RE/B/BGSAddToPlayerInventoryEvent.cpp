#include "RE/B/BGSAddToPlayerInventoryEvent.h"

namespace RE
{
	std::uint32_t& BGSAddToPlayerInventoryEvent::GetIndex()
	{
		REL::Relocation<std::uint32_t*> index{ STATIC_OFFSET(BGSAddToPlayerInventoryEvent::GetIndex) };
		return *index;
	}
}
