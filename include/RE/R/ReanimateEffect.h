#pragma once

#include "RE/C/CommandEffect.h"

namespace RE
{
	class ReanimateEffect : public CommandEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_ReanimateEffect;

		~ReanimateEffect() override;  // 13

		// members
		std::uint64_t unk98;  // 98
	};
	static_assert(sizeof(ReanimateEffect) == 0xA0);
}
