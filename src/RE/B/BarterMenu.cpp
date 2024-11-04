#include "RE/B/BarterMenu.h"

namespace RE
{
	RefHandle BarterMenu::GetTargetRefHandle()
	{
		REL::Relocation<RefHandle*> handle{ STATIC_OFFSET(BarterMenu::TargetRefHandle) };
		return *handle;
	}
}
