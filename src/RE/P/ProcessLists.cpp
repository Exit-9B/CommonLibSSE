#include "RE/P/ProcessLists.h"

namespace RE
{
	ProcessLists* ProcessLists::GetSingleton()
	{
		REL::Relocation<ProcessLists**> singleton{ STATIC_OFFSET(ProcessLists::Singleton) };
		return *singleton;
	}

	void ProcessLists::ClearCachedFactionFightReactions() const
	{
		using func_t = decltype(&ProcessLists::ClearCachedFactionFightReactions);
		REL::Relocation<func_t> func{ STATIC_OFFSET(ProcessLists::ClearCachedFactionFightReactions) };
		return func(this);
	}

	void ProcessLists::StopCombatAndAlarmOnActor(Actor* a_actor, bool a_notAlarm)
	{
		using func_t = decltype(&ProcessLists::StopCombatAndAlarmOnActor);
		REL::Relocation<func_t> func{ STATIC_OFFSET(ProcessLists::StopCombatAndAlarmOnActor) };
		return func(this, a_actor, a_notAlarm);
	}
}
