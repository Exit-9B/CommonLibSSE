#pragma once

#include "RE/G/GFxCharacterDef.h"

namespace RE
{
	class GASExecuteTag;

	class GFxTimelineDef : public GFxCharacterDef
	{
	public:
		struct FrameData
		{
			GASExecuteTag* data;
			std::uint32_t  size;
		};

		// add
		virtual std::uint32_t GetFrameCount() = 0;                                                                          // 0A
		virtual FrameData*    GetFrameData1(FrameData& a_data, std::int32_t a_frameNumber) = 0;                             // 0B
		virtual FrameData*    GetFrameData2(FrameData& a_data, std::int32_t a_frameNumber) = 0;                             // 0B
		virtual bool          GetLabeledFrame(const char* a_label, std::int32_t& a_frameNumber, bool a_labelIsNumber) = 0;  // 0D
	};
	static_assert(sizeof(GFxTimelineDef) == 0x20);
}
