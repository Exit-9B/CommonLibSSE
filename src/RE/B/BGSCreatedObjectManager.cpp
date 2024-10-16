#include "RE/B/BGSCreatedObjectManager.h"

namespace RE
{
	BGSCreatedObjectManager* BGSCreatedObjectManager::GetSingleton()
	{
		REL::Relocation<BGSCreatedObjectManager**> singleton{ Offset::BGSCreatedObjectManager::Singleton };
		return *singleton;
	}

	EnchantmentItem* BGSCreatedObjectManager::AddArmorEnchantment(BSTArray<Effect>& a_effects)
	{
		using func_t = decltype(&BGSCreatedObjectManager::AddArmorEnchantment);
		REL::Relocation<func_t> func{ Offset::BGSCreatedObjectManager::AddArmorEnchantment };
		return func(this, a_effects);
	}

	EnchantmentItem* BGSCreatedObjectManager::AddWeaponEnchantment(BSTArray<Effect>& a_effects)
	{
		using func_t = decltype(&BGSCreatedObjectManager::AddWeaponEnchantment);
		REL::Relocation<func_t> func{ Offset::BGSCreatedObjectManager::AddWeaponEnchantment };
		return func(this, a_effects);
	}

	void BGSCreatedObjectManager::DestroyEnchantment(EnchantmentItem* a_enchantment, bool a_isWeapon)
	{
		using func_t = decltype(&BGSCreatedObjectManager::DestroyEnchantment);
		REL::Relocation<func_t> func{ Offset::BGSCreatedObjectManager::DestroyEnchantment };
		return func(this, a_enchantment, a_isWeapon);
	}
}
