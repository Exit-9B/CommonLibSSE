#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	struct ReadyWeaponHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_ReadyWeaponHandler;

		~ReadyWeaponHandler() override;  // 00

		// override (PlayerInputHandler)
		bool CanProcess(InputEvent* a_event) override;                                // 01
		void HandleEvent(ButtonEvent* a_event, PlayerControlsData* a_data) override;  // 06
	};
	static_assert(sizeof(ReadyWeaponHandler) == 0x10);
}
