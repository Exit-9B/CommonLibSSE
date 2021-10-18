#include "RE/G/GFxLoader.h"
#include "RE/G/GFxStateBagImpl.h"

namespace RE
{
	GFxLoader::GFxLoader(const LoaderConfig& a_config)
	{
		using func_t = GFxLoader*(GFxLoader*, const LoaderConfig&);
		REL::Relocation<func_t> func{ REL::ID(80610) };
		func(this, a_config);
	}

	GFxStateBag* GFxLoader::GetStateBagImpl() const
	{
		if (impl) {
			return impl->stateBagImpl;
		} else {
			return nullptr;
		}
	}

	bool GFxLoader::CheckTagLoader(std::int32_t a_tagType) const
	{
		using func_t = decltype(&GFxLoader::CheckTagLoader);
		static REL::Relocation<func_t> func{ REL::ID(80617) };
		return func(this, a_tagType);
	}

	GFxMovieDef* GFxLoader::CreateMovie(const char* a_filename, LoadConstants a_loadConstants, UPInt a_memoryArena)
	{
		using func_t = decltype(&GFxLoader::CreateMovie);
		REL::Relocation<func_t> func{ Offset::GFxLoader::CreateMovie };
		return func(this, a_filename, a_loadConstants, a_memoryArena);
	}

	GFxLoaderImpl* GFxLoader::GetLoaderImpl() const
	{
		return impl.get();
	}
}
