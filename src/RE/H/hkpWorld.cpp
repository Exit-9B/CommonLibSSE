#include "RE/H/hkpWorld.h"

namespace RE
{
	void hkpWorld::CastRay(const hkpWorldRayCastInput& a_input, hkpWorldRayCastOutput& a_output) const
	{
		using func_t = decltype(&hkpWorld::CastRay);
		REL::Relocation<func_t> func{ STATIC_OFFSET(hkpWorld::CastRay) };
		return func(this, a_input, a_output);
	}
}
