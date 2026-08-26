#pragma once

#include "RE/I/IDEvent.h"

namespace RE
{
	class AmiiboEvent : public IDEvent
	{
	public:
#if 0
		inline static constexpr auto RTTI = RTTI_AmiiboEvent;
#endif

		// members
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
		std::uint64_t unk38;  // 38
	};
	static_assert(sizeof(AmiiboEvent) == 0x40);
}
