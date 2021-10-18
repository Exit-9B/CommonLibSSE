#pragma once

#include "RE/G/GFxState.h"

namespace RE
{
	class GFile;
	class GFxStream;

	class GFxZlibSupportBase : public GFxState
	{
	protected:
		GFxZlibSupportBase() :
			GFxState()
		{
			stateType = GFxState::StateType::kZlibSupport;
		}

	public:
		// add
		virtual GFile* CreateZlibFile(GFile* a_in) = 0;                                                        // 01
		virtual void   InflateWrapper(GFxStream* a_inStream, void* a_buffer, std::int32_t a_bufferBytes) = 0;  // 02
	};
}
