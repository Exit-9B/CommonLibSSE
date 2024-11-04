#include "RE/S/State.h"

namespace RE::BSGraphics
{
	State* State::GetSingleton()
	{
		REL::Relocation<State*> singleton{ STATIC_OFFSET(BSGraphics::State::Singleton) };
		return singleton.get();
	}
}
