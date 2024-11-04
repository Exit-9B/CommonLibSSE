#include "RE/T/TESCamera.h"

namespace RE
{
	void TESCamera::SetState(TESCameraState* a_state)
	{
		using func_t = decltype(&TESCamera::SetState);
		REL::Relocation<func_t> func{ STATIC_OFFSET(TESCamera::SetState) };
		return func(this, a_state);
	}
}
