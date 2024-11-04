#include "RE/R/RaceSexMenu.h"

namespace RE
{
	void RaceSexMenu::ChangeName(const char* a_name)
	{
		using func_t = decltype(&RaceSexMenu::ChangeName);
		REL::Relocation<func_t> func{ STATIC_OFFSET(RaceSexMenu::ChangeName) };
		return func(this, a_name);
	}
}
