#include "RE/I/Inventory.h"

namespace RE
{
	BSTEventSource<Inventory::Event>* Inventory::GetEventSource()
	{
		using func_t = decltype(&Inventory::GetEventSource);
		REL::Relocation<func_t> func{ STATIC_OFFSET(Inventory::GetEventSource) };
		return func();
	}
}
