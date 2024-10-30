#pragma once

namespace RE
{
	struct INPUT_DEVICES
	{
		enum INPUT_DEVICE
		{
			kNone = static_cast<std::underlying_type_t<INPUT_DEVICE>>(-1),
			kKeyboard = 0,
			kMouse,
			kGamepad,
#ifdef SKYRIMVR
			kVivePrimary,
			kViveSecondary,
			kOculusPrimary,
			kOculusSecondary,
			kWMRPrimary,
			kWMRSecondary,
#endif
			kVirtualKeyboard,

			kTotal
		};
	};
	using INPUT_DEVICE = INPUT_DEVICES::INPUT_DEVICE;

#ifdef SKYRIMVR
	[[nodiscard]] inline bool IsVRWandDevice(INPUT_DEVICE a_device)
	{
		return a_device == INPUT_DEVICE::kVivePrimary ||
		       a_device == INPUT_DEVICE::kViveSecondary ||
		       a_device == INPUT_DEVICE::kOculusPrimary ||
		       a_device == INPUT_DEVICE::kOculusSecondary ||
		       a_device == INPUT_DEVICE::kWMRPrimary ||
		       a_device == INPUT_DEVICE::kWMRSecondary;
	}
#endif
}
