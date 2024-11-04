#include "RE/B/BSScaleformExternalTexture.h"

namespace RE
{
	BSScaleformExternalTexture::~BSScaleformExternalTexture()
	{
		ReleaseTexture();
	}

	bool BSScaleformExternalTexture::LoadPNG(const BSFixedString& a_path)
	{
		using func_t = decltype(&BSScaleformExternalTexture::LoadPNG);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSScaleformExternalTexture::LoadPNG) };
		return func(this, a_path);
	}

	void BSScaleformExternalTexture::ReleaseTexture()
	{
		using func_t = decltype(&BSScaleformExternalTexture::ReleaseTexture);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSScaleformExternalTexture::ReleaseTexture) };
		return func(this);
	}

	bool BSScaleformExternalTexture::SetTexture(NiTexture* a_texture)
	{
		using func_t = decltype(&BSScaleformExternalTexture::SetTexture);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSScaleformExternalTexture::SetTexture) };
		return func(this, a_texture);
	}
}
