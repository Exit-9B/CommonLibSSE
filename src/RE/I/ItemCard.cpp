#include "RE/I/ItemCard.h"

#include "RE/G/GFxMovieView.h"

namespace RE
{
	ItemCard::ItemCard(GFxMovieView* a_view)
	{
		view.reset(a_view);
		a_view->CreateObject(&obj);
		//infoText.reserve(2048);
	}

	void ItemCard::SetForm(const TESForm* a_form)
	{
		using func_t = decltype(&ItemCard::SetForm);
		REL::Relocation<func_t> func{ STATIC_OFFSET(ItemCard::SetForm) };
		return func(this, a_form);
	}

	void ItemCard::SetItem(const InventoryEntryData* a_item, bool a_ignoreStolen)
	{
		using func_t = decltype(&ItemCard::SetItem);
		REL::Relocation<func_t> func{ STATIC_OFFSET(ItemCard::SetItem) };
		return func(this, a_item, a_ignoreStolen);
	}
}
