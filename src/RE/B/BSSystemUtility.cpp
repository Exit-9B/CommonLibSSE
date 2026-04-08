#include "RE/B/BSWin32SystemUtility.h"

namespace RE
{
	BSSystemUtility* BSSystemUtility::GetSingleton()
	{
		using func_t = decltype(&BSSystemUtility::GetSingleton);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSSystemUtility::GetSingleton) };
		return func();
	}
}
