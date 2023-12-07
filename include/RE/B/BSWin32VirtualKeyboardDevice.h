#pragma once

#include "RE/B/BSVirtualKeyboardDevice.h"

namespace RE
{
	class BSWin32VirtualKeyboardDevice : public BSVirtualKeyboardDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSWin32VirtualKeyboardDevice;

		~BSWin32VirtualKeyboardDevice() override;  // 00

		// override (BSVirtualKeyboardDevice)
		void Initialize() override;                 // 01 - { return; }
		void Poll(float a_timeDelta) override;      // 02 - { return; }
		void Shutdown() override;                   // 03 - { return; }
		void ClearInputState() override;            // 08 - { return; }
		void Start(const kbInfo* a_info) override;  // 0B - { return; }
		void Stop() override;                       // 0C - { return; }
		void UserCancelled() override;              // 0D - { return; }
	};
	static_assert(sizeof(BSWin32VirtualKeyboardDevice) == 0x70);
}
