#include "RE/U/UserEvents.h"

namespace RE
{
	UserEvents* UserEvents::GetSingleton()
	{
		REL::Relocation<UserEvents**> singleton{ STATIC_OFFSET(UserEvents::Singleton) };
		return *singleton;
	}
}
