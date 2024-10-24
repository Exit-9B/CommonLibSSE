#include "RE/M/Misc.h"

#include "RE/I/INIPrefSettingCollection.h"
#include "RE/I/INISettingCollection.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/S/Setting.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	bool LookupReferenceByHandle_ActorImpl(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut)
	{
		using func_t = decltype(&LookupReferenceByHandle_ActorImpl);
		REL::Relocation<func_t> func{ Offset::LookupReferenceByHandle };
		return func(a_handle, a_refrOut);
	}

	bool LookupReferenceByHandle_RefrImpl(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		using func_t = decltype(&LookupReferenceByHandle_RefrImpl);
		REL::Relocation<func_t> func{ Offset::LookupReferenceByHandle };
		return func(a_handle, a_refrOut);
	}

	void CreateRefHandle(RefHandle& a_handleOut, TESObjectREFR* a_refTo)
	{
		using func_t = decltype(&CreateRefHandle);
		REL::Relocation<func_t> func{ Offset::CreateRefHandle };
		return func(a_handleOut, a_refTo);
	}

	Setting* GetINISetting(const char* a_name)
	{
		Setting* setting = nullptr;

		auto iniPrefs = INIPrefSettingCollection::GetSingleton();
		setting = iniPrefs ? iniPrefs->GetSetting(a_name) : nullptr;
		if (!setting) {
			auto ini = INISettingCollection::GetSingleton();
			setting = ini ? ini->GetSetting(a_name) : nullptr;
		}
		return setting;
	}

	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut)
	{
		return LookupReferenceByHandle_ActorImpl(a_handle, a_refrOut);
	}

	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		return LookupReferenceByHandle_RefrImpl(a_handle, a_refrOut);
	}

	void PlaySound(const char* a_editorID)
	{
		using func_t = decltype(&PlaySound);
		REL::Relocation<func_t> func{ Offset::PlaySound };
		return func(a_editorID);
	}

	float GetArmorFinalRating(RE::InventoryEntryData* a_armorEntryData, float a_armorPerks, float a_skillMultiplier)
	{
		using func_t = decltype(&GetArmorFinalRating);
		REL::Relocation<func_t> func{ Offset::GetArmorFinalRating };
		return func(a_armorEntryData, a_armorPerks, a_skillMultiplier);
	}
}
