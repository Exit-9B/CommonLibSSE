#include "RE/G/GiftMenu.h"

namespace RE
{
	RefHandle GiftMenu::GetTargetRefHandle()
	{
		REL::Relocation<RefHandle*> handle{ Offset::GiftMenu::TargetRefHandle };
		return *handle;
	}
}
