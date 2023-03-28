#pragma once

#include "RE/I/InputEvent.h"

namespace RE
{
	class CharEvent : public InputEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_CharEvent;

		~CharEvent() override;  // 00

		std::uint32_t keyCode;  // 18
		std::uint32_t pad1C;    // 1C
	};
	static_assert(sizeof(CharEvent) == 0x20);
}
