#include "RE/B/BarterMenu.h"

namespace RE
{
	RefHandle BarterMenu::GetTargetRefHandle()
	{
		REL::Relocation<RefHandle*> handle{ Offset::BarterMenu::TargetRefHandle };
		return *handle;
	}
}
