#pragma once

#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTEvent.h"
#include "RE/I/IMenu.h"
#include "RE/M/MenuEventHandler.h"

namespace RE
{
	class MenuOpenCloseEvent;
	class TESObjectREFR;

	// menuDepth = 3
	// flags = kPausesGame | kDisablePauseMenu | kRequiresUpdate
	// context = kLockpicking
	class LockpickingMenu :
		public IMenu,                            // 00
		public MenuEventHandler,                 // 30
		public BSTEventSink<MenuOpenCloseEvent>  // 40
	{
	public:
		inline static constexpr auto      RTTI = RTTI_LockpickingMenu;
		constexpr static std::string_view MENU_NAME = "Lockpicking Menu";

		~LockpickingMenu() override;  // 00

		// override (IMenu)
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;  // 04

		// override (MenuEventHandler)
		bool ShouldHandleEvent(const InputEvent* a_event) override;  // 01
		bool HandleEvent(const ButtonEvent* a_event) override;       // 07
		bool HandleEvent(const MouseMoveEvent* a_event) override;    // 06
		bool HandleEvent(const ThumbstickEvent* a_event) override;   // 05

		// override (BSTEventSink<MenuOpenCloseEvent>)
		BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01

		[[nodiscard]] TESObjectREFR* GetTargetReference();

		// members
		void*         unk048;  // 048
		void*         unk050;  // 050
		float         unk058;  // 058
		std::uint32_t unk05C;  // 05C
		std::uint64_t unk060;  // 060
		float         unk068;  // 068
		std::uint32_t unk06C;  // 06C
		std::uint64_t unk070;  // 070
		std::uint32_t unk078;  // 078
		std::uint32_t unk07C;  // 07C
		std::uint32_t unk080;  // 080
		std::uint32_t unk084;  // 084
		std::uint64_t unk088;  // 088
		std::uint64_t unk090;  // 090
		std::uint64_t unk098;  // 098
		std::uint64_t unk0A0;  // 0A0
		std::uint64_t unk0A8;  // 0A8
		std::uint64_t unk0B0;  // 0B0
		std::uint64_t unk0B8;  // 0B8
		std::uint64_t unk0C0;  // 0C0
		float         unk0C8;  // 0C8
		std::uint32_t unk0CC;  // 0CC
		std::uint64_t unk0D0;  // 0D0
		float         unk0D8;  // 0D8
		std::uint32_t unk0DC;  // 0DC
		std::uint32_t unk0E0;  // 0E0
		std::uint32_t unk0E4;  // 0E4
#if HAS_SKYRIMSE(1, 7, 99)
		std::uint64_t unk0E8;  // 0E8
		std::uint32_t unk0F0;  // 0F0
		std::uint16_t unk0F4;  // 0F4
		std::uint8_t  unk0F6;  // 0F6
		std::uint8_t  pad0F7;  // 0F7
		std::uint32_t unk0F8;  // 0F8
#endif
		std::uint32_t unk0FC;  // 0E8
		BSSoundHandle unk100;  // 0EC
		std::uint32_t unk10C;  // 0F8
		std::uint32_t unk110;  // 0FC
		std::uint32_t unk114;  // 100
		std::uint32_t unk118;  // 104
		std::uint16_t unk11C;  // 108
		std::uint8_t  unk11E;  // 10A
		std::uint8_t  unk11F;  // 10B
		std::uint8_t  unk120;  // 10C
		std::uint8_t  unk121;  // 10D
		std::uint8_t  unk122;  // 10E
	};
#if HAS_SKYRIMSE(1, 7, 99)
	static_assert(sizeof(LockpickingMenu) == 0x128);
#elif !defined(SKYRIMVR)
	static_assert(sizeof(LockpickingMenu) == 0x110);
#else
	static_assert(sizeof(LockpickingMenu) == 0x120);
#endif
}
