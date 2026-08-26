#pragma once

#include "RE/I/IDEvent.h"

namespace RE
{
	class MotionGestureEvent : public IDEvent
	{
	public:
#if 0
		inline static constexpr auto RTTI = RTTI_MotionGestureEvent;
#endif

		// members
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
	};
	static_assert(sizeof(MotionGestureEvent) == 0x38);
}
