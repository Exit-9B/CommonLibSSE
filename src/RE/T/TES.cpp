#include "RE/T/TES.h"

namespace RE
{
	TES* TES::GetSingleton()
	{
		REL::Relocation<TES**> singleton{ STATIC_OFFSET(TES::Singleton) };
		return *singleton;
	}
}
