#pragma once

#include "RE/I/IUIMessageData.h"

namespace RE
{
	class GFxEvent;

	class BSUIScaleformData : public IUIMessageData
	{
	public:
		inline static constexpr auto             RTTI = RTTI_BSUIScaleformData;
		inline static constexpr std::string_view CLASS_NAME = "BSUIScaleformData";

		~BSUIScaleformData() override;  // 00

		// members
		GFxEvent* scaleformEvent;  // 10
	};
	static_assert(sizeof(BSUIScaleformData) == 0x18);
}
