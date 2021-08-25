#pragma once
#include <REL/Relocation.h>

namespace RE
{
	namespace Offset
	{
		namespace _CRT
		{
			inline constexpr REL::Offset RTDynamicCast(0x0138BABA);
		}

		namespace ActivateHandler
		{
			// VTable: .?AUActivateHandler@@
			inline constexpr REL::Offset Vtbl(0x016F22E8);  // VR 1_4_15
		}

		namespace ActiveEffect
		{
			// IndirectSig: E8 ? ? ? ? 48 85 DB 75 C9
			inline constexpr REL::Offset Dispel(0x00541100);  // VR 1_4_15
		}

		namespace Actor
		{
			// IndirectSig: E8 ? ? ? ? 0F B6 F0 49 8D 4E 30
			inline constexpr REL::Offset AddSpell(0x00638430);  // VR 1_4_15
			inline constexpr REL::Offset RemoveSpell(0x006385F0);
			// IndirectSig: E8 ? ? ? ? 49 8B D5 49 8B 8D ? ? ? ?
			inline constexpr REL::Offset DispelWornItemEnchantments(0x0055CCB0);  // VR 1_4_15
			// DirectSig: 40 55 56 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 0F B6 DA 48 8B F1
			inline constexpr REL::Offset DoReset3D(0x0069C710);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B CD E8 ? ? ? ? 85 C0 74 0B
			inline constexpr REL::Offset EvaluatePackage(0x005E3990);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 84 C0 49 0F 45 F4
			inline constexpr REL::Offset GetGhost(0x005DAAE0);  // VR 1_4_15
			// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B F2 48 8B D9 40 32 FF
			inline constexpr REL::Offset GetHostileToActor(0x005F0560);  // VR 1_4_15
			// DirectSig: 48 8B 49 40 48 83 C1 30 E9 ? ? ? ?
			inline constexpr REL::Offset GetLevel(0x005DE910);  // VR 1_4_15
			// DirectSig: 48 83 EC 28 48 8B 81 ? ? ? ? 48 85 C0 74 16
			inline constexpr REL::Offset HasPerk(0x006025A0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B CF 0F B6 E8
			inline constexpr REL::Offset InterruptCast(0x0063AB50);
			inline constexpr REL::Offset IsRunning(0x005D9770);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 85 C0 7E 2D
			inline constexpr REL::Offset RequestDetectionLevel(0x00605190);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? EB 1D 8B 4D 7F
			inline constexpr REL::Offset StealAlarm(0x005E5DC0);  // VR 1_4_15
			// DirectSig: 48 85 D2 0F 84 ? ? ? ? 41 56 48 83 EC 40
			inline constexpr REL::Offset SwitchRace(0x00610000);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 89 7D D8 48 8D 55 D8
			inline constexpr REL::Offset UpdateArmorAbility(0x0063A230);  // VR 1_4_15
			// DirectSig: 48 85 D2 0F 84 ? ? ? ? 48 89 6C 24 ? 56 57
			inline constexpr REL::Offset UpdateWeaponAbility(0x0063A2A0);  // VR 1_4_15
			// VTable: .?AVActor@@
			inline constexpr REL::Offset Vtbl(0x016CE888);  // VR 1_4_15
		}

		namespace ActorEquipManager
		{
			// DirectSig: 48 85 D2 0F 84 ? ? ? ? 57 48 83 EC 50 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 49 8B D9
			inline constexpr REL::Offset EquipObject(0x00640A90);  // VR 1_4_15
			inline constexpr REL::Offset EquipShout(0x006556848);
			inline constexpr REL::Offset EquipSpell(0x006556624);
			// 88 4C 24 30 48 8B 0D ? ? ? ? 48 C7 44 24 ? ? ? ? ?
			inline constexpr REL::Offset Singleton(0x02F896D8);  // VR
			// IndirectSig: E8 ? ? ? ? 84 C0 0F 94 C0 33 F6
			inline constexpr REL::Offset UnequipObject(0x006411A0);  // VR 1_4_15
		}

		namespace ActorValueList
		{
			inline constexpr REL::Offset GetSingleton(0x1f82ac8);
		}

		namespace ActorValueOwner
		{
			// IndirectSig: E8 ? ? ? ? F3 44 0F 2C C0
			inline constexpr REL::Offset GetClampedActorValue(0x003F4DA0);  // VR 1_4_15
		}

		namespace AIProcess
		{
			// IndirectSig: E8 ? ? ? ? 0F 28 C7 0F 28 7C 24 ?
			inline constexpr REL::Offset SetBaseScale(0x00665BD0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? E9 ? ? ? ? 8B 4F 08
			inline constexpr REL::Offset Update3DModel(0x0065A140);  // VR 1_4_15
		}

		namespace AttackBlockHandler
		{
			// VTable: .?AUAttackBlockHandler@@
			inline constexpr REL::Offset Vtbl(0x016F2258);  // VR 1_4_15
		}

		namespace AutoMoveHandler
		{
			// VTable: .?AUAutoMoveHandler@@
			inline constexpr REL::Offset Vtbl(0x016F2338);  // VR 1_4_15
		}

		namespace BGSDecalManager
		{
			inline constexpr REL::Offset GetSingleton(0x1f89188);
		}

		namespace BGSDefaultObjectManager
		{
			// IndirectSig: E8 ? ? ? ? 4C 63 C3
			inline constexpr REL::Offset GetSingleton(0x0001077C0);  // VR 1_4_15
		}

		namespace BGSFootstepManager
		{
			// E8 ? ? ? ? 90 48 89 1D ? ? ? ? 48 8D 0D ? ? ? ?
			inline constexpr REL::Offset Singleton(0x02FEBC50);  // VR
		}

		namespace BGSIdleCollection
		{
			inline constexpr REL::Offset Ctor(0x0196d70);
		}

		namespace BGSListForm
		{
			// IndirectSig: E8 ? ? ? ? E9 ? ? ? ? 48 83 7B ? ? 75 5E
			inline constexpr REL::Offset AddForm(0x002D6B40);  // VR 1_4_15
		}

		namespace BGSSaveLoadManager
		{
			// DirectSig: 44 89 44 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ?
			inline constexpr REL::Offset Save(0x0058E310);  // VR 1_4_15
			// 48 89 05 ? ? ? ? 48 8B 0D ? ? ? ? 48 81 C1 ? ? ? ?
			inline constexpr REL::Offset Singleton(0x02FEB248);  // VR 1_4_15
			// DirectSig: 48 8B C4 48 89 58 10 57 48 81 EC ? ? ? ? 48 8B DA 66 C7 40 ? ? ?
			inline constexpr REL::Offset Load(0x0058E920);  // VR 1_4_15
		}

		namespace BGSStoryTeller
		{
			// DirectSig: 40 56 57 41 56 48 83 EC 40 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 8B FA 48 8B E9 44 8B 05 ? ? ? ? 65 48 8B 04 25 ? ? ? ? B9 ? ? ? ? 4A 8B 34 C0 48 03 F1 8B 1E 89 5C 24 68
			inline constexpr REL::Offset BeginShutDownQuest(0x004E8240);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 4C 8D 35 ? ? ? ? 40 84 F6
			inline constexpr REL::Offset BeginStartUpQuest(0x004E8120);  // VR 1_4_15
			// 48 8B 0D ? ? ? ? 48 8B D3 45 84 C0
			inline constexpr REL::Offset Singleton(0x01EC3B80);  // 1_5_97
		}

		namespace BGSWaterSystemManager
		{
			inline constexpr REL::Offset GetSingleton(0x1f85120);
			inline constexpr REL::Offset CreateBulletWaterDisplacement(0x04d8a40);
		}

		namespace BipedAnim
		{
			// IndirectSig: E8 ? ? ? ? BA ? ? ? ? 48 8B CF E8 ? ? ? ? 48 8B 5C 24 ? EB 76
			inline constexpr REL::Offset Dtor(0x001D6200);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 48 8D 8B ? ? ? ? 4C 8D 0D ? ? ? ? BA ? ? ? ? 44 8D 42 B2
			inline constexpr REL::Offset RemoveAllParts(0x001D6530);  // VR 1_4_15
		}

		namespace BSAudioManager
		{
			// IndirectSig: E8 ? ? ? ? BA 33 00 00 00
			inline constexpr REL::Offset GetSingleton(0x00C29430);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? C6 46 04 01
			inline constexpr REL::Offset BuildSoundDataFromDescriptor(0x00C29F60);  // VR 1_4_15
		}

		namespace BSDismemberSkinInstance
		{
			inline constexpr REL::Offset UpdateDismemberPartion(0x1401de820);
		}

		namespace BSFaceGenManager
		{
			inline constexpr REL::Offset GetSingleton(0x03e17c0);
			inline constexpr REL::Offset     PrepareHeadPartForShaders(0x03e23d0);
		}

		namespace BSFixedString
		{
			// IndirectSig: E8 ? ? ? ? 83 CD 01
			inline constexpr REL::Offset Ctor8(0x00C6DB20);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 89 7D 98
			inline constexpr REL::Offset Ctor_Copy(0x00C6DBB0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 01 5F 1C
			inline constexpr REL::Offset Set_CStr(0x00C6DC90);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? F7 DF
			inline constexpr REL::Offset Set_Copy(0x00C6DD50);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? EB 94
			inline constexpr REL::Offset Dtor8(0x00C6DC70);  // VR 1_4_15
			// DirectSig: 40 53 48 83 EC 20 48 C7 01 00 00 00 00 4C 8B DA
			inline constexpr REL::Offset Ctor16(0x00C6E440);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 4C 8D 45 C8 48 8D 55 D8
			inline constexpr REL::Offset Dtor16(0x00C6E550);  // VR 1_4_15
		}

		namespace BSInputDeviceManager
		{
			// 74 0D 48 83 C0 A8
			inline constexpr REL::Offset Singleton(0x02FEA520);  // VR
		}

		namespace BSLightingShaderMaterial
		{
			inline constexpr REL::Offset Ctor(0x130dc60);
		}

		namespace BSLightingShaderMaterialBase
		{
			// IndirectSig: E8 ? ? ? ? 45 33 C0 33 D2 48 8B CF 4C 8B F0
			inline constexpr REL::Offset CreateMaterial(0x0130EAD0);  // VR 1_4_15
		}

		namespace BSLightingShaderMaterialEnvmap
		{
			inline constexpr REL::Offset Ctor(0x130f0b0);
		}

		namespace BSLightingShaderMaterialEye
		{
			inline constexpr REL::Offset Ctor(0x130f760);
		}

		namespace BSLightingShaderMaterialFacegen
		{
			inline constexpr REL::Offset Ctor(0x1310e80);
		}

		namespace BSLightingShaderMaterialFacegenTint
		{
			inline constexpr REL::Offset Ctor(0x13115a0);
		}

		namespace BSLightingShaderMaterialGlowmap
		{
			inline constexpr REL::Offset Ctor(0x130ff20);
		}

		namespace BSLightingShaderMaterialHairTint
		{
			inline constexpr REL::Offset Ctor(0x13117c0);
		}

		namespace BSLightingShaderMaterialLODLandscape
		{
			inline constexpr REL::Offset Ctor(0x1312270);
		}

		namespace BSLightingShaderMaterialLandscape
		{
			inline constexpr REL::Offset Ctor(0x13119d0);
		}

		namespace BSLightingShaderMaterialMultiLayerParallax
		{
			inline constexpr REL::Offset Ctor(0x13129e0);
		}

		namespace BSLightingShaderMaterialParallax
		{
			inline constexpr REL::Offset Ctor(0x13103c0);
		}

		namespace BSLightingShaderMaterialParallaxOcc
		{
			inline constexpr REL::Offset Ctor(0x1310860);
		}

		namespace BSLightingShaderMaterialSnow
		{
			inline constexpr REL::Offset Ctor(0x1312800);
		}

		namespace BSReadWriteLock
		{
			// IndirectSig: E8 ? ? ? ? 4D 8B 27
			inline constexpr REL::Offset LockForRead(0x00C42150);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 40 88 77 2C
			inline constexpr REL::Offset LockForWrite(0x00C421D0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 EB 2E
			inline constexpr REL::Offset UnlockForRead(0x00C42410);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 8B 56 14
			inline constexpr REL::Offset UnlockForWrite(0x00C42420);  // VR 1_4_15
		}

		namespace BSResourceNiBinaryStream
		{
			// DirectSig: 48 89 4C 24 ? 57 41 56 41 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 49 8B D9
			inline constexpr REL::Offset Ctor(0x00CBC490);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 8B 84 24 ? ? ? ? 89 07
			inline constexpr REL::Offset Dtor(0x00CBC770);  // VR 1_4_15
			// DirectSig: 48 83 79 ? ? 4C 8B C9
			inline constexpr REL::Offset Seek(0x00CBC8C0);  // VR 1_4_15
			// ??_7BSResourceNiBinaryStream@@6B@ + 0x5
			inline constexpr REL::Offset SetEndianSwap(0x00CBC9B0);  // VR 1_4_15
		}

		namespace BSScaleformManager
		{
			// IndirectSig: E8 ? ? ? ? 84 C0 74 50 48 8B 4F 10
			inline constexpr REL::Offset LoadMovie(0x00F2B480);  // VR 1_4_15
			// 48 89 0D ? ? ? ? 4C 89 79 18
			inline constexpr REL::Offset Singleton(0x02FEA518);  // VR
		}

		namespace BSScaleformTranslator
		{
			// VTable: .?AVBSScaleformTranslator@@
			inline constexpr REL::Offset Vtbl(0x01866FA0);  // VR 1_4_15
		}

		namespace BSScript
		{
			namespace Object
			{
				inline constexpr REL::Offset GetHandle(0x0126BBD0);
				// IndirectSig: E8 ? ? ? ? 49 89 3F
				inline constexpr REL::Offset IncRef(0x0126C810);  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 85 C0 75 10 49 8B CE
				inline constexpr REL::Offset DecRef(0x0126C8C0);  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 49 8B CE E8 ? ? ? ? 48 85 DB 74 08
				inline constexpr REL::Offset Dtor(0x0126BB20);  // VR 1_4_15
			}

			namespace ObjectTypeInfo
			{
				// IndirectSig: E8 ? ? ? ? 90 48 8D 4B 18 E8 ? ? ? ? 90 48 8B 4B 10
				inline constexpr REL::Offset ReleaseData(0x01270B80);  // VR 1_4_15
			}

			namespace ObjectBindPolicy
			{
				// IndirectSig: E8 ? ? ? ? 80 BD ? ? ? ? ? 0F 84 ? ? ? ? 48 C7 44 24 ? ? ? ? ?
				inline constexpr REL::Offset BindObject(0x01265F80);  // VR 1_4_15
			}

			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					// DirectSig: 48 8B C4 4C 89 48 20 4C 89 40 18 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 48 C7 44 24 ? ? ? ? ? 48 89 58 08
					inline constexpr REL::Offset Call(0x0129DD90);  // VR 1_4_15
				}
			}

			namespace Stack
			{
				inline constexpr REL::Offset GetStackFrameVariable(0x0129A720);
				// IndirectSig: E8 ? ? ? ? BA A0 00 00 00 49 8B CF
				inline constexpr REL::Offset Dtor(0x0129A210);  // VR 1_4_15
			}
		}

		namespace BSSoundHandle
		{
			// IndirectSig: E8 ? ? ? ? 84 C0 75 5C 49 8B 85 ? ? ? ?
			inline constexpr REL::Offset IsValid(0x00C28540);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? EB 0E 84 C0
			inline constexpr REL::Offset Play(0x00C283E0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? F3 0F 10 5D 9F
			inline constexpr REL::Offset SetObjectToFollow(0x00C289C0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 4C 8D 7E 20
			inline constexpr REL::Offset SetPosition(0x00C287D0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B CE E8 ? ? ? ? E9 ? ? ? ? B9 ? ? ? ?
			inline constexpr REL::Offset Stop(0x00C284B0);  // VR 1_4_15
		}

		namespace BSString
		{
			// DirectSig: 40 57 41 54 41 55 41 56 41 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 41 8B F8
			inline constexpr REL::Offset Set_CStr(0x00010A440);  // VR 1_4_15
		}

		namespace BSStringPool
		{
			inline constexpr REL::Offset Release8(0x00C6EDB0);
			inline constexpr REL::Offset Release16(0x00C6EF20);
		}

		namespace BSTimer
		{
			inline constexpr REL::Offset GetCurrentGlobalTimeMult(0x1ec569c);
		}

		namespace BSUntypedPointerHandle
		{
			// 8B 05 ? ? ? ? 89 44 24 78 48 8D 44 24 ? 8B 00
			inline constexpr REL::Offset NullHandle(0x01EBEABC);  // 1_5_97
		}

		namespace BucketTable
		{
			// IndirectSig: E8 ? ? ? ? 41 8B FE 41 8B CE
			inline constexpr REL::Offset GetSingleton(0x00C6F400);  // VR 1_4_15
		}

		namespace BSWin32SaveDataSystemUtility
		{
			// IndirectSig: E8 ? ? ? ? 4C 8B 18
			inline constexpr REL::Offset GetSingleton(0x0137C200);  // VR 1_4_15
		}

		namespace Calendar
		{
			//
			inline constexpr REL::Offset Singleton(0x01F85108);  // VR
		}

		namespace ChestsLooted
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 54 24 51
			inline constexpr REL::Offset GetEventSource(0x0088D4E0);  // VR 1_4_15
		}

		namespace Console
		{
			// 48 8D 0D ? ? ? ? E8 ? ? ? ? 83 3D ? ? ? ? ? 74 13 48 8D 15 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 45 33 C9 45 33 C0 BA ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 48 89 44 24 ?
			inline constexpr REL::Offset SelectedRef(0x02F4C31C);  // 1_5_97
			// IndirectSig: E8 ? ? ? ? BE 02 00 00 00 8B C6
			inline constexpr REL::Offset SetSelectedRef(0x008864D0);  // VR 1_4_15
		}

		namespace ConsoleLog
		{
			// E8 ? ? ? ? 48 89 2D ? ? ? ? 48 8B 0D ? ? ? ? 48 85 C9 74 0C E8 ? ? ? ? 48 89 2D ? ? ? ? 48 8B 0D ? ? ? ? 48 85 C9 74 0C E8 ? ? ? ? 48 89 2D ? ? ? ? 48 8B 0D ? ? ? ?
			inline constexpr REL::Offset Singleton(0x02FC4FE0);  // VR
			// DirectSig: 48 8B C4 57 41 54 41 55 41 56 41 57 48 83 EC 40 48 C7 40 ? ? ? ? ? 48 89 58 10 48 89 68 18 48 89 70 20 4D 8B F8 4C 8B E2
			inline constexpr REL::Offset VPrint(0x00886DF0);  // VR 1_4_15
		}

		namespace ControlMap
		{
			// E8 ? ? ? ? 90 48 89 05 ? ? ? ? 8B 05 ? ? ? ?
			inline constexpr REL::Offset Singleton(0x02EC5BD0);  // 1_5_97
		}

		namespace CRC32Calculator
		{
			// IndirectSig: E8 ? ? ? ? 8B 75 AB
			inline constexpr REL::Offset SizeOf32(0x00C41370);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 8B 5D C0
			inline constexpr REL::Offset SizeOf64(0x00C413F0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 8B 9D B8 00 00 00
			inline constexpr REL::Offset SizeOfSize(0x00C41310);  // VR 1_4_15
		}

		namespace CrosshairPickData
		{
			inline constexpr REL::Offset GetSingleton(0x2fc60c0);
		}

		namespace DialogueItem
		{
			// IndirectSig: E8 ? ? ? ? 48 8B F8 41 89 1E 48 8B C7 48 8B 5C 24 70
			inline constexpr REL::Offset Ctor(0x00572FD0);  // VR 1_4_15
		}

		namespace ExtraAliasInstanceArray
		{
			// VTable: .?AVExtraAliasInstanceArray@@
			inline constexpr REL::Offset Vtbl(0x015A3CF0);  // VR 1_4_15
		}

		namespace ExtraAshPileRef
		{
			// VTable: .?AVExtraAshPileRef@@
			inline constexpr REL::Offset Vtbl(0x015A3630);  // VR 1_4_15
		}

		namespace ExtraCannotWear
		{
			// VTable: .?AVExtraCannotWear@@
			inline constexpr REL::Offset Vtbl(0x015A3390);  // VR 1_4_15
		}

		namespace ExtraCanTalkToPlayer
		{
			// VTable: .?AVExtraCanTalkToPlayer@@
			inline constexpr REL::Offset Vtbl(0x015A3A90);  // VR 1_4_15
		}

		namespace ExtraCharge
		{
			// VTable: .?AVExtraCharge@@
			inline constexpr REL::Offset Vtbl(0x015A3410);  // VR 1_4_15
		}

		namespace ExtraContainerChanges
		{
			// VTable: .?AVExtraContainerChanges@@
			inline constexpr REL::Offset Vtbl(0x015A65D0);  // VR 1_4_15
		}

		namespace ExtraCount
		{
			// VTable: .?AVExtraCount@@
			inline constexpr REL::Offset Vtbl(0x015A3330);  // VR 1_4_15
		}

		namespace ExtraDataList
		{
			// IndirectSig: E8 ? ? ? ? 4C 8D 75 10
			inline constexpr REL::Offset Add(0x00142140);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? F7 43 28 FF 03 00 00 75 0C
			inline constexpr REL::Offset SetExtraFlags(0x00136360);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 41 89 1E 48 8B C7 48 8B 5C 24 60 48 8B 6C 24 68 48 83 C4 30 41 5E
			inline constexpr REL::Offset SetInventoryChanges(0x0011FBA0);  // VR 1_4_15
		}

		namespace ExtraEnchantment
		{
			// VTable: .?AVExtraEnchantment@@
			inline constexpr REL::Offset Vtbl(0x015A37D0);  // VR 1_4_15
		}

		namespace ExtraForcedTarget
		{
			// VTable: .?AVExtraForcedTarget@@
			inline constexpr REL::Offset Vtbl(0x015A3EB0);  // VR 1_4_15
		}

		namespace ExtraHealth
		{
			// VTable: .?AVExtraHealth@@
			inline constexpr REL::Offset Vtbl(0x015A33B0);  // VR 1_4_15
		}

		namespace ExtraHotkey
		{
			// VTable: .?AVExtraHotkey@@
			inline constexpr REL::Offset Vtbl(0x015A3470);  // VR 1_4_15
		}

		namespace ExtraLightData
		{
			// VTable: .?AVExtraLightData@@
			inline constexpr REL::Offset Vtbl(0x015A3D50);  // VR 1_4_15
		}

		namespace ExtraOwnership
		{
			// VTable: .?AVExtraOwnership@@
			inline constexpr REL::Offset Vtbl(0x015A32D0);  // VR 1_4_15
		}

		namespace ExtraPoison
		{
			// VTable: .?AVExtraPoison@@
			inline constexpr REL::Offset Vtbl(0x015A37B0);  // VR 1_4_15
		}

		namespace ExtraRank
		{
			// VTable: .?AVExtraRank@@
			inline constexpr REL::Offset Vtbl(0x015A3310);  // VR 1_4_15
		}

		namespace ExtraReferenceHandle
		{
			// VTable: .?AVExtraReferenceHandle@@
			inline constexpr REL::Offset Vtbl(0x015A34B0);  // VR 1_4_15
		}

		namespace ExtraSoul
		{
			// VTable: .?AVExtraSoul@@
			inline constexpr REL::Offset Vtbl(0x015A6650);  // VR 1_4_15
		}

		namespace ExtraTextDisplayData
		{
			// IndirectSig: E8 ? ? ? ? EB 08 48 8B 0F
			inline constexpr REL::Offset GenerateName(0x0014D130);  // VR 1_4_15
			// VTable: .?AVExtraTextDisplayData@@
			inline constexpr REL::Offset Vtbl(0x015A3E30);  // VR 1_4_15
		}

		namespace ExtraUniqueID
		{
			// VTable: .?AVExtraUniqueID@@
			inline constexpr REL::Offset Vtbl(0x015A3EF0);  // VR 1_4_15
		}

		namespace FavoritesHandler
		{
			// VTable: .?AUFavoritesHandler@@
			inline constexpr REL::Offset Vtbl(0x0173C9C0);  // VR 1_4_15
		}

		namespace FavoritesMenu
		{
			// VTable: .?AVFavoritesMenu@@
			inline constexpr REL::Offset Vtbl(0x01734F50);  // VR 1_4_15
		}

		namespace FirstPersonState
		{
			// VTable: .?AVFirstPersonState@@
			inline constexpr REL::Offset Vtbl(0x0172CEB0);  // VR 1_4_15
		}

		namespace FixedStrings
		{
			inline constexpr REL::Offset GetSingleton(0x01150c0);
		}

		namespace GameSettingCollection
		{
			// 48 83 3D ? ? ? ? ? 75 63
			inline constexpr REL::Offset Singleton(0x02F8A780);  // VR
		}

		namespace GFxLoader
		{
			// DirectSig: 45 8B D0 48 8B C1
			inline constexpr REL::Offset CreateMovie(0x00F38CA0);  // VR 1_4_15
		}

		namespace GFxMovieView
		{
			// IndirectSig: E8 ? ? ? ? C6 44 24 20 01 41 B9 03 00 00 00 44 8D 47 69
			inline constexpr REL::Offset InvokeNoReturn(0x00F30F20);  // VR 1_4_15
		}

		namespace GFxValue
		{
			namespace ObjectInterface
			{
				// IndirectSig: E8 ? ? ? ? 4C 8D 45 F0 48 8B 54 24 ?
				inline constexpr REL::Offset AttachMovie(0x00F24EF0);  // VR 1_4_15
				// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 49 8B D8 48 8B FA 48 8B F1 45 84 C9
				inline constexpr REL::Offset DeleteMember(0x00F25FE0);  // VR 1_4_15
				// DirectSig: 48 85 D2 74 04 8B 42 58
				inline constexpr REL::Offset GetArraySize(0x00F26720);  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 66 83 8D ? ? ? ? ? F3 0F 10 05 ? ? ? ?
				inline constexpr REL::Offset GetDisplayInfo(0x00F26770);  // VR 1_4_15
				// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 49 63 F0
				inline constexpr REL::Offset GetElement(0x00F26A80);  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 48 8B 4B 20 40 38 7D E8
				inline constexpr REL::Offset GetMember(0x00F26CA0);  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 4C 8D 0D ? ? ? ? E9 ? ? ? ? 4C 89 75 E8
				inline constexpr REL::Offset GotoAndPlay(0x00F270C0);  // VR 1_4_15
				// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 60 49 8B D8
				inline constexpr REL::Offset HasMember(0x00F27170);  // VR 1_4_15
				// DirectSig: 40 53 41 54 41 56 41 57 48 81 EC ? ? ? ?
				inline constexpr REL::Offset Invoke(0x00F273B0);  // VR 1_4_15
				// DirectSig: 48 83 EC 28 8B 42 08 25 ? ? ? ?
				inline constexpr REL::Offset ObjectAddRef(0x00F27BD0);  // VR 1_4_15
				// DirectSig: 40 53 48 83 EC 20 8B 42 08
				inline constexpr REL::Offset ObjectRelease(0x00F27C30);  // VR 1_4_15
				// DirectSig: 40 53 48 83 EC 40 49 8B C0
				inline constexpr REL::Offset PushBack(0x00F27E50);  // VR 1_4_15
				// DirectSig: 48 83 EC 28 45 8B D0
				inline constexpr REL::Offset RemoveElements(0x00F28210);  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 80 BE FE 03 03 00 00
				inline constexpr REL::Offset SetArraySize(0x00F28870);  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? E9 ? ? ? ? 4C 89 B5 ? ? ? ? 4C 89 74 24 ?
				inline constexpr REL::Offset SetDisplayInfo(0x00F28900);  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? FF C3 48 83 C6 18
				inline constexpr REL::Offset SetElement(0x00F294B0);  // VR 1_4_15
				// DirectSig: 48 89 6C 24 ? 56 57 41 56 48 83 EC 50 80 BC 24 ? ? ? ? ?
				inline constexpr REL::Offset SetMember(0x00F296F0);  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 8B 44 24 48 C1 E8 06 A8 01 74 19 4C 8B 44 24 ? 48 8D 54 24 ? 48 8B 4C 24 ? E8 ? ? ? ? 4C 89 6C 24 ?
				inline constexpr REL::Offset SetText(0x00F29840);  // VR 1_4_15
			}
		}

		namespace GlobalLookupInfo
		{
			//
			inline constexpr REL::Offset Singleton(0x01EC3CB0);  // 1_5_97
		}

		namespace GMemory
		{
			// GFxFunctionHandler::virt_dtor + 35
			inline constexpr REL::Offset GlobalHeap(0x0318CE40);  // VR
		}

		namespace GString
		{
			// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 48 8B FA 4C 8B F1 48 85 D2 74 3B
			inline constexpr REL::Offset Ctor(0x00F2DA40);  // VR 1_4_15
		}

		namespace hkContainerHeapAllocator
		{
			// 48 8D 0D ? ? ? ? 48 8B 93 C8 00 00 00
			inline constexpr REL::Offset Singleton(0x01DF5E70);  // 1_5_97
		}

		namespace hkReferencedObject
		{
			// DirectSig: 40 57 48 83 EC 20 66 83 79 ? ?
			inline constexpr REL::Offset AddReference(0x00A01280);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 89 6E 18 EB 19
			inline constexpr REL::Offset RemoveReference(0x00A01340);  // VR 1_4_15
		}

		namespace INIPrefSettingCollection
		{
			// 48 8D 4B 08 4C 3B C1 74 11 BA ? ? ? ? FF 15 ? ? ? ? EB 04 C6 43 08 00 48 8B 03 B2 01 48 8B CB FF 50 28 84 C0 74 18
			inline constexpr REL::Offset Singleton(0x030C3B18);  // VR
		}

		namespace INISettingCollection
		{
			// 48 05 ? ? ? ? 74 4B
			inline constexpr REL::Offset Singleton(0x03175FE0);  // VR
		}

		namespace InterfaceStrings
		{
			// E8 ? ? ? ? 90 48 89 05 ? ? ? ? 48 8B 0D ? ? ? ? E8 ? ? ? ? 48 83 3D ? ? ? ? ? 75 20
			inline constexpr REL::Offset Singleton(0x01F85100);  // VR 1_4_15
		}

		namespace Inventory
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 54 24 58 E8 ? ? ? ? 49 8B 0F
			inline constexpr REL::Offset GetEventSource(0x001FFE10);  // VR 1_4_15
		}

		namespace InventoryChanges
		{
			// IndirectSig: E8 ? ? ? ? 48 8B F8 48 8B D7 48 8B CD
			inline constexpr REL::Offset Ctor(0x001E9DA0);  // VR 1_4_15
			// DirectSig: 40 57 41 56 41 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 4C 8B F9 4C 8B 31
			inline constexpr REL::Offset Dtor(0x001E9E90);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 8B 44 24 68 41 89 06 48 83 C4 38
			inline constexpr REL::Offset GenerateLeveledListChanges(0x001F1470);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 44 0F B7 F8
			inline constexpr REL::Offset GetNextUniqueID(0x001ECD33);  // 1_5_97
			// IndirectSig: E8 ? ? ? ? 48 85 ED 74 3F
			inline constexpr REL::Offset SendContainerChangedEvent(0x001FD990);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 80 BC 24 ? ? ? ? ? 74 0D
			inline constexpr REL::Offset SetUniqueID(0x001FD7D0);  // VR 1_4_15
			// IndirectSig:
			inline constexpr REL::Offset TransferItemUID(0x001FD990);  // VR 1_4_15
		}

		namespace InventoryEntryData
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 5B 08 44 8B F8
			inline constexpr REL::Offset GetValue(0x001E7280);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 84 C0 0F 85 ? ? ? ? 48 8B 3F
			inline constexpr REL::Offset IsOwnedBy(0x001E8130);  // VR 1_4_15
		}

		namespace ItemCrafted
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 55 B8 E8 ? ? ? ? 45 85 E4
			inline constexpr REL::Offset GetEventSource(0x0089BE30);  // VR 1_4_15
		}

		namespace ItemList
		{
			// IndirectSig: E8 ? ? ? ? EB 4A 80 7D 1A 1B
			inline constexpr REL::Offset Update(0x00880E10);  // VR 1_4_15
		}

		namespace ItemsPickpocketed
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 54 24 58 E8 ? ? ? ? EB 7B
			inline constexpr REL::Offset GetEventSource(0x0088D5D0);  // VR 1_4_15
		}

		namespace JournalMenu
		{
			// VTable: .?AVJournalMenu@@
			inline constexpr REL::Offset Vtbl(0x0174E278);  // VR 1_4_15
		}

		namespace JumpHandler
		{
			// VTable: .?AUJumpHandler@@
			inline constexpr REL::Offset Vtbl(0x016F2408);  // VR 1_4_15
		}

		namespace LocalMapCamera
		{
			// IndirectSig: E8 ? ? ? ? 90 33 F6 48 89 B3 ? ? ? ? 48 8D 8B ? ? ? ?
			inline constexpr REL::Offset Ctor(0x00205EF0);  // VR 1_4_15
			// DirectSig: 48 8B C4 53 48 81 EC ? ? ? ? 0F 28 05 ? ? ? ? 48 8B D9
			inline constexpr REL::Offset SetNorthRotation(0x002062B0);  // VR 1_4_15
		}

		namespace LookHandler
		{
			// VTable: .?AULookHandler@@
			inline constexpr REL::Offset Vtbl(0x016F2070);  // VR 1_4_15
		}

		namespace LooseFileStream
		{
			// IndirectSig: E8 ? ? ? ? 48 8B F8 EB 02 33 FF 40 F6 C6 02 74 11
			inline constexpr REL::Offset Ctor(0x00C90A40);  // VR 1_4_15
		}

		namespace MagicFavorites
		{
			// 48 C7 05 ? ? ? ? ? ? ? ? 48 8B 5C 24 ? 48 83 C4 30 5F C3 CC 48 89 5C 24 ?
			inline constexpr REL::Offset Singleton(0x02FEB238);  // VR
		}

		namespace MagicItem
		{
			// IndirectSig: E8 ? ? ? ? E8 ? ? ? ? F3 0F 2C C0
			inline constexpr REL::Offset CalculateCost(0x00111FE0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 85 C0 74 0C 48 8B 40 10
			inline constexpr REL::Offset GetCostliestEffectItem(0x00112270);  // VR 1_4_15
		}

		namespace MagicTarget
		{
			// DirectSig: 48 89 5C 24 18 56 48 83 EC 20 48 8B 01 48 8B F2 FF 50 38
			inline constexpr REL::Offset HasMagicEffect(0x00557380);  // VR 1_4_15
		}

		namespace Main
		{
			// 74 04 8B 40 28
			inline constexpr REL::Offset Singleton(0x02F26BF8);  // 1_5_97
		}

		namespace MapMenu
		{
			inline constexpr REL::Offset PlaceMarker(0x0919520);
		}

		namespace MemoryManager
		{
			// DirectSig: 48 89 5C 24 ? 55 57 41 54 41 55 41 57 48 83 EC 30 65 48 8B 04 25 ? ? ? ?
			inline constexpr REL::Offset Allocate(0x00C3D0E0);  // VR 1_4_15
			// DirectSig: 48 85 D2 0F 84 ? ? ? ? 48 89 5C 24 ? 48 89 54 24 ? 57 48 83 EC 20 80 39 00
			inline constexpr REL::Offset Deallocate(0x00C3D3E0);  // VR 1_4_15
			// DirectSig: 40 53 48 83 EC 20 83 3D ? ? ? ? ? 74 1F
			inline constexpr REL::Offset GetSingleton(0x00010D590);  // VR 1_4_15
			// DirectSig: 40 56 57 41 54 41 56 41 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 8B F1 33 ED
			inline constexpr REL::Offset GetThreadScrapHeap(0x00C3C680);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 3B 77 48
			inline constexpr REL::Offset Reallocate(0x00C3D330);  // VR 1_4_15
		}

		namespace MenuControls
		{
			// 48 89 2D ? ? ? ? 48 8D 05 ? ? ? ? 48 89 01 48 8D 05 ? ? ? ? 48 89 41 08 48 8D 59 18
			inline constexpr REL::Offset Singleton(0x02F003F8);  // 1_5_97
		}

		namespace MenuOpenHandler
		{
			// VTable: .?AUMenuOpenHandler@@
			inline constexpr REL::Offset Vtbl(0x0173C970);  // VR 1_4_15
		}

		namespace MessageBoxData
		{
			inline constexpr REL::Offset QueueMessage(0x08d8420);
		}

		namespace MessageDataFactoryManager
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 57 08
			inline constexpr REL::Offset GetSingleton(0x00335CA0);  // VR 1_4_15
		}

		namespace MovementHandler
		{
			// VTable: .?AUMovementHandler@@
			inline constexpr REL::Offset Vtbl(0x016F21C8);  // VR 1_4_15
		}

		namespace NiAVObject
		{
			// IndirectSig: E8 ? ? ? ? 44 88 65 6F
			inline constexpr REL::Offset SetMotionType(0x00DFD160);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? EB 09 48 8B CB E8 ? ? ? ? 90 48 8B 8C 24 ? ? ? ?
			inline constexpr REL::Offset Update(0x00C9BC10);  // VR 1_4_15
		}

		namespace NiCamera
		{
			// DirectSig: 48 83 EC 18 F3 41 0F 10 60 04
			inline constexpr REL::Offset WorldPtToScreenPt3(0x00CAC0E0);  // VR 1_4_15
		}

		namespace NiMemManager
		{
			// 48 89 44 24 30 48 89 05 ? ? ? ?
			inline constexpr REL::Offset Singleton(0x02F77208);  // 1_5_97
		}

		namespace NiNode
		{
			// IndirectSig: E8 ? ? ? ? 48 8B F8 48 8B 0E 48 3B CF
			inline constexpr REL::Offset Ctor(0x00C9CCD0);  // VR 1_4_15
		}

		namespace NiObject
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 44 24 ? 48 89 44 24 ? 48 85 C0
			inline constexpr REL::Offset CreateDeepCopy(0x00C97A60);  // VR 1_4_15
		}

		namespace NiRefObject
		{
			// NiRefObject::virt_dtor + 13
			inline constexpr REL::Offset TotalObjectCount(0x03012520);  // 1_5_97
		}

		namespace NiSkinInstance
		{
			// DirectSig: 40 53 48 83 EC 20 48 8B D9 E8 ? ? ? ? 48 8D 05 ? ? ? ? 48 89 03 48 8D 4B 60
			inline constexpr REL::Offset Ctor(0x00CC5250);  // VR 1_4_15
		}

		namespace PlayerCamera
		{
			// 74 0D 48 83 C0 C7
			inline constexpr REL::Offset Singleton(0x02F8A888);  // VR
			// IndirectSig: E8 ? ? ? ? 48 3B 1D ? ? ? ? 75 1C 48 8B 0D ? ? ? ?
			inline constexpr REL::Offset UpdateThirdPerson(0x00877DB0);  // VR 1_4_15
		}

		namespace PlayerCharacter
		{
			namespace PlayerSkills
			{
				// IndirectSig: E8 ? ? ? ? 48 8B 15 ? ? ? ? 48 81 C2 40 01 00 00
				inline constexpr REL::Offset AdvanceLevel(0x0070D630);  // VR 1_4_15
			}

			// IndirectSig: E8 ? ? ? ? 66 C7 43 18 00 00
			inline constexpr REL::Offset ActivatePickRef(0x006B2C60);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 84 C0 75 08 40 32 F6
			inline constexpr REL::Offset AttemptPickpocket(0x006D58A0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 0F 28 F0 48 85 FF 0F 84 ? ? ? ?
			inline constexpr REL::Offset GetArmorValue(0x0069C2D0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? F3 0F 2C C8 8B C7
			inline constexpr REL::Offset GetDamage(0x0069C650);  // VR 1_4_15
			// DirectSig: 44 8B 81 ? ? ? ? 33 C0 45 85 C0 74 27
			inline constexpr REL::Offset GetNumTints(0x006D8730);  // VR 1_4_15
			// DirectSig: 48 83 EC 38 80 7C 24 70 00
			inline constexpr REL::Offset GetPickpocketChance(0x003CCD90);  // VR 1_4_15
			// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 44 8B 99 ? ? ? ? 45 33 C9
			inline constexpr REL::Offset GetTintMask(0x006D8580);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 44 89 65 67
			inline constexpr REL::Offset PlayPickupEvent(0x006C0640);  // VR 1_4_15
			// E8 ? ? ? ? 48 89 35 ? ? ? ? 48 8B C6
			inline constexpr REL::Offset Singleton(0x02FEB9F0);  // VR
			// IndirectSig: E8 ? ? ? ? 48 8B 05 ? ? ? ? 83 B8 ? ? ? ? ? 0F 95 C0
			inline constexpr REL::Offset StartGrabObject(0x006CC000);  // VR 1_4_15
			// VTable: .?AVPlayerCharacter@@
			inline constexpr REL::Offset Vtbl(0x016E2230);  // VR 1_4_15
		}

		namespace PlayerControls
		{
			// IndirectSig: E8 ? ? ? ? 90 48 89 05 ? ? ? ? 43 89 1C 34
			inline constexpr REL::Offset Ctor(0x0072B900);  // VR 1_4_15
			// 74 0D 48 83 C0 E0 48 89 05 ? ? ? ?
			inline constexpr REL::Offset Singleton(0x02F8AAA8);  // VR
		}

		namespace ProcessLists
		{
			// 4C 8B F9 48 89 0D ? ? ? ?
			inline constexpr REL::Offset Singleton(0x01F831B0);  // VR
			// IndirectSig: E8 ? ? ? ? 48 8B 13 48 8B CB FF 92 ? ? ? ? 33 D2
			inline constexpr REL::Offset StopCombatAndAlarmOnActor(0x00700330);  // VR 1_4_15
		}

		namespace ReadyWeaponHandler
		{
			// VTable: .?AUReadyWeaponHandler@@
			inline constexpr REL::Offset Vtbl(0x016F22A8);  // VR 1_4_15
		}

		namespace REFR_LOCK
		{
			// IndirectSig: E8 ? ? ? ? 83 F8 05 74 35
			inline constexpr REL::Offset GetLockLevel(0x00145380);  // VR 1_4_15
		}

		namespace RunHandler
		{
			// VTable: .?AURunHandler@@
			inline constexpr REL::Offset Vtbl(0x016F23B8);  // VR 1_4_15
		}

		namespace ScrapHeap
		{
			inline constexpr REL::Offset Allocate(0x00C3E320);
			inline constexpr REL::Offset Deallocate(0x00C3E940);
		}

		namespace Script
		{
			// DirectSig: 41 54 41 56 41 57 48 83 EC 40 48 C7 44 24 38 FE FF FF FF 48 89 5C 24 60 48 89 6C 24 68 48 89 74 24 70 48 89 7C 24 78 4D 8B F1
			inline constexpr REL::Offset CompileAndRun(0x002F8AF0);  // VR 1_4_15
		}

		namespace ScriptEventSourceHolder
		{
			// IndirectSig: E8 ? ? ? ? 8B 15 ? ? ? ? 65 48 8B 0C 25 ? ? ? ? 41 B8 ? ? ? ? 48 8B 3C D1
			inline constexpr REL::Offset GetSingleton(0x001964C0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 48 8B 45 D7 48 85 C0 74 1C
			inline constexpr REL::Offset SendActivateEvent(0x002B37E0);  // VR 1_4_15
		}

		namespace SCRIPT_FUNCTION
		{
			// E8 ? ? ? ? 48 8D 1D ? ? ? ? BF ? ? ? ? 0F 1F 44 00 ?
			inline constexpr REL::Offset FirstConsoleCommand(0x01DC6F60);  // 1_5_97
			// 48 8D 1D ? ? ? ? BF ? ? ? ? 0F 1F 00
			inline constexpr REL::Offset FirstScriptCommand(0x01DB8910);  // 1_5_97
		}

		namespace ShoutHandler
		{
			// VTable: .?AUShoutHandler@@
			inline constexpr REL::Offset Vtbl(0x016F2488);  // VR 1_4_15
		}

		namespace Sky
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 40 48
			inline constexpr REL::Offset GetSingleton(0x001876A0);  // VR 1_4_15
		}

		namespace SkyrimVM
		{
			// IndirectSig: E8 ? ? ? ? 84 C0 0F 94 C3 48 8B 4C 24 ? 48 85 C9 74 15
			inline constexpr REL::Offset QueuePostRenderCall(0x0095FD10);  // VR 1_4_15
			// E8 ? ? ? ? 90 48 89 05 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? 48 8B 0D ? ? ? ? E8 ? ? ? ?
			inline constexpr REL::Offset Singleton(0x01F889D8);  // VR 1_4_15
		}

		namespace SneakHandler
		{
			// VTable: .?AUSneakHandler@@
			inline constexpr REL::Offset Vtbl(0x016F2448);  // VR 1_4_15
		}

		namespace SprintHandler
		{
			// VTable: .?AUSprintHandler@@
			inline constexpr REL::Offset Vtbl(0x016F2208);  // VR 1_4_15
		}

		namespace TES
		{
			// 45 33 C9 48 8B 0D ? ? ? ? 48 C7 44 24 28 00 00 00 00
			inline constexpr REL::Offset Singleton(0x02FEB6F8);  // VR
		}

		namespace TESCamera
		{
			// DirectSig: 48 89 5C 24 ? 57 48 83 EC 20 48 8B F9 48 8B DA 48 8B 49 28 48 85 C9 74 06
			inline constexpr REL::Offset SetState(0x00505F60);  // VR 1_4_15
		}

		namespace TESCondition
		{
			namespace Node
			{
				// IndirectSig: E8 ? ? ? ? 44 0F B6 C0 45 84 F6
				inline constexpr REL::Offset Run(0x00455010);  // VR 1_4_15
			}

			// IndirectSig: E8 ? ? ? ? 0F B6 D8 EB 08
			inline constexpr REL::Offset Run(0x004542F0);  // VR 1_4_15
		}

		namespace TESDataHandler
		{
			// IndirectSig: E8 ? ? ? ? 83 3D ? ? ? ? ? 74 13 48 8D 15 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 33 D2 48 8D 0D ? ? ? ? E8 ? ? ? ? 8B 0D ? ? ? ?
			inline constexpr REL::Offset LoadScripts(0x00181B80);  // VR 1_4_15
			// 48 89 05 ? ? ? ? 49 8B D6
			inline constexpr REL::Offset Singleton(0x01F82AD8);  // VR
		}

		namespace TESDescription
		{
			// IndirectSig: E8 ? ? ? ? 44 0F 11 4C 24 ?
			inline constexpr REL::Offset GetDescription(0x001A01B0);  // VR 1_4_15
		}

		namespace TESFile
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 07 EB CA
			inline constexpr REL::Offset Duplicate(0x0018E210);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? EB E0
			inline constexpr REL::Offset GetCurrentSubRecordType(0x0018D6F0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 3C 5E
			inline constexpr REL::Offset GetFormType(0x0018D2A0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 44 8B DB
			inline constexpr REL::Offset ReadData(0x0018D7F0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 33 FF 8B B3 88 02 00 00
			inline constexpr REL::Offset Seek(0x0018D330);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 49 83 C6 28
			inline constexpr REL::Offset SeekNextSubrecord(0x0018D740);  // VR 1_4_15
		}

		namespace TESHavokUtilities
		{
			// IndirectSig: E8 ? ? ? ? 48 3B 05 ? ? ? ? 75 0C
			inline constexpr REL::Offset FindCollidableRef(0x003B4940);  // VR 1_4_15
		}

		namespace TESNPC
		{
			// IndirectSig: E8 ? ? ? ? EB 07 8B D5
			inline constexpr REL::Offset ChangeHeadPart(0x00375550);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B CD 48 8B D8 E8 ? ? ? ? 8B F0
			inline constexpr REL::Offset GetBaseOverlays(0x00378490);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 8B F0 B8 ? ? ? ? 85 F6
			inline constexpr REL::Offset GetNumBaseOverlays(0x00378520);  // VR 1_4_15
			// DirectSig: 48 89 5C 24 ? 57 48 83 EC 20 83 79 14 07
			inline constexpr REL::Offset HasOverlays(0x00378380);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 63 03 48 6B C8 78 48 8B 43 08 4C 8B 7C 01 ?
			inline constexpr REL::Offset SetSkinFromTint(0x0036FD80);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 0F B6 05 ? ? ? ? 84 C0
			inline constexpr REL::Offset UpdateNeck(0x0036FFD0);  // VR 1_4_15
			// VTable: .?AVTESNPC@@
			inline constexpr REL::Offset Vtbl(0x01616E60);  // VR 1_4_15
		}

		namespace TESObjectACTI
		{
			// VTable: .?AVTESObjectACTI@@
			inline constexpr REL::Offset Vtbl(0x015CF2C0);  // VR 1_4_15
		}

		namespace TESObjectCONT
		{
			// VTable: .?AVTESObjectCONT@@
			inline constexpr REL::Offset Vtbl(0x015D1500);  // VR 1_4_15
		}

		namespace TESObjectREFR
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 4E 40 48 8B 01 8B 55 77
			inline constexpr REL::Offset InitChildActivates(0x002BA430);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 4C 8B C8 89 74 24 20 4C 8B C3 48 8D 15 ? ? ? ? 48 8B CD E8 ? ? ? ? B0 01
			inline constexpr REL::Offset GetDisplayFullName(0x002A78F0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? FF 40 18
			inline constexpr REL::Offset GetLock(0x002B8C30);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 3B D8 75 08
			inline constexpr REL::Offset GetOwner(0x002B7DE0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 41 8B CE 3B C1
			inline constexpr REL::Offset GetStealValue(0x001E9C20);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B F8 48 89 85 ? ? ? ? 48 85 C0 74 04 F0 FF 40 28 84 DB
			inline constexpr REL::Offset FindReferenceFor3D(0x002A5CF0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 4D 85 FF 75 26
			inline constexpr REL::Offset InitInventoryIfRequired(0x001E98B0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B 1D ? ? ? ? 48 8B CF 83 FE 01
			inline constexpr REL::Offset IsCrimeToActivate(0x002ABA40);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? E8 ? ? ? ? 4D 89 26
			inline constexpr REL::Offset MoveTo(0x009E90E0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 41 B4 01 EB 1B
			inline constexpr REL::Offset PlayAnimation(0x00199B60);  // VR 1_4_15
		}

		namespace TESQuest
		{
			// DirectSig: 48 89 5C 24 ? 56 48 83 EC 20 C6 02 00
			inline constexpr REL::Offset EnsureQuestStarted(0x003802B0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B 54 24 ? 0F B6 8A ? ? ? ?
			inline constexpr REL::Offset ResetQuest(0x00380830);  // VR 1_4_15
		}

		namespace ThirdPersonState
		{
			// VTable: .?AVThirdPersonState@@
			inline constexpr REL::Offset Vtbl(0x016A57A0);  // VR 1_4_15
		}

		namespace TogglePOVHandler
		{
			// VTable: .?AUTogglePOVHandler@@
			inline constexpr REL::Offset Vtbl(0x016F24C8);  // VR 1_4_15
		}

		namespace ToggleRunHandler
		{
			// VTable: .?AUToggleRunHandler@@
			inline constexpr REL::Offset Vtbl(0x016F2378);  // VR 1_4_15
		}

		namespace UI
		{
			// 48 89 0D ? ? ? ? 48 83 C1 08 E8 ? ? ? ? 90 48 8D 4F 60
			inline constexpr REL::Offset Singleton(0x01F83200);  // VR
		}

		namespace UIBlurManager
		{
			// IndirectSig: 0F B7 41 18 66 85 C0
			inline constexpr REL::Offset DecrementBlurCount(0x00902C50);  // VR 1_4_15
			// IndirectSig: 40 53 48 83 EC 20 66 83 79 ? ? 48 8B D9 75 1E
			inline constexpr REL::Offset IncrementBlurCount(0x00902C10);  // VR 1_4_15
			// 48 89 0D ? ? ? ? 48 8D 05 ? ? ? ? 48 89 03 66 89 4B 18
			inline constexpr REL::Offset Singleton(0x02F26780);  // 1_5_97
		}

		namespace UIMessageQueue
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 05 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 80 B8 ? ? ? ? ? 0F 85 ? ? ? ? 80 B8 ? ? ? ? ?
			inline constexpr REL::Offset AddMessage(0x00175A10);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 4C 8B F0 48 85 C0 0F 84 ? ? ? ? 48 89 75 D8
			inline constexpr REL::Offset CreateUIMessageData(0x00F1FCA0);  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B 0D ? ? ? ? E8 ? ? ? ? 41 C6 86 ? ? ? ? ?
			inline constexpr REL::Offset ProcessCommands(0x00F1FBC0);  // VR 1_4_15
			// 48 89 0D ? ? ? ? 33 C9 89 4B 10
			inline constexpr REL::Offset Singleton(0x01F850F8);  // VR
		}

		namespace UserEvents
		{
			// E8 ? ? ? ? 90 48 89 05 ? ? ? ? 48 8D 4F 60
			inline constexpr REL::Offset Singleton(0x02FEA140);  // VR
		}

		// IndirectSig: E8 ? ? ? ? 8B 45 80 41 89 44 24 ?
		inline constexpr REL::Offset CreateRefHandle(0x001428A0);  // VR 1_4_15
		// IndirectSig: E8 ? ? ? ? 83 FE 0C
		inline constexpr REL::Offset DebugNotification(0x00908170);  // VR 1_4_15
		// IndirectSig: E8 ? ? ? ? 90 48 8B BC 24 ? ? ? ? 48 85 FF 74 20 8B 47 10
		inline constexpr REL::Offset LookupReferenceByHandle(0x00143180);  // VR 1_4_15
		// IndirectSig: E8 ? ? ? ? 44 38 7E 50
		inline constexpr REL::Offset PlaySound(0x0090B1D0);  // VR 1_4_15
		// IndirectSig: E8 ? ? ? ? 48 8B F5
		inline constexpr REL::Offset RTDynamicCast(0x0138BABA);  // VR 1_4_15
		//
		inline constexpr REL::Offset TlsIndex(0x03497408);  // 1_5_97
	}
}
