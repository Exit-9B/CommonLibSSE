#pragma once

#include "RE/B/BSTEvent.h"
#include "vr/COpenVRContext.h"
#include "vr/OpenVRTypes.h"

#ifdef SKYRIMVR

namespace RE
{
	struct VROverlayChange;
	struct VRDeviceConnectionChange;
	struct VRResetHMDHeight;

	class BSVRInterface : public BSTEventSource<VROverlayChange>,           // 00
						  public BSTEventSource<VRDeviceConnectionChange>,  // 58
						  public BSTEventSource<VRResetHMDHeight>           // B0
	{
	public:
		[[nodiscard]] vr::IVROverlay* VROverlay()
		{
			REL::Relocation<vr::IVROverlay*(vr::COpenVRContext&)> get{ REL::Offset(0x8A0110) };
			return get(moduleContext);
		}

		// members
		std::uint64_t         unk108;          // 108
		std::uint64_t         unk110;          // 118
		std::uint64_t         unk118;          // 118
		std::uint64_t         unk120;          // 120
		std::uint64_t         unk128;          // 128
		std::uint64_t         unk130;          // 130
		std::uint64_t         unk138;          // 138
		std::uint64_t         unk140;          // 140
		std::uint64_t         unk148;          // 148
		std::uint64_t         unk150;          // 150
		std::uint64_t         unk158;          // 158
		std::uint64_t         unk160;          // 160
		std::uint64_t         unk168;          // 168
		std::uint64_t         unk170;          // 170
		std::uint64_t         unk178;          // 178
		std::uint64_t         unk180;          // 180
		std::uint64_t         unk188;          // 188
		vr::COpenVRContext    moduleContext;   // 190
		vr::VROverlayHandle_t currentOverlay;  // 1F8
		std::uint64_t         unk200;          // 200
	};
	static_assert(sizeof(BSVRInterface) == 0x208);
}
#endif
