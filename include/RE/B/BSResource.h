#pragma once

namespace RE
{
	namespace BSResource
	{
		class Location;

		void RegisterGlobalPath(const char* a_path);
		void RegisterLocation(Location* a_location, std::uint32_t a_priority);
	}
}
