#include "RE/G/GiftMenu.h"

namespace RE
{
	RefHandle GiftMenu::GetTargetRefHandle()
	{
		REL::Relocation<RefHandle*> handle{ STATIC_OFFSET(GiftMenu::TargetRefHandle) };
		return *handle;
	}
}
