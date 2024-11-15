#pragma once

#include "RE/B/BSSimpleList.h"
#include "RE/F/FormTypes.h"
#include "RE/I/InventoryEntryData.h"
#include "RE/M/MemoryManager.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESContainer.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	class ExtraDataList;
	class InventoryEntryData;

	class InventoryChanges
	{
	public:
		enum class VisitResult : std::uint32_t
		{
			kStop = 0,
			kContinue = 1,
		};

		class IItemChangeVisitor
		{
		public:
			inline static constexpr auto RTTI = RTTI_InventoryChanges__IItemChangeVisitor;

			virtual ~IItemChangeVisitor();  // 00

			// add
			virtual VisitResult Visit(InventoryEntryData* a_entryData) = 0;  // 01
			virtual void        Unk_02(RE::FormType a_formType);             // 02 - { return 1; }
			virtual void        Unk_03(void);                                // 03
		};
		static_assert(sizeof(IItemChangeVisitor) == 0x8);

		InventoryChanges();
		explicit InventoryChanges(TESObjectREFR* a_ref);
		~InventoryChanges();

		void AddEntryData(InventoryEntryData* a_entry);
#ifndef SKYRIMVR
		TESObjectARMO* GetArmorInSlot(std::int32_t a_slot);
#endif
		std::uint16_t      GetNextUniqueID();
		RE::ExtraDataList* EnchantObject(RE::TESBoundObject* a_obj, RE::ExtraDataList* a_extraList, RE::EnchantmentItem* a_enchantment, uint16_t a_charge);
		void               InitFromContainerExtra();
		void               InitLeveledItems();
		void               InitScripts();
		void               SendContainerChangedEvent(ExtraDataList* a_itemExtraList, TESObjectREFR* a_fromRefr, TESForm* a_item, std::int32_t a_count);
		void               SetUniqueID(ExtraDataList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm);

		[[nodiscard]] std::int32_t GetCount(const TESBoundObject* a_object, std::predicate<const InventoryEntryData*> auto a_itemFilter) const
		{
			const auto   container = owner ? owner->GetContainer() : nullptr;
			std::int32_t count = container ? std::abs(container->GetObjectCount(a_object)) : 0;

			if (entryList) {
				const InventoryEntryData* objEntry = nullptr;
				for (const auto* const entry : *entryList) {
					if (entry && entry->object == a_object) {
						objEntry = entry;
						break;
					}
				}

				if (objEntry) {
					if (a_itemFilter(objEntry)) {
						count += objEntry->countDelta;
					}
				}
			}

			return count;
		}

		TES_HEAP_REDEFINE_NEW();

		// members
		BSSimpleList<InventoryEntryData*>* entryList{ nullptr };  // 00
		TESObjectREFR*                     owner{ nullptr };      // 08
		float                              totalWeight{ 0.0F };   // 10
		float                              armorWeight{ 0.0F };   // 14
		bool                               changed{ false };      // 18
		std::uint8_t                       unk19{ 0 };            // 19
		std::uint8_t                       unk1A{ 0 };            // 1A
		std::uint8_t                       unk1B{ 0 };            // 1B
		std::uint32_t                      unk1C{ 0 };            // 1C

	private:
		InventoryChanges* Ctor(TESObjectREFR* a_ref);
		void              Dtor();
	};
	static_assert(sizeof(InventoryChanges) == 0x20);
}
