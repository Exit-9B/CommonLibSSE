#pragma once

#include "RE/M/MenuEventHandler.h"

namespace RE
{
	struct DirectionHandler : public MenuEventHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_DirectionHandler;

		virtual ~DirectionHandler();  // 00

		// override (MenuEventHandler)
		bool ShouldHandleEvent(const InputEvent* a_event) override;  // 01
		bool HandleEvent(const ButtonEvent* a_event) override;       // 05
		bool HandleEvent(const ThumbstickEvent* a_event) override;   // 03

		// members
		std::uint32_t unk10;               // 10
		float         menuKeyRepeatLong;   // 14
		float         menuKeyRepeatShort;  // 18
		std::uint64_t unk20;               // 20
		std::uint32_t unk28;               // 28
		std::uint32_t unk2C;               // 2C
	};
	static_assert(sizeof(DirectionHandler) == 0x30);
}
