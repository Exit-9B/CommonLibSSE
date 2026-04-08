#include "RE/RTTI.h"

namespace RE
{
	void* RTDynamicCast(void* a_inptr, std::int32_t a_vfDelta, void* a_srcType, void* a_targetType, std::int32_t a_isReference)
	{
		using func_t = decltype(&RTDynamicCast<>);
		REL::Relocation<func_t> func{ STATIC_OFFSET(RTDynamicCast) };
		return func(a_inptr, a_vfDelta, a_srcType, a_targetType, a_isReference);
	}
}
