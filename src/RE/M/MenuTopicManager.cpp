#include "RE/M/MenuTopicManager.h"

namespace RE
{
	MenuTopicManager* MenuTopicManager::GetSingleton()
	{
		REL::Relocation<MenuTopicManager**> singleton{ STATIC_OFFSET(MenuTopicManager::Singleton) };
		return *singleton;
	}
}
