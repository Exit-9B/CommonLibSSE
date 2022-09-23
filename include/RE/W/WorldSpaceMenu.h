#pragma once

#ifdef SKYRIMVR

#	include "RE/B/BSTEvent.h"
#	include "RE/I/IMenu.h"

namespace RE
{
	class HudModeChangeEvent;

	// menuDepth = 4
	// context = 22
	class WorldSpaceMenu :
		public IMenu,                            // 00
		public BSTEventSink<HudModeChangeEvent>  // 40
	{
	public:
		inline static constexpr auto RTTI = RTTI_WorldSpaceMenu;

		~WorldSpaceMenu() override;  // 00

		// add
		virtual void Unk_11();
		virtual void Unk_12();
		virtual void Unk_13();

		// members
		std::uint16_t unk48{ 0 };
		std::uint8_t  unk50{ 0 };
		std::uint8_t  unk51{ 0 };
		std::uint8_t  unk52{ 0 };
		std::uint8_t  pad53{ 0 };
		std::uint32_t pad54{ 0 };
	};
	static_assert(sizeof(WorldSpaceMenu) == 0x58);
}

#endif
