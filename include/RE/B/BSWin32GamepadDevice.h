#pragma once

#include "RE/B/BSPCGamepadDeviceDelegate.h"

namespace RE
{
	class BSWin32GamepadDevice : public BSPCGamepadDeviceDelegate
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSWin32GamepadDevice;

		struct Keys
		{
			enum Key : std::uint32_t
			{
				kUp = 0x0001,
				kDown = 0x0002,
				kLeft = 0x0004,
				kRight = 0x0008,
				kStart = 0x0010,
				kBack = 0x0020,
				kLeftThumb = 0x0040,
				kRightThumb = 0x0080,
				kLeftShoulder = 0x0100,
				kRightShoulder = 0x0200,

				kA = 0x1000,
				kB = 0x2000,
				kX = 0x4000,
				kY = 0x8000,

				kLeftTrigger = 0x0009,
				kRightTrigger = 0x000A
			};
		};
		using Key = Keys::Key;

		struct InputState
		{
		public:
			XInput::XINPUT_STATE xinputState;   // 00
			float                leftTrigger;   // 10
			float                rightTrigger;  // 14
			float                thumbLX;       // 18
			float                thumbLY;       // 1C
			float                thumbRX;       // 20
			float                thumbRY;       // 24
		};
		static_assert(sizeof(InputState) == 0x28);

		~BSWin32GamepadDevice() override;  // 00

		// override (BSPCGamepadDeviceDelegate)
		void Initialize() override;                                          // 01
		void Poll(float a_timeDelta) override;                               // 02
		void Shutdown() override;                                            // 03 - { return; }
		void ClearInputState() override;                                     // 08 - { std::memset(&unk0D8, 0, 0x50); }
		void SetVibration(float a_largeMotor, float a_smallMotor) override;  // 09 - { return; }

		// members
		InputState previousState;  // 0D8
		InputState currentState;   // 100
	};
	static_assert(sizeof(BSWin32GamepadDevice) == 0x128);
}
