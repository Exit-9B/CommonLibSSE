#include "RE/B/BSMusicManager.h"

namespace RE
{
	BSMusicManager* BSMusicManager::GetSingleton()
	{
		REL::Relocation<BSMusicManager**> singleton{ Offset::BSMusicManager::Singleton };
		return *singleton;
	}
}
