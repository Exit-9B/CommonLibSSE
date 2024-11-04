#include "RE/B/BGSSaveLoadGame.h"

namespace RE
{
	BGSSaveLoadGame* BGSSaveLoadGame::GetSingleton()
	{
		REL::Relocation<BGSSaveLoadGame**> singleton{ STATIC_OFFSET(BGSSaveLoadGame::Singleton) };
		return *singleton;
	}
}
