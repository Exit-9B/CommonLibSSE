#include "RE/S/ScriptEventSourceHolder.h"

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	ScriptEventSourceHolder* ScriptEventSourceHolder::GetSingleton()
	{
		using func_t = decltype(&ScriptEventSourceHolder::GetSingleton);
		REL::Relocation<func_t> func{ Offset::ScriptEventSourceHolder::GetSingleton };
		return func();
	}

	void ScriptEventSourceHolder::SendActivateEvent(const NiPointer<TESObjectREFR>& a_objectActivated, const NiPointer<TESObjectREFR>& a_actionRef)
	{
		using func_t = decltype(&ScriptEventSourceHolder::SendActivateEvent);
		REL::Relocation<func_t> func{ Offset::ScriptEventSourceHolder::SendActivateEvent };
		return func(this, a_objectActivated, a_actionRef);
	}

	void ScriptEventSourceHolder::SendOpenCloseEvent(const NiPointer<TESObjectREFR>& a_ref, const NiPointer<TESObjectREFR>& a_activeRef, bool a_isOpened)
	{
		using func_t = decltype(&ScriptEventSourceHolder::SendOpenCloseEvent);
		REL::Relocation<func_t> func{ Offset::ScriptEventSourceHolder::SendOpenCloseEvent };
		return func(this, a_ref, a_activeRef, a_isOpened);
	}
}
