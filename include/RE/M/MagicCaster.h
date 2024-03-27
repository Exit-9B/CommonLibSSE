#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/M/MagicTarget.h"

namespace RE
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;
	class MagicItem;

	class MagicCaster
	{
	public:
		inline static constexpr auto RTTI = RTTI_MagicCaster;

		enum class State
		{
			kNone = 0
		};

		class PostCreationCallback : public MagicTarget::IPostCreationModification
		{
		public:
			inline static constexpr auto RTTI = RTTI_MagicCaster__PostCreationCallback;

			~PostCreationCallback() override;  // 00

			// override (IPostCreationModification)
			void ModifyActiveEffect(ActiveEffect* a_effect) override;  // 01

			// members
			std::uint64_t unk08[8];
		};
		static_assert(sizeof(PostCreationCallback) == 0x48);

		virtual ~MagicCaster();  // 00

		// add
		virtual void                       CastSpellImmediate(MagicItem* a_spell, bool a_arg2, TESObjectREFR* a_target, float a_power, bool a_arg6, float a_magnitudeOverride = 0.0f, Actor* a_owner = nullptr);  // 01
		virtual void                       Unk_02(void);                                                                                                                                                          // 02
		virtual void                       Unk_03(void);                                                                                                                                                          // 03
		virtual void                       Unk_04(void);                                                                                                                                                          // 04
		virtual void                       Unk_05(void);                                                                                                                                                          // 05
		virtual void                       Unk_06(void);                                                                                                                                                          // 06
		virtual void                       Unk_07(void);                                                                                                                                                          // 07 - { return; }
		virtual void                       Unk_08(void);                                                                                                                                                          // 08 - { return; }
		virtual void                       SpellCast(bool a_arg1, std::uint32_t a_arg2, MagicItem* a_arg3);                                                                                                       // 09 - { return; }
		virtual bool                       CheckCast(MagicItem* a_spell, bool a_arg2, float* a_arg3, MagicSystem::CannotCastReason* a_reasonOut, bool a_arg5);                                                    // 0A
		virtual TESObjectREFR*             GetCasterStatsObject() const;                                                                                                                                          // 0B - { return 0; }
		virtual Actor*                     GetCasterAsActor() const;                                                                                                                                              // 0C - { return 0; }
		virtual TESObjectREFR*             GetCasterObjectReference(Actor** a_casterOut) const;                                                                                                                   // 0D
		virtual NiNode*                    GetMagicNode();                                                                                                                                                        // 0E - { return 0; }
		virtual void                       ClearMagicNode();                                                                                                                                                      // 0F - { return; }
		virtual void                       SetCurrentSpellImpl(MagicItem* a_spell);                                                                                                                               // 10 - { return; }
		virtual void                       Unk_11(void);                                                                                                                                                          // 11 - { return; }
		virtual void                       Unk_12(void);                                                                                                                                                          // 12 - { return; }
		virtual void                       SetSkipCheckCast();                                                                                                                                                    // 13 - { return; }
		virtual void                       SetCastingTimerForCharge();                                                                                                                                            // 14
		virtual MagicSystem::CastingSource GetCastingSource() const;                                                                                                                                              // 15 - { return 0; }
		virtual bool                       GetIsDualCasting() const;                                                                                                                                              // 16 - { return 0; }
		virtual void                       SetDualCasting(bool a_value);                                                                                                                                          // 17 - { return; }
		virtual void                       SaveGame(BGSSaveFormBuffer* a_buffer);                                                                                                                                 // 18
		virtual void                       LoadGame(BGSLoadFormBuffer* a_buffer);                                                                                                                                 // 19
		virtual void                       Unk_1A(void);                                                                                                                                                          // 1A
		virtual void                       Unk_1B(void);                                                                                                                                                          // 1B
		virtual void                       AdjustActiveEffect(ActiveEffect* a_effect, float a_power, bool a_hostileOnly);                                                                                         // 1C

		// members
		BSTArray<BSSoundHandle>                sounds;             // 08
		ObjectRefHandle                        desiredTarget;      // 20
		std::uint32_t                          pad24;              // 24
		MagicItem*                             currentSpell;       // 28
		stl::enumeration<State, std::uint32_t> state;              // 30
		float                                  castingTimer;       // 34
		float                                  currentSpellCost;   // 38
		float                                  magnitudeOverride;  // 3C
		float                                  nextTargetUpdate;   // 40
		float                                  projectileTimer;    // 44
	};
	static_assert(sizeof(MagicCaster) == 0x48);
}
