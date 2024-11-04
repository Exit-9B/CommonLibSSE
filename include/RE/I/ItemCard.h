#pragma once

#include "RE/B/BSString.h"
#include "RE/G/GFxValue.h"
#include "RE/G/GPtr.h"

namespace RE
{
	class GFxMovieView;
	class InventoryEntryData;
	class TESForm;

	struct ItemCard
	{
	public:
		ItemCard(GFxMovieView* a_view);

		void SetForm(const TESForm* a_form);
		void SetItem(const InventoryEntryData* a_item, bool a_ignoreStolen);

		TES_HEAP_REDEFINE_NEW();

		// members
		GFxValue           obj;       // 00 - kObject
		BSString           infoText;  // 18
		void*              unk28;     // 28
		std::uint32_t      unk30;     // 30
		std::uint32_t      pad34;     // 34
		GPtr<GFxMovieView> view;      // 38
	};
	static_assert(sizeof(ItemCard) == 0x40);
}
