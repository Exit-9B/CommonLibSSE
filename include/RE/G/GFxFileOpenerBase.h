#pragma once

#include "RE/G/GFileConstants.h"
#include "RE/G/GFxState.h"

namespace RE
{
	class GFile;
	class GFxLog;

	class GFxFileOpenerBase : public GFxState
	{
	protected:
		GFxFileOpenerBase() :
			GFxState()
		{
			stateType = GFxState::StateType::kFileOpener;
		}

	public:
		// add
		virtual GFile*       OpenFile(const char* a_url, std::int32_t a_flags = GFileConstants::OpenFlags::kRead | GFileConstants::OpenFlags::kBuffered, std::int32_t a_mode = GFileConstants::Modes::kReadWrite) = 0;                   // 01
		virtual std::int64_t GetFileModifyTime(const char* a_url) = 0;                                                                                                                                                                   // 02
		virtual GFile*       OpenFileEx(const char* a_url, GFxLog* a_log, std::int32_t a_flags = GFileConstants::OpenFlags::kRead | GFileConstants::OpenFlags::kBuffered, std::int32_t a_mode = GFileConstants::Modes::kReadWrite) = 0;  // 03
	};
}
