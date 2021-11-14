#include "RE/A/ArmorRatingVisitorBase.h"

namespace RE
{
	bool ArmorRatingVisitorBase::Visit(InventoryEntryData* a_entryData)
	{
		using func_t = decltype(&ArmorRatingVisitorBase::Visit);
		REL::Relocation<func_t> func{ Offset::ArmorRatingVisitorBase::Visit };
		return func(this, a_entryData);
	}
}
