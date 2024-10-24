#pragma once

namespace RE
{
	namespace BSResource
	{
		class Location;

		inline void RegisterGlobalPath(const char* a_path)
		{
			using func_t = decltype(&RegisterGlobalPath);
			REL::Relocation<func_t> func{ Offset::BSResource::RegisterGlobalPath };
			return func(a_path);
		}

		inline void RegisterLocation(Location* a_location, std::uint32_t a_priority)
		{
			using func_t = decltype(&RegisterLocation);
			REL::Relocation<func_t> func{ Offset::BSResource::RegisterLocation };
			return func(a_location, a_priority);
		}
	}
}
