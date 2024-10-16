#pragma once

namespace RE
{
	class Actor;
	template <class T>
	class NiPointer;
	class Setting;
	class TESObjectREFR;
	class TESForm;
	class InventoryEntryData;

	void     CreateRefHandle(RefHandle& a_handleOut, TESObjectREFR* a_refrTo);
	float    GetArmorFinalRating(InventoryEntryData* a_entryData, float a_armorPerks, float a_skillMultiplier);
	Setting* GetINISetting(const char* a_name);
	bool     LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut);
	bool     LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut);
	void     PlaySound(const char* a_editorID);
}
