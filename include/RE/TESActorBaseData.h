#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormTypes

class BGSVoiceType;


namespace RE
{
	class TESActorBaseData : public BaseFormComponent	// ACBS
	{
	public:
		enum class Flag : UInt32
		{
			kNone = 0,
			kFemale = 1 << 0,
			kEssential = 1 << 1,
			kIsChargenFacePreset = 1 << 2,
			kRespawn = 1 << 3,
			kAutoCalcStats = 1 << 4,
			kUnique = 1 << 5,
			kDoesntAffectStealthMeter = 1 << 6,
			kPCLevelMult = 1 << 7,
			kUsesTemplate = 1 << 8,
			kProtected = 1 << 11,
			kSummonable = 1 << 14,
			kDoesntBleed = 1 << 16,
			kBleedoutOverride = 1 << 18,
			kOppositeGenderanims = 1 << 19,
			kSimpleActor = 1 << 20,
			kGhost = 1 << 29,
			kInvulnerable = (UInt32)(1 << 31)
		};


		enum class TemplateFlag : UInt16
		{
			kUseTraits = 1 << 0,
			kUseStats = 1 << 1,
			kUseFactions = 1 << 2,
			kUseSpellList = 1 << 3,
			kUseAIData = 1 << 4,
			kUseAIPackages = 1 << 5,
			kUseModelAnimation = 1 << 6,
			kUseBaseData = 1 << 7,
			kUseInventory = 1 << 8,
			kUseScript = 1 << 9,
			kUseDefPackageList = 1 << 10,
			kUseAttackData = 1 << 11,
			kUseKeywords = 1 << 12,
		};


		struct FactionInfo	// SNAM
		{
			TESFaction*	faction;	// 0
			SInt8		rank;		// 8
			UInt8		pad9[7];	// 9
		};


		virtual ~TESActorBaseData();

		// override (BaseFormComponent)
		virtual void	Init() override;
		virtual void	ReleaseRefs() override;
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;

		// add
		virtual void	Unk_04(void);		// 04 - { return 0; }
		virtual bool	IsGhost();			// 05 - { return (flags >> 29) & 1; }
		virtual bool	IsInvulnerable();	// 06 - { test flags, 80000000h; }
		virtual void	Unk_07(void);		// 07 - { return 1; }

		bool			IsFemale();
		bool			IsPreset();
		bool			IsEssential();
		bool			Respawns();
		bool			HasAutoCalcStats();
		bool			IsUnique();
		bool			AffectsStealthMeter();
		bool			HasPCLevelMult();
		bool			UsesTemplate();
		bool			Protected();
		bool			IsSummonable();
		bool			Bleeds();
		bool			HasBleedoutOverride();
		bool			UsesOppositeGenderAnims();
		bool			IsSimpleActor();


		// members
		Flag					flags;				// 08
		UInt16					magickaOffset;		// 0C
		UInt16					staminaOffset;		// 0E
		UInt16					level;				// 10
		UInt16					calcMinLevel;		// 12
		UInt16					calcMaxLevel;		// 14
		UInt16					speedMultiplier;	// 16
		UInt16					dispositionBase;	// 18
		TemplateFlag			templateFlags;		// 1A
		UInt16					healthOffset;		// 1C
		UInt16					bleedoutOverride;	// 1E
		TESLevItem*				deathItem;			// 20 - INAM?
		BGSVoiceType*			voiceType;			// 28 - VTCK
		TESNPC*					templateNPC;		// 30 - TPLT
		UInt32					unk38;				// 38 - SPCT?
		UInt32					pad3C;				// 3C
		BSTArray<FactionInfo*>	factions;			// 40
	};
	STATIC_ASSERT(sizeof(TESActorBaseData) == 0x58);
}