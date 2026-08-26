#pragma once

#include "RE/H/HeldStateHandler.h"

namespace RE
{
	class Setting;

	struct AttackBlockHandler : public HeldStateHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_AttackBlockHandler;

		virtual ~AttackBlockHandler();  // 00

		// override (HeldStateHandler)
		virtual bool CanProcess(InputEvent* a_event) override;                                // 01
		virtual void HandleEvent(ButtonEvent* a_event, PlayerControlsData* a_data) override;  // 06
		virtual void UpdateHeldStateActive(const ButtonEvent* a_event) override;              // 07
		virtual void SetHeldStateActive(bool a_flag) override;                                // 08

		// members
#if HAS_SKYRIMSE(1, 7, 99)
		BSFixedString gestureEngageLL;     // 18
		BSFixedString gestureEngageLR;     // 20
		BSFixedString gestureEngageRL;     // 28
		BSFixedString gestureEngageRR;     // 30
		BSFixedString gesturePunchLeft;    // 38
		BSFixedString gesturePunchRight;   // 40
		BSFixedString gestureRaiseShield;  // 48
		BSFixedString gestureDropShield;   // 50
#endif
		std::uint64_t unk58;      // 58
		BSFixedString userEvent;  // 60
#if HAS_SKYRIMSE(1, 7, 99)
		std::uint64_t unk68;  // 68
		std::uint64_t unk70;  // 70
		std::uint64_t unk78;  // 78
		std::uint64_t unk80;  // 80
		std::uint64_t unk88;  // 88
		std::uint64_t unk90;  // 90
		std::uint32_t unk98;  // 98
#endif
		std::uint32_t unk9C;                       // 9C
		std::uint32_t unkA0;                       // A0
		Setting*      initialPowerAttackDelay;     // A8
		Setting*      subsequentPowerAttackDelay;  // B0
		std::uint8_t  unkB8;                       // B8
		std::uint8_t  unkB9;                       // B9
		std::uint8_t  unkBA;                       // BA
		std::uint8_t  unkBB;                       // BB
		std::uint16_t unkBC;                       // BC
	};
#if HAS_SKYRIMSE(1, 7, 99)
	static_assert(sizeof(AttackBlockHandler) == 0xC0);
#else
	static_assert(sizeof(AttackBlockHandler) == 0x48);
#endif
}
