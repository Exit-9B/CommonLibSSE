#include "RE/M/MessageBoxMenu.h"

namespace RE
{
	bool MessageBoxMenu::Create(MessageBoxData* a_data)
	{
		using func_t = bool (*)(MessageBoxData*);
		REL::Relocation<func_t> func{ STATIC_OFFSET(MessageBoxMenu::Create_MessageBoxData) };
		return func(a_data);
	}
}
