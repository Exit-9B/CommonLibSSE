#include "RE/B/BSWin32SystemUtility.h"

namespace RE
{
	BSWin32SystemUtility* BSWin32SystemUtility::GetSingleton()
	{
		using func_t = decltype(&BSWin32SystemUtility::GetSingleton);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSWin32SystemUtility::GetSingleton) };
		return func();
	}
}
