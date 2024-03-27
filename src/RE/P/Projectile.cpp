#include "RE/P/Projectile.h"

namespace RE
{
	BSPointerHandle<Projectile> Projectile::Launch(const LaunchData& a_data)
	{
		using func_t = decltype(&Projectile::Launch);
		REL::Relocation<func_t> func{ Offset::Projectile::Launch };
		return func(a_data);
	}

	void Projectile::Kill()
	{
		using func_t = decltype(&Projectile::Kill);
		REL::Relocation<func_t> func{ Offset::Projectile::Kill };
		return func(this);
	}
}
