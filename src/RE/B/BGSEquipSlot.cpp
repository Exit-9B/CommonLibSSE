#include "RE/B/BGSEquipSlot.h"
#include "RE/B/BGSDefaultObjectManager.h"

namespace RE
{
	BGSEquipSlot* BGSEquipSlot::GetLeftHandSlot()
	{
		const auto defaultObjectManager = BGSDefaultObjectManager::GetSingleton();
		return defaultObjectManager ? defaultObjectManager->GetObject<BGSEquipSlot>(DEFAULT_OBJECTS::kLeftHandEquip) : nullptr;
	}

	BGSEquipSlot* BGSEquipSlot::GetRightHandSlot()
	{
		const auto defaultObjectManager = BGSDefaultObjectManager::GetSingleton();
		return defaultObjectManager ? defaultObjectManager->GetObject<BGSEquipSlot>(DEFAULT_OBJECTS::kRightHandEquip) : nullptr;
	}

	BGSEquipSlot* BGSEquipSlot::GetVoiceSlot()
	{
		const auto defaultObjectManager = BGSDefaultObjectManager::GetSingleton();
		return defaultObjectManager ? defaultObjectManager->GetObject<BGSEquipSlot>(DEFAULT_OBJECTS::kVoiceEquip) : nullptr;
	}
}
