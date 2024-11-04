#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTexture.h"

namespace RE
{
	namespace BSGraphics
	{
		class State
		{
		public:
			[[nodiscard]] static State* GetSingleton();

			// members
			NiPointer<NiTexture> projectedNoise;               // 000
			NiPointer<NiTexture> projectedDiffuse;             // 008
			NiPointer<NiTexture> projectedNormal;              // 010
			NiPointer<NiTexture> projectedNormalDetail;        // 018
			std::uint32_t        unk020;                       // 020
			std::uint32_t        screenWidth;                  // 024
			std::uint32_t        screenHeight;                 // 028
			std::uint32_t        frameBufferViewport[2];       // 02C
			std::uint32_t        unk034;                       // 034
			std::uint64_t        unk038;                       // 038
			std::uint64_t        unk040;                       // 040
			std::uint64_t        unk048;                       // 048
			bool                 insideFrame;                  // 050
			bool                 letterbox;                    // 051
			std::uint16_t        unk052;                       // 052
			std::uint32_t        unk054;                       // 054
			std::uint32_t        unk058;                       // 058
			std::uint32_t        unk05C;                       // 05C
			NiPointer<NiTexture> unk060;                       // 060 - black?
			NiPointer<NiTexture> defaultTextureWhite;          // 068
			NiPointer<NiTexture> defaultTextureGrey;           // 070
			NiPointer<NiTexture> defaultHeightMap;             // 078
			NiPointer<NiTexture> defaultReflectionCubeMap;     // 080
			NiPointer<NiTexture> defaultFaceDetailMap;         // 088
			NiPointer<NiTexture> defaultTexEffectMap;          // 090
			NiPointer<NiTexture> defaultTextureNormalMap;      // 098
			NiPointer<NiTexture> ditheringNoise;               // 0A0
			BSTArray<void*>      unk0A8;                       // 0A8
			std::uint32_t        unk0C0;                       // 0C0
			float                unk0C4[2][8];                 // 0C4
			float                dynamicResolutionWidth;       // 104
			float                dynamicResolutionHeight;      // 108
			float                prevDynamicResolutionWidth;   // 10C
			float                prevDynamicResolutionHeight;  // 110
			std::uint32_t        unk114;                       // 114
			std::uint32_t        unk118;                       // 118
#ifndef SKYRIMVR
			std::uint8_t unk11C;  // 11C
			std::uint8_t unk11D;  // 11D
			std::uint8_t unk11E;  // 11E
			std::uint8_t pad11F;  // 11F
#else
			std::uint8_t  unkVR11C;  // 11C
			std::uint8_t  unkVR11D;  // 11D
			std::uint16_t padVR11E;  // 11E
			std::int32_t  unkVR120;  // 120
			std::uint32_t padVR124;  // 124
#endif
		};
#ifndef SKYRIMVR
		static_assert(sizeof(State) == 0x120);
#endif
	}
}
