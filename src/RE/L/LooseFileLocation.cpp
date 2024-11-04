#include "RE/L/LooseFileLocation.h"

namespace RE::BSResource
{
	LooseFileLocation* LooseFileLocation::Create(const char* a_prefix)
	{
		return Create(a_prefix, 512, true);
	}

	LooseFileLocation* LooseFileLocation::Create(const char* a_prefix, std::uint32_t a_minimumAsyncPacketSize, bool a_asyncSupported)
	{
		auto memory = malloc<LooseFileLocation>();
		std::memset(memory, 0, sizeof(LooseFileLocation));

		REL::Relocation<std::uintptr_t> vtbl{ STATIC_OFFSET(BSResource::LooseFileLocation::Vtbl) };
		((std::uintptr_t*)memory)[0] = vtbl.address();

		memory->prefix = a_prefix;
		memory->minimumAsyncPacketSize = a_minimumAsyncPacketSize;
		memory->asyncSupported = a_asyncSupported;

		return memory;
	}
}
