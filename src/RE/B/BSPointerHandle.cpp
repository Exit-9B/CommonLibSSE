#include "RE/B/BSPointerHandle.h"

#include "RE/A/Actor.h"
#include "RE/P/Projectile.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	template <class T, class Manager>
	[[nodiscard]] BSPointerHandle<T> BSPointerHandleManagerInterface<T, Manager>::GetHandle(T* a_ptr)
	{
		using func_t = decltype(&BSPointerHandleManagerInterface<T, Manager>::GetHandle);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSPointerHandleManagerInterface::GetHandle) };
		return func(a_ptr);
	}

	template <class T, class Manager>
	bool BSPointerHandleManagerInterface<T, Manager>::GetSmartPointer(const BSPointerHandle<T>& a_handle, NiPointer<T>& a_smartPointerOut)
	{
		using func_t = decltype(&BSPointerHandleManagerInterface<T, Manager>::GetSmartPointer);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSPointerHandleManagerInterface::GetSmartPointer) };
		return func(a_handle, a_smartPointerOut);
	}

	template class BSUntypedPointerHandle<>;
	static_assert(sizeof(BSUntypedPointerHandle<>) == 0x4);

	template class BSPointerHandle<Actor>;
	static_assert(sizeof(BSPointerHandle<Actor>) == 0x4);

	template class BSPointerHandle<Projectile>;
	static_assert(sizeof(BSPointerHandle<Projectile>) == 0x4);

	template class BSPointerHandle<TESObjectREFR>;
	static_assert(sizeof(BSPointerHandle<TESObjectREFR>) == 0x4);

	template class BSPointerHandleManagerInterface<Actor>;
	static_assert(std::is_empty_v<BSPointerHandleManagerInterface<Actor>>);

	template class BSPointerHandleManagerInterface<Projectile>;
	static_assert(std::is_empty_v<BSPointerHandleManagerInterface<Projectile>>);

	template class BSPointerHandleManagerInterface<TESObjectREFR>;
	static_assert(std::is_empty_v<BSPointerHandleManagerInterface<TESObjectREFR>>);
}
