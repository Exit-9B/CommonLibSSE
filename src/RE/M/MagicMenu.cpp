#include "RE/M/MagicMenu.h"

namespace RE
{
	void MagicMenu::UpdateList()
	{
		using func_t = decltype(&MagicMenu::UpdateList);
		REL::Relocation<func_t> func{ STATIC_OFFSET(MagicMenu::UpdateList) };
		return func(this);
	}
}
