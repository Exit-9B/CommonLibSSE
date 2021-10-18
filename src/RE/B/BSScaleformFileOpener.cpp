#include "RE/B/BSScaleformFileOpener.h"

namespace RE
{
	GFile* BSScaleformFileOpener::OpenFile(const char* a_url, std::int32_t a_flags, std::int32_t a_mode)
	{
		using func_t = decltype(&BSScaleformFileOpener::OpenFile);
		static REL::Relocation<func_t> func{ REL::ID(80081) };
		return func(this, a_url, a_flags, a_mode);
	}

	std::int64_t BSScaleformFileOpener::GetFileModifyTime([[maybe_unused]] const char* a_url)
	{
		return 0;
	}

	GFile* BSScaleformFileOpener::OpenFileEx(const char* a_url, GFxLog* a_log, std::int32_t a_flags, std::int32_t a_mode)
	{
		using func_t = decltype(&BSScaleformFileOpener::OpenFileEx);
		static REL::Relocation<func_t> func{ REL::ID(80083) };
		return func(this, a_url, a_log, a_flags, a_mode);
	}
}
