#include "RE/B/BGSFootstepManager.h"

namespace RE
{
	BGSFootstepManager* BGSFootstepManager::GetSingleton()
	{
		REL::Relocation<BGSFootstepManager**> singleton{ STATIC_OFFSET(BGSFootstepManager::Singleton) };
		return *singleton;
	}
}
