#include "RE/P/PlayerControls.h"

#include "RE/A/ActivateHandler.h"
#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	PlayerControls::PlayerControls()
	{
		Ctor();
	}

	PlayerControls* PlayerControls::GetSingleton()
	{
		REL::Relocation<PlayerControls**> singleton{ STATIC_OFFSET(PlayerControls::Singleton) };
		return *singleton;
	}

	PlayerControls* PlayerControls::Ctor()
	{
		using func_t = decltype(&PlayerControls::Ctor);
		REL::Relocation<func_t> func{ STATIC_OFFSET(PlayerControls::Ctor) };
		return func(this);
	}
}
