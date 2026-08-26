#pragma once

#include "RE/H/HeldStateHandler.h"

namespace RE
{
	struct RunHandler : public HeldStateHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_RunHandler;

		~RunHandler() override;  // 00

		// override (PlayerInputHandler)
		bool CanProcess(InputEvent* a_event) override;                                // 01
		void HandleEvent(ButtonEvent* a_event, PlayerControlsData* a_data) override;  // 06
	};
	static_assert(sizeof(RunHandler) == 0x18);
}
