#include "RE/I/InventoryChanges.h"

namespace RE
{
	InventoryChanges::InventoryChanges() :
		InventoryChanges(nullptr)
	{}

	InventoryChanges::InventoryChanges(TESObjectREFR* a_ref)
	{
		Ctor(a_ref);
	}

	InventoryChanges::~InventoryChanges()
	{
		Dtor();
		stl::memzero(this);
	}

	void InventoryChanges::AddEntryData(InventoryEntryData* a_entry)
	{
		if (!entryList) {
			entryList = new std::remove_pointer_t<decltype(entryList)>;
		}

		entryList->push_front(a_entry);
		changed = true;
	}

#ifndef SKYRIMVR
	TESObjectARMO* InventoryChanges::GetArmorInSlot(std::int32_t a_slot)
	{
		using func_t = decltype(&InventoryChanges::GetArmorInSlot);
		REL::Relocation<func_t> func{ STATIC_OFFSET(InventoryChanges::GetArmorInSlot) };
		return func(this, a_slot);
	}
#endif

	std::uint16_t InventoryChanges::GetNextUniqueID()
	{
		using func_t = decltype(&InventoryChanges::GetNextUniqueID);
		REL::Relocation<func_t> func{ STATIC_OFFSET(InventoryChanges::GetNextUniqueID) };
		return func(this);
	}

	RE::ExtraDataList* InventoryChanges::EnchantObject(RE::TESBoundObject* a_obj, RE::ExtraDataList* a_extraList, RE::EnchantmentItem* a_enchantment, uint16_t a_charge)
	{
		using func_t = decltype(&InventoryChanges::EnchantObject);
		REL::Relocation<func_t> func{ STATIC_OFFSET(InventoryChanges::EnchantObject) };
		return func(this, a_obj, a_extraList, a_enchantment, a_charge);
	}

	void InventoryChanges::SendContainerChangedEvent(ExtraDataList* a_itemExtraList, TESObjectREFR* a_fromRefr, TESForm* a_item, std::int32_t a_count)
	{
		using func_t = decltype(&InventoryChanges::SendContainerChangedEvent);
		REL::Relocation<func_t> func{ STATIC_OFFSET(InventoryChanges::SendContainerChangedEvent) };
		return func(this, a_itemExtraList, a_fromRefr, a_item, a_count);
	}

	void InventoryChanges::SetUniqueID(ExtraDataList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm)
	{
		using func_t = decltype(&InventoryChanges::SetUniqueID);
		REL::Relocation<func_t> func{ STATIC_OFFSET(InventoryChanges::SetUniqueID) };
		return func(this, a_itemList, a_oldForm, a_newForm);
	}

	void InventoryChanges::InitFromContainerExtra()
	{
		using func_t = decltype(&InventoryChanges::InitFromContainerExtra);
		REL::Relocation<func_t> func{ STATIC_OFFSET(InventoryChanges::InitFromContainerExtra) };
		return func(this);
	}

	void InventoryChanges::InitLeveledItems()
	{
		using func_t = decltype(&InventoryChanges::InitLeveledItems);
		REL::Relocation<func_t> func{ STATIC_OFFSET(InventoryChanges::InitLeveledItems) };
		return func(this);
	}

	void InventoryChanges::InitScripts()
	{
		using func_t = decltype(&InventoryChanges::InitScripts);
		REL::Relocation<func_t> func{ STATIC_OFFSET(InventoryChanges::InitScripts) };
		return func(this);
	}

	InventoryChanges* InventoryChanges::Ctor(TESObjectREFR* a_ref)
	{
		using func_t = decltype(&InventoryChanges::Ctor);
		REL::Relocation<func_t> func{ STATIC_OFFSET(InventoryChanges::Ctor) };
		return func(this, a_ref);
	}

	void InventoryChanges::Dtor()
	{
		using func_t = decltype(&InventoryChanges::Dtor);
		REL::Relocation<func_t> func{ STATIC_OFFSET(InventoryChanges::Dtor) };
		return func(this);
	}
}
