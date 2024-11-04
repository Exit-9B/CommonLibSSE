#include "RE/L/LockpickingMenu.h"

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	TESObjectREFR* LockpickingMenu::GetTargetReference()
	{
		REL::Relocation<TESObjectREFRPtr*> refptr{ STATIC_OFFSET(LockpickingMenu::TargetReference) };
		return refptr->get();
	}
}
