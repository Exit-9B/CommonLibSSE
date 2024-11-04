#include "RE/I/Inventory3DManager.h"

namespace RE
{
	Inventory3DManager* Inventory3DManager::GetSingleton()
	{
		REL::Relocation<Inventory3DManager**> singleton{ STATIC_OFFSET(Inventory3DManager::Singleton) };
		return *singleton;
	}

	void Inventory3DManager::Begin3D(std::uint32_t a_arg1)
	{
		using func_t = decltype(&Inventory3DManager::Begin3D);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Inventory3DManager::Begin3D) };
		return func(this, a_arg1);
	}

	void Inventory3DManager::End3D()
	{
		using func_t = decltype(&Inventory3DManager::End3D);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Inventory3DManager::End3D) };
		return func(this);
	}

	void Inventory3DManager::UpdateItem3D(InventoryEntryData* a_objDesc)
	{
		using func_t = void (Inventory3DManager::*)(InventoryEntryData*);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Inventory3DManager::UpdateItem3D) };
		return func(this, a_objDesc);
	}

	void Inventory3DManager::UpdateItem3D(TESForm* a_form, ExtraDataList* a_extraList)
	{
		using func_t = void (Inventory3DManager::*)(TESForm*, ExtraDataList*);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Inventory3DManager::UpdateObject3D) };
		return func(this, a_form, a_extraList);
	}

	void Inventory3DManager::Clear3D()
	{
		using func_t = decltype(&Inventory3DManager::Clear3D);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Inventory3DManager::Clear3D) };
		return func(this);
	}

	std::uint32_t Inventory3DManager::Render()
	{
		using func_t = decltype(&Inventory3DManager::Render);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Inventory3DManager::Render) };
		return func(this);
	}

	void Inventory3DManager::SetMouseRotation(bool a_active)
	{
		REL::Relocation<bool*> bMouseRotation{ STATIC_OFFSET(Inventory3DManager::bMouseRotation) };
		*bMouseRotation = a_active;
	}
}
