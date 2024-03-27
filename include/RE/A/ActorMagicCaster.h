#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/M/MagicCaster.h"
#include "RE/S/SimpleAnimationGraphManagerHolder.h"

namespace RE
{
	class bhkWorld;
	class BSLight;
	class NiNode;
	class ReferenceEffectController;
	class TESRace;

	class ActorMagicCaster :
		public MagicCaster,                         // 00
		public SimpleAnimationGraphManagerHolder,   // 48
		public BSTEventSink<BSAnimationGraphEvent>  // 60
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActorMagicCaster;

		virtual ~ActorMagicCaster();  // 00

		// add
		virtual void Update(float a_timeDelta);  // 1D

		// members
		std::uint64_t              unk68;             // 68
		std::uint64_t              unk70;             // 70
		NiNode*                    fireNode;          // 78
		std::uint64_t              unk80;             // 80
		std::uint64_t              unk88;             // 88
		TESRace*                   casterRace;        // 90
		bhkWorld*                  havokWorld;        // 98
		std::uint64_t              unkA0;             // A0
		std::uint64_t              unkA8;             // A8
		std::uint64_t              unkB0;             // B0
		Actor*                     owner;             // B8
		NiNode*                    effectNode;        // C0
		BSLight*                   effectLight;       // C8
		std::uint64_t              unkD0;             // D0
		std::uint64_t              unkD8;             // D8
		std::uint64_t              unkE0;             // E0
		ReferenceEffectController* effectController;  // E8
		std::uint32_t              unkF0;             // F0
		MagicSystem::CastingSource actorCasterType;   // F4
		std::uint32_t              unkF8;             // F8
	};
	static_assert(sizeof(ActorMagicCaster) == 0x100);
}
