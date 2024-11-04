#include "RE/I/InterfaceStrings.h"

namespace RE
{
	InterfaceStrings* InterfaceStrings::GetSingleton()
	{
		REL::Relocation<InterfaceStrings**> singleton{ STATIC_OFFSET(InterfaceStrings::Singleton) };
		return *singleton;
	}
}
