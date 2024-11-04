#include "RE/B/BGSStoryTeller.h"

namespace RE
{
	BGSStoryTeller* BGSStoryTeller::GetSingleton()
	{
		REL::Relocation<BGSStoryTeller**> singleton{ STATIC_OFFSET(BGSStoryTeller::Singleton) };
		return *singleton;
	}

	void BGSStoryTeller::BeginShutDownQuest(TESQuest* a_quest)
	{
		using func_t = decltype(&BGSStoryTeller::BeginShutDownQuest);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BGSStoryTeller::BeginShutDownQuest) };
		return func(this, a_quest);
	}

	void BGSStoryTeller::BeginStartUpQuest(TESQuest* a_quest)
	{
		using func_t = decltype(&BGSStoryTeller::BeginStartUpQuest);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BGSStoryTeller::BeginStartUpQuest) };
		return func(this, a_quest);
	}
}
