#pragma once

#include "RE/B/BSVRInterface.h"

#ifdef SKYRIMVR
namespace RE
{
	class BSOpenVR : public BSVRInterface
	{
	public:
		struct Data238
		{
			std::uint64_t unk00;  // 00
			std::uint64_t unk08;  // 08
			std::uint64_t unk10;  // 10
			std::uint64_t unk18;  // 18
			std::uint64_t unk20;  // 20
			std::uint64_t unk28;  // 28
			std::uint64_t unk30;  // 30
			std::uint64_t unk38;  // 38
		};
		static_assert(sizeof(Data238) == 0x40);

		[[nodiscard]] static BSOpenVR* GetSingleton()
		{
			REL::Relocation<BSOpenVR**> singleton{ REL::Offset(0x2FEB9B0) };
			return *singleton;
		}

		// members
		std::uint64_t unk208;     // 208
		void*         unk210;     // 210
		std::uint64_t unk218;     // 218
		void*         unk220;     // 220
		std::uint64_t unk228;     // 228
		std::uint64_t unk230;     // 230
		Data238       unk238[4];  // 238
		std::uint64_t unk338;     // 338
		std::uint64_t unk340;     // 340
		std::uint64_t unk348;     // 348
		std::uint64_t unk350;     // 350
		std::uint64_t unk358;     // 358
		std::uint64_t unk360;     // 360
		std::uint64_t unk368;     // 368
		std::uint64_t unk370;     // 370
		std::uint64_t unk378;     // 378
		std::uint64_t unk380;     // 380
		std::uint64_t unk388[2];  // 388
		std::uint64_t unk398;     // 398
	};
	static_assert(sizeof(BSOpenVR) == 0x3A0);
}
#endif
