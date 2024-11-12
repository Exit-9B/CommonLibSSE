#include "RE/T/TESForm.h"

#include "RE/B/BGSDefaultObjectManager.h"
#include "RE/I/IObjectHandlePolicy.h"
#include "RE/I/InventoryEntryData.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESGlobal.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESNPC.h"
#include "RE/T/TESObjectREFR.h"
#include "RE/T/TESWeightForm.h"
#include "RE/V/VirtualMachine.h"

namespace RE
{
	std::int32_t TESForm::GetGoldValue() const
	{
		const auto obj = As<TESBoundObject>();
		if (obj) {
			const InventoryEntryData entry{ const_cast<TESBoundObject*>(obj), 1 };
			return entry.GetValue();
		} else {
			return -1;
		}
	}

	const char* TESForm::GetName() const
	{
		const auto fullName = As<TESFullName>();
		if (fullName) {
			const auto str = fullName->GetFullName();
			return str ? str : "";
		} else {
			return "";
		}
	}

	float TESForm::GetWeight() const
	{
		const auto survival = []() {
			const auto dobj = BGSDefaultObjectManager::GetSingleton();
			const auto survival = dobj ? dobj->GetObject<TESGlobal>(DEFAULT_OBJECT::kSurvivalModeEnabled) : nullptr;
			return survival ? survival->value == 1.0F : false;
		};

		const auto ref = As<TESObjectREFR>();
		const auto baseObj = ref ? ref->GetBaseObject() : nullptr;
		const auto form = baseObj ? baseObj : this;
		if (!survival() && (form->IsAmmo() || form->IsLockpick())) {
			return 0.0F;
		} else if (const auto weightForm = form->As<TESWeightForm>(); weightForm) {
			return weightForm->weight;
		} else if (form->Is(FormType::NPC)) {
			const auto npc = static_cast<const TESNPC*>(form);
			return npc->weight;
		} else {
			return -1.0F;
		}
	}

	bool TESForm::HasVMAD() const
	{
		const auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
		if (!vm) {
			return false;
		}

		const auto policy = vm->GetObjectHandlePolicy();
		if (!policy) {
			return false;
		}

		const auto handle = policy->GetHandleForObject(GetFormType(), this);
		return handle != policy->EmptyHandle();
	}

	bool TESForm::HasWorldModel() const noexcept
	{
		return As<TESModel>() != nullptr;
	}

	void TESForm::AddCompileIndex(FormID& a_id, TESFile* a_file)
	{
		using func_t = decltype(&TESForm::AddCompileIndex);
		REL::Relocation<func_t> func{ STATIC_OFFSET(TESForm::AddCompileIndex) };
		return func(a_id, a_file);
	}

	auto TESForm::GetAllForms()
		-> std::pair<
			BSTHashMap<FormID, TESForm*>*,
			std::reference_wrapper<BSReadWriteLock>>
	{
		REL::Relocation<BSTHashMap<FormID, TESForm*>**> allForms{ STATIC_OFFSET(TESForm::AllForms) };
		REL::Relocation<BSReadWriteLock*>               allFormsMapLock{ STATIC_OFFSET(TESForm::AllFormsMapLock) };
		return { *allForms, std::ref(*allFormsMapLock) };
	}

	auto TESForm::GetAllFormsByEditorID()
		-> std::pair<
			BSTHashMap<BSFixedString, TESForm*>*,
			std::reference_wrapper<BSReadWriteLock>>
	{
		REL::Relocation<BSTHashMap<BSFixedString, TESForm*>**> allFormsByEditorID{ STATIC_OFFSET(TESForm::AllFormsByEditorID) };
		REL::Relocation<BSReadWriteLock*>                      allFormsEditorIDMapLock{ STATIC_OFFSET(TESForm::AllFormsEditorIDMapLock) };
		return { *allFormsByEditorID, std::ref(*allFormsEditorIDMapLock) };
	}

	TESForm* TESForm::LookupByID(FormID a_formID)
	{
		const auto& [map, lock] = GetAllForms();
		const BSReadWriteLock l{ lock };
		if (map) {
			const auto it = map->find(a_formID);
			return it != map->end() ? it->second : nullptr;
		} else {
			return nullptr;
		}
	}

	TESForm* TESForm::LookupByEditorID(const std::string_view& a_editorID)
	{
		const auto& [map, lock] = GetAllFormsByEditorID();
		const BSReadWriteLock l{ lock };
		if (map) {
			const auto it = map->find(a_editorID);
			return it != map->end() ? it->second : nullptr;
		} else {
			return nullptr;
		}
	}
}
