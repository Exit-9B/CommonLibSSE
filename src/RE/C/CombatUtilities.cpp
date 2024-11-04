#include "RE/C/CombatUtilities.h"

namespace RE
{
	RE::NiPoint3 CombatUtilities::GetAngleToProjectedTarget(RE::NiPoint3 a_origin, RE::TESObjectREFR* a_target, float a_speed, float a_gravity, RE::ACTOR_LOS_LOCATION a_location)
	{
		using func_t = decltype(&CombatUtilities::GetAngleToProjectedTarget);
		REL::Relocation<func_t> func{ STATIC_OFFSET(CombatUtilities::GetAngleToProjectedTarget) };
		return func(a_origin, a_target, a_speed, a_gravity, a_location);
	}
}
