#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/N/NiTexture.h"

namespace RE
{
	class BSScaleformExternalTexture
	{
	public:
		BSScaleformExternalTexture() :
			gamebryoTexture{ nullptr },
			renderTarget(0),
			pad0C(0)
		{}

		~BSScaleformExternalTexture()
		{
			ReleaseTexture();
		}

		BSScaleformExternalTexture(const BSScaleformExternalTexture&) = delete;
		BSScaleformExternalTexture(BSScaleformExternalTexture&&) = delete;
		BSScaleformExternalTexture& operator=(const BSScaleformExternalTexture&) = delete;
		BSScaleformExternalTexture& operator=(BSScaleformExternalTexture&&) = delete;

		bool LoadPNG(const BSFixedString& a_path)
		{
			using func_t = decltype(&BSScaleformExternalTexture::LoadPNG);
			REL::Relocation<func_t> func{ Offset::BSScaleformExternalTexture::LoadPNG };
			return func(this, a_path);
		}

		void ReleaseTexture()
		{
			using func_t = decltype(&BSScaleformExternalTexture::ReleaseTexture);
			REL::Relocation<func_t> func{ Offset::BSScaleformExternalTexture::ReleaseTexture };
			return func(this);
		}

		bool SetTexture(NiTexture* a_texture)
		{
			using func_t = decltype(&BSScaleformExternalTexture::SetTexture);
			REL::Relocation<func_t> func{ Offset::BSScaleformExternalTexture::SetTexture };
			return func(this, a_texture);
		}

		// members
		NiPointer<NiTexture> gamebryoTexture;  // 00
		std::uint32_t        renderTarget;     // 08
		std::uint32_t        pad0C;            // 0C
		BSFixedString        filePath;         // 10
	};
	static_assert(sizeof(BSScaleformExternalTexture) == 0x18);
}
