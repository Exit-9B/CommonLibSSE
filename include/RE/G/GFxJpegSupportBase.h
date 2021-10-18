#pragma once

#include "RE/G/GFxState.h"

namespace RE
{
	class GFile;
	class GImage;
	class GJPEGInput;
	class GMemoryHeap;

	class GFxJpegSupportBase : public GFxState
	{
	protected:
		GFxJpegSupportBase() : GFxState()
		{
			stateType = GFxState::StateType::kJpegSupport;
		}

	public:
		// add
		virtual GJPEGInput* CreateSwfJpeg2HeaderOnly(GFile* a_in) = 0;                                // 01
		virtual GImage*     ReadJpeg(GFile* a_in, GMemoryHeap* a_imageHeap) = 0;                      // 02
		virtual GImage*     ReadSwfJpeg2(GFile* a_in, GMemoryHeap* a_imageHeap) = 0;                  // 03
		virtual GImage*     ReadSwfJpeg2WithTables(GJPEGInput* a_jin, GMemoryHeap* a_imageHeap) = 0;  // 04
		virtual GImage*     ReadSwfJpeg3(GFile* a_in, GMemoryHeap* a_imageHeap) = 0;                  // 05
	};
}
