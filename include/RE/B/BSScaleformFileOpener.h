#pragma once

#include "RE/G/GFxFileOpenerBase.h"

namespace RE
{
	class BSScaleformFileOpener : public GFxFileOpenerBase
	{
	public:
		~BSScaleformFileOpener() override = default;  // 00

		// override (GFxFileOpenerBase)
		GFile*       OpenFile(const char* a_url, std::int32_t a_flags, std::int32_t a_mode) override;                   // 01
		std::int64_t GetFileModifyTime(const char* a_url) override;                                                     // 02
		GFile*       OpenFileEx(const char* a_url, GFxLog* a_log, std::int32_t a_flags, std::int32_t a_mode) override;  // 03
	};
}
