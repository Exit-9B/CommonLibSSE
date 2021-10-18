#pragma once

#include "RE/G/GFxZlibSupportBase.h"

namespace RE
{
	class GFxZlibSupport : public GFxZlibSupportBase
	{
	public:
		~GFxZlibSupport() override = default;

		GFile* CreateZlibFile(GFile* a_in) override;                                                        // 01
		void   InflateWrapper(GFxStream* a_inStream, void* a_buffer, std::int32_t a_bufferBytes) override;  // 02
	};
}
