#pragma once

#include "RE/I/IDEvent.h"

namespace RE
{
#if HAS_SKYRIMSE(1, 7, 99)
	class SixaxisEvent : public IDEvent
	{
	public:
#	if 0
		inline static constexpr auto RTTI = RTTI_SixaxisEvent;
#	endif

		// members
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
		std::uint64_t unk38;  // 38
		std::uint32_t unk40;  // 40
		std::uint32_t unk44;  // 44
		std::uint32_t unk48;  // 48
		std::uint32_t unk4C;  // 4C
		std::uint64_t unk50;  // 50
		std::uint32_t unk58;  // 58
		std::uint32_t unk5C;  // 5C
		std::uint64_t unk60;  // 60
		std::uint64_t unk68;  // 68
		std::uint32_t unk70;  // 70
		std::uint32_t unk74;  // 74
		std::uint32_t unk78;  // 78
		std::uint32_t unk7C;  // 7C
		std::uint64_t unk80;  // 80
		std::uint64_t unk88;  // 88
	};
	static_assert(sizeof(SixaxisEvent) == 0x90);
#endif
}
