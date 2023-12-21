#pragma once

#include "RE/N/NiPoint3.h"
#include "RE/N/NiRefObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class bhkAabbPhantom;
	class bhkRigidBody;
	class TESObjectCELL;

	class LoadedAreaBound : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_LoadedAreaBound;

		virtual ~LoadedAreaBound();  // 00

		// members
		NiPointer<bhkAabbPhantom>                phantoms[6];           // 10
		TESObjectCELL*                           currentCell;           // 40
		BSTHashMap<bhkRigidBody*, std::uint16_t> boundCollisions;       // 48
		NiPoint3                                 maxExtent;             // 78
		NiPoint3                                 minExtent;             // 84
		float                                    innerOffset;           // 90 - 20.0
		float                                    outerOffset;           // 94 - 600.0
		float                                    exteriorHeightOffset;  // 98 - 1000.0
		float                                    reflectSpeed;          // 9C - 0.3
	};
	static_assert(sizeof(LoadedAreaBound) == 0xA0);
}
