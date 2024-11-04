#include "RE/B/BSFaceGenAnimationData.h"

namespace RE
{
	void BSFaceGenAnimationData::Reset(float a_timer, bool a_resetExpression, bool a_resetModifierAndPhoneme, bool a_resetCustom, bool a_closeEyes)
	{
		using func_t = decltype(&BSFaceGenAnimationData::Reset);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSFaceGenAnimationData::Reset) };
		return func(this, a_timer, a_resetExpression, a_resetModifierAndPhoneme, a_resetCustom, a_closeEyes);
	}

	void BSFaceGenAnimationData::SetExpressionOverride(std::int32_t a_idx, float a_value)
	{
		using func_t = decltype(&BSFaceGenAnimationData::SetExpressionOverride);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSFaceGenAnimationData::SetExpressionOverride) };
		return func(this, a_idx, a_value);
	}
}
