#include "RE/S/State.h"

namespace RE
{
	namespace BSGraphics
	{
		State* State::GetSingleton()
		{
			REL::Relocation<State*> singleton{ Offset::BSGraphics::State::Singleton };
			return singleton.get();
		}
	}
}
