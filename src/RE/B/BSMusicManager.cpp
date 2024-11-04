#include "RE/B/BSMusicManager.h"

namespace RE
{
	BSMusicManager* BSMusicManager::GetSingleton()
	{
		REL::Relocation<BSMusicManager**> singleton{ STATIC_OFFSET(BSMusicManager::Singleton) };
		return *singleton;
	}
}
