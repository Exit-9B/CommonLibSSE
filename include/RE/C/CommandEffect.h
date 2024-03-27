#pragma once

#include "RE/A/ActiveEffect.h"
#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class CommandEffect : public ActiveEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_CommandEffect;

		~CommandEffect() override;  // 13

		// members
		ActorHandle   commandedActor;  // 90
		std::uint32_t pad94;           // 94
	};
	static_assert(sizeof(CommandEffect) == 0x98);
}
