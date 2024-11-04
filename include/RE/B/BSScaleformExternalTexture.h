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

		~BSScaleformExternalTexture();

		BSScaleformExternalTexture(const BSScaleformExternalTexture&) = delete;
		BSScaleformExternalTexture(BSScaleformExternalTexture&&) = delete;
		BSScaleformExternalTexture& operator=(const BSScaleformExternalTexture&) = delete;
		BSScaleformExternalTexture& operator=(BSScaleformExternalTexture&&) = delete;

		bool LoadPNG(const BSFixedString& a_path);
		void ReleaseTexture();
		bool SetTexture(NiTexture* a_texture);

		// members
		NiPointer<NiTexture> gamebryoTexture;  // 00
		std::uint32_t        renderTarget;     // 08
		std::uint32_t        pad0C;            // 0C
		BSFixedString        filePath;         // 10
	};
	static_assert(sizeof(BSScaleformExternalTexture) == 0x18);
}
