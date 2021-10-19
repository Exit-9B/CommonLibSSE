#pragma once

#include "RE/G/GFxResource.h"
#include "RE/G/GPoint.h"

namespace RE
{
	class GFxCharacter;

	class GFxCharacterDef : public GFxResource
	{
	public:
		// add
		virtual void          Unk_04();                                                 // 04
		virtual bool          HitTest(const GPointF& a_pt, bool a_arg2, void* a_arg3);  // 05 - { return false; }
		virtual void          Unk_06();                                                 // 06
		virtual void          Unk_07();                                                 // 07
		virtual std::uint32_t GetVersion();                                             // 08
		virtual GFxCharacter* CreateASCharacter();                                      // 09

		// members
		std::uint32_t pad18;  // 18
		std::uint32_t pad1C;  // 1C
	};
	static_assert(sizeof(GFxCharacterDef) == 0x20);
}
