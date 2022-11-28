#include "RE/B/BGSCreatedObjectManager.h"

namespace RE
{
	BGSCreatedObjectManager* BGSCreatedObjectManager::GetSingleton()
	{
		REL::Relocation<BGSCreatedObjectManager**> singleton{ Offset::BGSCreatedObjectManager::Singleton };
		return *singleton;
	}

	EnchantmentItem* BGSCreatedObjectManager::CreateArmorEnchantment(BSTArray<Effect>& a_effects)
	{
		using func_t = decltype(&BGSCreatedObjectManager::CreateArmorEnchantment);
		REL::Relocation<func_t> func{ Offset::BGSCreatedObjectManager::CreateArmorEnchantment };
		return func(this, a_effects);
	}

	EnchantmentItem* BGSCreatedObjectManager::CreateWeaponEnchantment(BSTArray<Effect>& a_effects)
	{
		using func_t = decltype(&BGSCreatedObjectManager::CreateWeaponEnchantment);
		REL::Relocation<func_t> func{ Offset::BGSCreatedObjectManager::CreateWeaponEnchantment };
		return func(this, a_effects);
	}
}
