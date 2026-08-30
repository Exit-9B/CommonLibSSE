#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/I/InputDevices.h"

namespace RE
{
	class BSIInputDevice;
	class BSPCGamepadDeviceDelegate;
	class BSPCGamepadDeviceHandler;
	class BSWin32KeyboardDevice;
	class BSWin32MouseDevice;
	class BSWin32VirtualKeyboardDevice;
	class InputEvent;
	struct BSRemoteGamepadEvent;

	class BSInputDeviceManager :
		public BSTEventSource<InputEvent*>,           // 000
		public BSTSingletonSDM<BSInputDeviceManager>  // 058
	{
	public:
		static BSInputDeviceManager* GetSingleton();

		bool                          GetButtonNameFromID(INPUT_DEVICE a_device, std::int32_t a_id, BSFixedString& a_buttonName) const;
		BSPCGamepadDeviceDelegate*    GetGamepad();
		BSPCGamepadDeviceHandler*     GetGamepadHandler();
		BSWin32KeyboardDevice*        GetKeyboard();
		BSWin32MouseDevice*           GetMouse();
		BSWin32VirtualKeyboardDevice* GetVirtualKeyboard();
		bool                          IsGamepadConnected();
		bool                          IsGamepadEnabled();

		// members
		std::uint8_t                         pad59;                           // 059
		std::uint16_t                        pad5A;                           // 05A
		std::uint32_t                        pad5C;                           // 05C
		BSIInputDevice*                      devices[INPUT_DEVICES::kTotal];  // 060
		bool                                 queuedGamepadEnableValue;        // 090
		bool                                 valueQueued;                     // 091
		bool                                 pollingEnabled;                  // 092
		std::uint8_t                         pad093;                          // 093
		std::uint32_t                        pad094;                          // 094
		BSTEventSource<BSRemoteGamepadEvent> remoteGamepadEventSource;        // 098
		std::uint8_t                         unk0F0;                          // 0F0
		std::uint8_t                         unk0F1;                          // 0F1
		std::uint16_t                        unk0F2;                          // 0F2
		std::uint32_t                        unk0F4;                          // 0F4
		std::uint64_t                        unk0F8;                          // 0F8
	};
#if HAS_SKYRIMSE(1, 7, 99)
	static_assert(sizeof(BSInputDeviceManager) == 0x100);
#elif !defined(SKYRIMVR)
	static_assert(sizeof(BSInputDeviceManager) == 0xF0);
#else
	static_assert(sizeof(BSInputDeviceManager) == 0x120);
#endif
}
