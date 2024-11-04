#include "RE/E/Effect.h"

namespace RE
{
	Effect::EffectItem::EffectItem() :
		magnitude(0.0),
		area(0),
		duration(0)
	{}

	Effect::Effect() :
		effectItem(),
		pad0C(0),
		baseEffect(nullptr),
		cost(0.0),
		pad1C(0),
		conditions()
	{}

	void Effect::Copy(const Effect* a_other)
	{
		using func_t = decltype(&Effect::Copy);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Effect::Copy) };
		return func(this, a_other);
	}

	void Effect::SetDuration(std::int32_t a_duration)
	{
		using func_t = decltype(&Effect::SetDuration);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Effect::SetDuration) };
		return func(this, a_duration);
	}

	void Effect::SetMagnitude(float a_magnitude)
	{
		using func_t = decltype(&Effect::SetMagnitude);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Effect::SetMagnitude) };
		return func(this, a_magnitude);
	}
}
