#pragma once

#include "RE/B/BSTSingleton.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	struct DEFAULT_OBJECTS
	{
		enum DEFAULT_OBJECT
		{
			kWerewolfSpell,
			kSittingAngleLimit,
			kAllowPlayerShout,
			kGold,
			kLockpick,
			kSkeletonKey,
			kPlayerFaction,
			kGuardFaction,
			kDefaultMusic,
			kBattleMusic,
			kDeathMusic,
			kSuccessMusic,
			kLevelUpMusic,
			kDungeonClearedMusic,
			kPlayerVoiceMale,
			kPlayerVoiceMaleChild,
			kPlayerVoiceFemale,
			kPlayerVoiceFemaleChild,
			kEatPackageDefaultFood,
			kLeftHandEquip,
			kRightHandEquip,
			kEitherHandEquip,
			kVoiceEquip,
			kPotionEquip,
			kEveryActorAbility,
			kCommandedActorAbility,
			kDrugWearsOffImageSpace,
			kFootstepSet,
			kLandscapeMaterial,
			kDragonLandZoneMarker,
			kDragonCrashZoneMarker,
			kCombatStyle,
			kDefaultPackList,
			kWaitForDialoguePackage,
			kLocRefTypeBoss,
			kVirtualLocation,
			kPersistAllLocation,
			kInventoryPlayer,
			kPathingTestNPC,
			kFavorCostSmall,
			kFavorCostMedium,
			kFavorCostLarge,
			kFavorGiftsPerDay,
			kActionSwimStateChange,
			kActionLook,
			kActionLeftAttack,
			kActionLeftReady,
			kActionLeftRelease,
			kActionLeftInterrupt,
			kActionRightAttack,
			kActionRightReady,
			kActionRightRelease,
			kActionRightInterrupt,
			kActionDualAttack,
			kActionDualRelease,
			kActionActivate,
			kActionJump,
			kActionFall,
			kActionLand,
			kActionSneak,
			kActionVoice,
			kActionVoiceReady,
			kActionVoiceRelease,
			kActionVoiceInterrupt,
			kActionIdle,
			kActionSprintStart,
			kActionSprintStop,
			kActionDraw,
			kActionSheath,
			kActionLeftPowerAttack,
			kActionRightPowerAttack,
			kActionDualPowerAttack,
			kActionStaggerStart,
			kActionBlockHit,
			kActionBlockAnticipate,
			kActionRecoil,
			kActionLargeRecoil,
			kActionBleedoutStart,
			kActionBleedoutStop,
			kActionIdleStop,
			kActionWardHit,
			kActionForceEquip,
			kActionShieldChange,
			kActionPathStart,
			kActionPathEnd,
			kActionLargeMovementDelta,
			kActionFlyStart,
			kActionFlyStop,
			kActionHoverStart,
			kActionHoverStop,
			kActionBumpedInto,
			kActionSummonedStart,
			kActionTalkingIdle,
			kActionListenIdle,
			kActionDeath,
			kActionDeathWait,
			kActionIdleWarn,
			kActionMoveStart,
			kActionMoveStop,
			kActionTurnRight,
			kActionTurnLeft,
			kActionTurnStop,
			kActionMoveForward,
			kActionMoveBackward,
			kActionMoveLeft,
			kActionMoveRight,
			kActionResetAnimationGraph,
			kActionKnockdown,
			kActionGetUp,
			kActionIdleStopInstant,
			kActionRagdollInstant,
			kActionWaterwalkStart,
			kActionReload,
			kPickupSoundGeneric,
			kPutdownSoundGeneric,
			kPickupSoundWeapon,
			kPutdownSoundWeapon,
			kPickupSoundArmor,
			kPutdownSoundArmor,
			kPickupSoundBook,
			kPutdownSoundBook,
			kPickupSoundIngredient,
			kPutdownSoundIngredient,
			kHarvestSound,
			kHarvestFailedSound,
			kWardBreakSound,
			kWardAbsorbSound,
			kWardDeflectSound,
			kMagicFailSound,
			kShoutFailSound,
			kHeartbeatSoundFast,
			kHeartbeatSoundSlow,
			kImagespaceLowHealth,
			kSoulCapturedSound,
			kNoActivationSound,
			kMapMenuLoopingSound,
			kDialogueVoiceCategory,
			kNonDialogueVoiceCategory,
			kSFXToFadeInDialogueCategory,
			kPauseDuringMenuCategoryFade,
			kPauseDuringMenuCategoryImmediate,
			kPauseDuringLoadingMenuCategory,
			kMusicSoundCategory,
			kStatsMuteCategory,
			kStatsMusic,
			kMasterSoundCategory,
			kTimeSensitiveSoundCategory,
			kDialogueOutputModel3D,
			kDialogueOutputModel2D,
			kPlayersOutputModel1stPerson,
			kPlayersOutputModel3rdPerson,
			kInterfaceOutputModel,
			kReverbType,
			kUnderwaterLoopSound,
			kUnderwaterReverbType,
			kKeywordHorse,
			kKeywordUndead,
			kKeywordNPC,
			kKeywordBeastRace,
			kKeywordDummyObject,
			kKeywordUseGeometryEmitter,
			kKeywordMustStop,
			kKeywordUpdateDuringArchery,
			kKeywordSkipOutfitItems,
			kMaleFaceTextureSetHead,
			kMaleFaceTextureSetMouth,
			kMaleFaceTextureSetEyes,
			kFemaleFaceTextureSetHead,
			kFemaleFaceTextureSetMouth,
			kFemaleFaceTextureSetEyes,
			kImageSpaceModifierforinventorymenu,
			kPackagetemplate,
			kMainMenuCell,
			kDefaultMovementTypeWalk,
			kDefaultMovementTypeRun,
			kDefaultMovementTypeSwim,
			kDefaultMovementTypeFly,
			kDefaultMovementTypeSneak,
			kDefaultMovementTypeSprint,
			kKeywordSpecialFurniture,
			kKeywordFurnitureForces1stPerson,
			kKeywordFurnitureForces3rdPerson,
			kKeywordActivatorFurnitureNoPlayer,
			kTelekinesisGrabSound,
			kTelekinesisThrowSound,
			kWorldMapWeather,
			kHelpManualPC,
			kHelpManualXBox,
#if HAS_SKYRIMSE(1, 7, 99)
			kHelpManualNX,
#endif
			kKeywordTypeAmmo,
			kKeywordTypeArmor,
			kKeywordTypeBook,
			kKeywordTypeIngredient,
			kKeywordTypeKey,
			kKeywordTypeMisc,
			kKeywordTypeSoulGem,
			kKeywordTypeWeapon,
			kKeywordTypePotion,
			kBaseWeaponEnchantment,
			kBaseArmorEnchantment,
			kBasePotion,
			kBasePoison,
			kKeywordDragon,
			kKeywordMovable,
			kArtObjectAbsorbEffect,
			kWeaponMaterialList,
			kArmorMaterialList,
			kKeywordDisallowEnchanting,
			kFavortravelmarkerlocation,
			kKeywordHoldLocation,
			kKeywordCivilWarOwner,
			kKeywordCivilWarNeutral,
			kLocRefTypeCivilWarSoldier,
			kKeywordClearableLocation,
			kLocRefTypeResourceDestructible,
			kFormListHairColorList,
			kComplexSceneObject,
			kKeywordReusableSoulGem,
			kKeywordAnimal,
			kKeywordDaedra,
			kKeywordRobot,
			kKeywordNirnroot,
			kFightersGuildFaction,
			kMagesGuildFaction,
			kThievesGuildFaction,
			kDarkBrotherhoodFaction,
			kJarlFaction,
			kBunnyFaction,
			kPlayerIsVampireVariable,
			kPlayerIsWerewolfVariable,
			kRoadMarker,
			kKeywordScaleActorTo10,
			kKeywordVampire,
			kKeywordForge,
			kKeywordCookingPot,
			kKeywordSmelter,
			kKeywordTanningRack,
			kHelpBasicLockpickingPC,
			kHelpBasicLockpickingConsole,
			kHelpBasicForging,
			kHelpBasicCooking,
			kHelpBasicSmelting,
			kHelpBasicTanning,
			kHelpBasicObjectCreation,
			kHelpBasicEnchanting,
			kHelpBasicSmithingWeapon,
			kHelpBasicSmithingArmor,
			kHelpBasicAlchemy,
			kHelpBarter,
			kHelpLevelingup,
			kHelpSkillsMenu,
			kHelpMapMenu,
			kHelpJournal,
			kHelpLowHealth,
			kHelpLowMagicka,
			kHelpLowStamina,
			kHelpJail,
			kHelpTeamateFavor,
			kHelpWeaponCharge,
			kHelpFavorites,
			kKinectHelpFormList,
			kHelpFlyingMount,
			kHelpTargetLock,
			kHelpAttackTarget,
#if HAS_SKYRIMSE(1, 7, 99)
			kHelpMotionAttackBlock,
			kHelpMotionBowAiming,
			kHelpMotionMagicAiming,
			kHelpMotionLockpicking,
			kHelpAmiibo,
#endif
			kImagespaceLoadscreen,
			kKeywordWeaponMaterialDaedric,
			kKeywordWeaponMaterialDraugr,
			kKeywordWeaponMaterialDraugrHoned,
			kKeywordWeaponMaterialDwarven,
			kKeywordWeaponMaterialEbony,
			kKeywordWeaponMaterialElven,
			kKeywordWeaponMaterialFalmer,
			kKeywordWeaponMaterialFalmerHoned,
			kKeywordWeaponMaterialGlass,
			kKeywordWeaponMaterialImperial,
			kKeywordWeaponMaterialIron,
			kKeywordWeaponMaterialOrcish,
			kKeywordWeaponMaterialSteel,
			kKeywordWeaponMaterialWood,
			kKeywordWeaponTypeBoundArrow,
			kKeywordArmorMaterialDaedric,
			kKeywordArmorMaterialDragonplate,
			kKeywordArmorMaterialDragonscale,
			kKeywordArmorMaterialDragonbone,
			kKeywordArmorMaterialDwarven,
			kKeywordArmorMaterialEbony,
			kKeywordArmorMaterialElven,
			kKeywordArmorMaterialElvenSplinted,
			kKeywordArmorMaterialFullLeather,
			kKeywordArmorMaterialGlass,
			kKeywordArmorMaterialHide,
			kKeywordArmorMaterialImperial,
			kKeywordArmorMaterialImperialHeavy,
			kKeywordArmorMaterialImperialReinforced,
			kKeywordArmorMaterialIron,
			kKeywordArmorMaterialIronBanded,
			kKeywordArmorMaterialOrcish,
			kKeywordArmorMaterialScaled,
			kKeywordArmorMaterialSteel,
			kKeywordArmorMaterialSteelPlate,
			kKeywordArmorMaterialStormcloak,
			kKeywordArmorMaterialStudded,
			kKeywordGenericCraftableKeyword01,
			kKeywordGenericCraftableKeyword02,
			kKeywordGenericCraftableKeyword03,
			kKeywordGenericCraftableKeyword04,
			kKeywordGenericCraftableKeyword05,
			kKeywordGenericCraftableKeyword06,
			kKeywordGenericCraftableKeyword07,
			kKeywordGenericCraftableKeyword08,
			kKeywordGenericCraftableKeyword09,
			kKeywordGenericCraftableKeyword10,
			kKeywordJewelry,
			kKeywordCuirass,
			kLocalMapHidePlane,
			kSnowLODMaterial,
			kSnowLODMaterialHD,
			kAshLODMaterial,
			kAshLODMaterialHD,
			kDialogueFollowerQuest,
			kPotentialFollowerFaction,
			kWerewolfAvailablePerks,
			kVampireAvailablePerks,
			kSurvivalModeToggle,
			kSurvivalModeEnabled,
			kSurvivalModeShowOption,
			kSurvivalTemperature,
			kSurvivalColdPenalty,
			kSurvivalHungerPenalty,
			kSurvivalSleepPenalty,
			kSurvivalKeywordCold,
			kSurvivalKeywordWarm,
			kSurvivalKeywordArmorHands,
			kSurvivalKeywordClothingHands,
			kSurvivalKeywordArmorFeet,
			kSurvivalKeywordClothingFeet,
			kSurvivalKeywordArmorBody,
			kSurvivalKeywordClothingBody,
			kSurvivalKeywordArmorHead,
			kSurvivalKeywordClothingHead,
			kWerewolfRace,
			kVampireRace,
			kVampireSpells,
			kDragonMountNoLandList,
			kPlayerCanMountDragonHereList,
			kFlyingMountAllowedSpells,
			kFlyingMountDisallowedSpells,
			kKeywordMount,
			kVerletCape,
			kFurnitureTestNPC,
			kKeywordConditionalExplosion,
			kVampireFeedNoCrimeFaction,
			kSkyrimWorldspace,
			kKeywordArmorMaterialLightBonemold,
			kKeywordArmorMaterialLightChitin,
			kKeywordArmorMaterialLightNordic,
			kKeywordArmorMaterialLightStalhrim,
			kFlyingMountFlyFastWorldspaces,
			kKeywordArmorMaterialHeavyBonemold,
			kKeywordArmorMaterialHeavyChitin,
			kKeywordArmorMaterialHeavyNordic,
			kKeywordArmorMaterialHeavyStalhrim,
			kKeywordWeaponMaterialNordic,
			kKeywordWeaponMaterialStalhrim,
#if HAS_SKYRIMSE(1, 7, 99)
			kHelpManualCreationClub,
			kHelpManualCreationClubAE,
#endif
			kModsHelpFormList,

			kTotal
		};
	};
	using DEFAULT_OBJECT = DEFAULT_OBJECTS::DEFAULT_OBJECT;
#if HAS_SKYRIMSE(1, 7, 99)
	static_assert(DEFAULT_OBJECT::kKeywordTypeAmmo == 189);
	static_assert(DEFAULT_OBJECT::kImagespaceLoadscreen == 269);
	static_assert(DEFAULT_OBJECT::kModsHelpFormList == 371);
	static_assert(DEFAULT_OBJECT::kTotal == 372);
#else
	static_assert(DEFAULT_OBJECT::kKeywordTypeAmmo == 188);
	static_assert(DEFAULT_OBJECT::kImagespaceLoadscreen == 263);
	static_assert(DEFAULT_OBJECT::kModsHelpFormList == 363);
	static_assert(DEFAULT_OBJECT::kTotal == 364);
#endif

	enum class DEFAULT_OBJECT_TYPE
	{
		kMisc = 0,
		kFaceGen = 1,
		kMovement = 2,
		kActions = 3,
		kItems = 4,
		kSounds = 5,
		kKeywords = 6
	};

	struct DEFAULT_OBJECT_DATA
	{
	public:
		// members
		const char*                                          name;         // 00
		stl::enumeration<FormType, std::uint8_t>             type;         // 08
		std::uint8_t                                         pad09;        // 09
		std::uint16_t                                        pad0A;        // 0A
		char                                                 uniqueID[4];  // 0C
		stl::enumeration<DEFAULT_OBJECT_TYPE, std::uint32_t> doType;       // 10
		std::uint32_t                                        pad14;        // 14
	};
	static_assert(sizeof(DEFAULT_OBJECT_DATA) == 0x18);

	class BGSDefaultObjectManager :
		public TESForm,                                       // 000
		public BSTSingletonImplicit<BGSDefaultObjectManager>  // 020
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSDefaultObjectManager;

		using DefaultObject = DEFAULT_OBJECT;
		inline static constexpr auto FORMTYPE = FormType::DefaultObject;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		~BGSDefaultObjectManager() override;  // 00

		// override (TESForm)
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		[[nodiscard]] static BGSDefaultObjectManager* GetSingleton();

		[[nodiscard]] TESForm* GetObject(DefaultObject a_object) const noexcept { return GetObject(stl::to_underlying(a_object)); }

		template <class T>
		[[nodiscard]] T* GetObject(DefaultObject a_object) const noexcept
		{
			return GetObject<T>(stl::to_underlying(a_object));
		}

		[[nodiscard]] TESForm* GetObject(std::size_t a_idx) const noexcept
		{
			assert(a_idx < stl::to_underlying(DefaultObject::kTotal));
			return objectInit[a_idx] ? objects[a_idx] : nullptr;
		}

		template <class T>
		[[nodiscard]] T* GetObject(std::size_t a_idx) const noexcept
		{
			const auto obj = GetObject(a_idx);
			return obj ? obj->As<T>() : nullptr;
		}

		// members
		TESForm* objects[DEFAULT_OBJECTS::kTotal];     // 020 - DNAM
		bool     objectInit[DEFAULT_OBJECTS::kTotal];  // BC0
	};
#if HAS_SKYRIMSE(1, 7, 99)
	static_assert(sizeof(BGSDefaultObjectManager) == 0xD38);
#else
	static_assert(sizeof(BGSDefaultObjectManager) == 0xCF0);
#endif
}
