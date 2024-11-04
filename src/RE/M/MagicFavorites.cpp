#include "RE/M/MagicFavorites.h"

namespace RE
{
	MagicFavorites* MagicFavorites::GetSingleton()
	{
		REL::Relocation<MagicFavorites**> singleton{ STATIC_OFFSET(MagicFavorites::Singleton) };
		return *singleton;
	}
}
