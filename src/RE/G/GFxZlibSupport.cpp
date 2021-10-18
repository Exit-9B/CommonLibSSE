#include "RE/G/GFxZlibSupport.h"

namespace RE
{
	GFile* GFxZlibSupport::CreateZlibFile(GFile* a_in)
	{
		using func_t = decltype(&GFxZlibSupport::CreateZlibFile);
		REL::Relocation<func_t> func{ REL::ID(82540) };
		return func(this, a_in);
	}

	void GFxZlibSupport::InflateWrapper(GFxStream* a_inStream, void* a_buffer, std::int32_t a_bufferBytes)
	{
		using func_t = decltype(&GFxZlibSupport::InflateWrapper);
		REL::Relocation<func_t> func{ REL::ID(82541) };
		return func(this, a_inStream, a_buffer, a_bufferBytes);
	}
}
