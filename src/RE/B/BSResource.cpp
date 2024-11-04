#include "RE/B/BSResource.h"

namespace RE::BSResource
{
	void RegisterGlobalPath(const char* a_path)
	{
		using func_t = decltype(&RegisterGlobalPath);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSResource::RegisterGlobalPath) };
		return func(a_path);
	}

	void RegisterLocation(Location* a_location, std::uint32_t a_priority)
	{
		using func_t = decltype(&RegisterLocation);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSResource::RegisterLocation) };
		return func(a_location, a_priority);
	}
}
