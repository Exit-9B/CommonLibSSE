#include "RE/B/BGSSaveLoadGame.h"

namespace RE
{
	BGSSaveLoadGame* BGSSaveLoadGame::GetSingleton()
	{
		REL::Relocation<BGSSaveLoadGame**> singleton{ STATIC_OFFSET(BGSSaveLoadGame::Singleton) };
		return *singleton;
	}

	void BGSSaveLoadGame::ClearForm(TESForm* a_form)
	{
		using func_t = decltype(&BGSSaveLoadGame::ClearForm);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BGSSaveLoadGame::ClearForm) };
		return func(this, a_form);
	}
}
