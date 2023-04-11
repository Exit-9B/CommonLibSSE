#pragma once

#include "RE/B/BSInputDevice.h"
#include "RE/B/BSTEvent.h"

namespace RE
{
	struct BSGamepadEvent;

	class BSGamepadDevice :
		public BSInputDevice,                  // 00
		public BSTEventSource<BSGamepadEvent>  // 70
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSGamepadDevice;

		~BSGamepadDevice() override;  // 00

		// override (BSInputDevice)
		bool IsEnabled() const override;  // 07 - { return connected && userIndex != -1; }

		// add
		virtual void SetVibration(float a_largeMotor, float a_smallMotor) = 0;                            // 09
		virtual void SetDeviceLight(const std::uint32_t (&a_rgb)[3]);                                     // 0A - { return; }
		virtual void ResetDeviceLight();                                                                  // 0B - { return; }
		virtual bool IsRemoteController();                                                                // 0C - { return 0; }
		virtual void NormalizeThumbstickValue(int a_thumbX, int a_thumbY, float& a_xOut, float& a_yOut);  // 0D
		virtual void DoEnableListeningMode();                                                             // 0E - { return; }

		// members
		std::int32_t  userIndex;          // C8
		bool          connected;          // CC
		bool          listeningForInput;  // CD
		std::uint16_t padCE;              // CE
	};
	static_assert(sizeof(BSGamepadDevice) == 0xD0);
}
