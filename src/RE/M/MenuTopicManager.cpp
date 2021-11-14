#include "RE/M/MenuTopicManager.h"

namespace RE
{
	MenuTopicManager* MenuTopicManager::GetSingleton()
	{
		REL::Relocation<MenuTopicManager**> singleton{ Offset::MenuTopicManager::Singleton };
		return *singleton;
	}
}
