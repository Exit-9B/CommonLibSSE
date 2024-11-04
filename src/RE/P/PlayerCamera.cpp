#include "RE/P/PlayerCamera.h"

namespace RE
{
	PlayerCamera* PlayerCamera::GetSingleton()
	{
		REL::Relocation<PlayerCamera**> singleton{ STATIC_OFFSET(PlayerCamera::Singleton) };
		return *singleton;
	}

	void PlayerCamera::UpdateThirdPerson(bool a_weaponDrawn)
	{
		using func_t = decltype(&PlayerCamera::UpdateThirdPerson);
		REL::Relocation<func_t> func{ STATIC_OFFSET(PlayerCamera::UpdateThirdPerson) };
		return func(this, a_weaponDrawn);
	}
}
