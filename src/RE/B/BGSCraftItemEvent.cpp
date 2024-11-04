#include "RE/B/BGSCraftItemEvent.h"

namespace RE
{
	std::int32_t& BGSCraftItemEvent::GetIndex()
	{
		REL::Relocation<std::int32_t*> index{ STATIC_OFFSET(BGSCraftItemEvent::GetIndex) };
		return *index;
	}
}
