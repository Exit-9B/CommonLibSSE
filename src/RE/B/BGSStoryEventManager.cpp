#include "RE/B/BGSStoryEventManager.h"

namespace RE
{
	BGSStoryEventManager* BGSStoryEventManager::GetSingleton()
	{
		using func_t = decltype(&BGSStoryEventManager::GetSingleton);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BGSStoryEventManager::GetSingleton) };
		return func();
	}

	std::uint32_t BGSStoryEventManager::AddEvent_Impl(std::uint32_t a_index, const void* a_event)
	{
		using func_t = decltype(&BGSStoryEventManager::AddEvent_Impl);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BGSStoryEventManager::AddEvent) };
		return func(this, a_index, a_event);
	}
}
