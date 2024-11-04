#include "RE/B/BSTCreateFactoryManager.h"

namespace RE
{
	MessageDataFactoryManager* MessageDataFactoryManager::GetSingleton()
	{
		using func_t = decltype(&MessageDataFactoryManager::GetSingleton);
		REL::Relocation<func_t> func{ STATIC_OFFSET(MessageDataFactoryManager::GetSingleton) };
		return func();
	}
}
