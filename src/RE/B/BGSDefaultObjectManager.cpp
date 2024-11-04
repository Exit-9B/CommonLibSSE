#include "RE/B/BGSDefaultObjectManager.h"

namespace RE
{
	BGSDefaultObjectManager* BGSDefaultObjectManager::GetSingleton()
	{
		using func_t = decltype(&BGSDefaultObjectManager::GetSingleton);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BGSDefaultObjectManager::GetSingleton) };
		return func();
	}
}
