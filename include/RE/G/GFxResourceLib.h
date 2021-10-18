#pragma once

#include "RE/G/GRefCountBase.h"
#include "RE/G/GStats.h"

namespace RE
{
	class GFxResource;

	class GFxResourceLib : public GRefCountBase<GFxResourceLib, GStatGroups::kGStat_Default_Mem>
	{
		class GFxResourceSlot;

		~GFxResourceLib() override;  // 00

		// add
		virtual void RemoveResourceOnRelease(GFxResource* a_res) = 0;  // 01
		virtual void PinResource(GFxResource* a_res) = 0;              // 02
		virtual void UnpinResource(GFxResource* a_res) = 0;            // 03

		// members
		void*                    pad10;
		WinAPI::CRITICAL_SECTION criticalSection;
		void*                    pad40;
		GMemoryHeap*             imageHeap;
	};
	static_assert(sizeof(GFxResourceLib) == 0x50);
}
