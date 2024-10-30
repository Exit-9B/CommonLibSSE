#pragma once

#include "RE/V/VRWandEvent.h"

namespace RE
{
	class VrWandTouchpadPositionEvent : public VRWandEvent
	{
	public:
		float         unk30;  // 30
		float         unk34;  // 34
		std::uint32_t unk38;  // 38
		std::uint32_t unk3C;  // 3C
		std::uint32_t unk40;  // 40
		std::uint32_t unk44;  // 44
	};
	static_assert(sizeof(VrWandTouchpadPositionEvent) == 0x48);
}
