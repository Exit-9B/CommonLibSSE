#include "RE/B/BSScaleformImageLoader.h"

namespace RE
{
	bool BSScaleformImageLoader::AddTexture(BSScaleformExternalTexture& a_texture)
	{
		using func_t = decltype(&BSScaleformImageLoader::AddTexture);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSScaleformImageLoader::AddTexture) };
		return func(this, a_texture);
	}

	void BSScaleformImageLoader::RemoveTexture(BSScaleformExternalTexture& a_texture)
	{
		using func_t = decltype(&BSScaleformImageLoader::RemoveTexture);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSScaleformImageLoader::RemoveTexture) };
		return func(this, a_texture);
	}
}
