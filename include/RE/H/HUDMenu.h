#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"
#include "RE/W/WorldSpaceMenu.h"

namespace RE
{
	class ActorValueMeter;
	class HUDObject;
	class ShoutMeter;
	class UserEventEnabledEvent;
	struct BSRemoteGamepadEvent;

#ifndef SKYRIMVR
	// menuDepth = 2
	// flags = kAlwaysOpen | kRequiresUpdate | kAllowSaving | kCustomRendering | kAssignCursorToRenderer
	// context = kNone
	class HUDMenu :
		public IMenu,                                // 00
		public BSTEventSink<UserEventEnabledEvent>,  // 30
		public BSTEventSink<BSRemoteGamepadEvent>    // 38
	{
	public:
		inline static constexpr auto      RTTI = RTTI_HUDMenu;
		constexpr static std::string_view MENU_NAME = "HUD Menu";

		~HUDMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;                       // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                         // 04
		void               AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05
		void               RefreshPlatform() override;                                            // 08

		// override (BSTEventSink<UserEventEnabledEvent>)
		BSEventNotifyControl ProcessEvent(const UserEventEnabledEvent* a_event, BSTEventSource<UserEventEnabledEvent>* a_eventSource) override;  // 01

		// override (BSTEventSink<BSRemoteGamepadEvent>)
		BSEventNotifyControl ProcessEvent(const BSRemoteGamepadEvent* a_event, BSTEventSource<BSRemoteGamepadEvent>* a_eventSource) override;  // 01

		// members
		BSTArray<HUDObject*> objects;  // 40
		ActorValueMeter*     health;   // 58
		ActorValueMeter*     stamina;  // 60
		ActorValueMeter*     magicka;  // 68
		ShoutMeter*          shout;    // 70
		GFxValue             root;     // 78 - kDisplayObject - "_level0.HUDMovieBaseInstance"
		std::uint64_t        unk90;    // 90
	};
	static_assert(sizeof(HUDMenu) == 0x98);
#else
	class HUDMenu :
		public WorldSpaceMenu,                       // 00
		public BSTEventSink<UserEventEnabledEvent>,  // 58
		public BSTEventSink<BSRemoteGamepadEvent>    // 60
	{
	public:
		inline static constexpr auto      RTTI = RTTI_HUDMenu;
		constexpr static std::string_view MENU_NAME = "VR/VR_HMD_info";

		~HUDMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;                       // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                         // 04
		void               AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05
		void               RefreshPlatform() override;                                            // 08

		// override (BSTEventSink<HudModeChangeEvent>)
		BSEventNotifyControl ProcessEvent(const HudModeChangeEvent* a_event, BSTEventSource<HudModeChangeEvent>* a_eventSource) override;  // 01

		// override (BSTEventSink<UserEventEnabledEvent>)
		BSEventNotifyControl ProcessEvent(const UserEventEnabledEvent* a_event, BSTEventSource<UserEventEnabledEvent>* a_eventSource) override;  // 01

		// override (BSTEventSink<BSRemoteGamepadEvent>)
		BSEventNotifyControl ProcessEvent(const BSRemoteGamepadEvent* a_event, BSTEventSource<BSRemoteGamepadEvent>* a_eventSource) override;  // 01

		// members
		std::uint64_t        pad68;    // 68
		BSTArray<HUDObject*> objects;  // 70
		ActorValueMeter*     health;   // 88
		ActorValueMeter*     stamina;  // 90
		ActorValueMeter*     magicka;  // 98
		ShoutMeter*          shout;    // A0
		GFxValue             root;     // A8 - kDisplayObject - "_level0.HUDMovieBaseInstance"
		std::uint64_t        unk90;    // C0
	};
	static_assert(sizeof(HUDMenu) == 0xC8);
#endif
}
