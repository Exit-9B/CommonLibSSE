#include "RE/M/MenuCursor.h"

namespace RE
{
	MenuCursor* MenuCursor::GetSingleton()
	{
		REL::Relocation<MenuCursor**> singleton{ STATIC_OFFSET(MenuCursor::Singleton) };
		return *singleton;
	}
}
