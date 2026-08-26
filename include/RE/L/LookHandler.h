#pragma once

#include "RE/P/PlayerInputHandler.h"
#include "RE/S/SixaxisEvent.h"

namespace RE
{
	struct LookHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_LookHandler;

		~LookHandler() override;  // 00

		// override (PlayerInputHandler)
		bool CanProcess(InputEvent* a_event) override;                                    // 01
		void HandleEvent(MouseMoveEvent* a_event, PlayerControlsData* a_data) override;   // 05
		void HandleEvent(ThumbstickEvent* a_event, PlayerControlsData* a_data) override;  // 04

		// members
#if HAS_SKYRIMSE(1, 7, 99)
		std::uint32_t unk10;  // 10
		SixaxisEvent  unk18;  // 18
		std::uint64_t unkA8;  // A8
		std::uint32_t unkB0;  // B0
		std::uint32_t unkB4;  // B4
#endif
	};
#if HAS_SKYRIMSE(1, 7, 99)
	static_assert(sizeof(LookHandler) == 0xB8);
#else
	static_assert(sizeof(LookHandler) == 0x10);
#endif
}
