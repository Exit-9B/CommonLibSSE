#include "RE/L/LockpickingMenu.h"

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	TESObjectREFR* LockpickingMenu::GetTargetReference()
	{
		REL::Relocation<TESObjectREFRPtr*> refptr{ Offset::LockpickingMenu::TargetReference };
		return refptr->get();
	}
}
