#pragma once

namespace RE
{
	namespace Offset
	{
		namespace ActivateHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F22E8);
		}

		namespace ActiveEffect
		{
			inline constexpr REL::Offset Dispel(0x00541100);
		}

		namespace Actor
		{
			inline constexpr REL::Offset AddSpell(0x00638430);
			inline constexpr REL::Offset RemoveSpell(0x006385F0);
			inline constexpr REL::Offset DispelWornItemEnchantments(0x0055CCB0);
			inline constexpr REL::Offset DoReset3D(0x0069C710);
			inline constexpr REL::Offset EvaluatePackage(0x005E3990);
			inline constexpr REL::Offset GetGhost(0x005DAAE0);
			inline constexpr REL::Offset GetHostileToActor(0x005F0560);
			inline constexpr REL::Offset GetLevel(0x005DE910);
			inline constexpr REL::Offset HasPerk(0x006025A0);
			inline constexpr REL::Offset InterruptCast(0x0063AB50);
			inline constexpr REL::Offset IsRunning(0x005D9770);
			inline constexpr REL::Offset RequestDetectionLevel(0x00605190);
			inline constexpr REL::Offset StealAlarm(0x005E5DC0);
			inline constexpr REL::Offset SwitchRace(0x00610000);
			inline constexpr REL::Offset UpdateArmorAbility(0x0063A230);
			inline constexpr REL::Offset UpdateWeaponAbility(0x0063A2A0);
			inline constexpr REL::Offset Vtbl(0x016CE888);
		}

		namespace ActorEquipManager
		{
			inline constexpr REL::Offset EquipObject(0x00640A90);
			inline constexpr REL::Offset EquipShout(0x006556848);
			inline constexpr REL::Offset EquipSpell(0x006556624);
			inline constexpr REL::Offset Singleton(0x02F896D8);
			inline constexpr REL::Offset UnequipObject(0x006411A0);
		}

		namespace ActorValueOwner
		{
			inline constexpr REL::Offset GetClampedActorValue(0x003F4DA0);
		}

		namespace AIProcess
		{
			inline constexpr REL::Offset SetBaseScale(0x00665BD0);
			inline constexpr REL::Offset Update3DModel(0x0065A140);
		}

		namespace AttackBlockHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F2258);
		}

		namespace AutoMoveHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F2338);
		}

		namespace BGSDefaultObjectManager
		{
			inline constexpr REL::Offset GetSingleton(0x0001077C0);
		}

		namespace BGSFootstepManager
		{
			inline constexpr REL::Offset Singleton(0x02FEBC50);
		}

		namespace BGSListForm
		{
			inline constexpr REL::Offset AddForm(0x002D6B40);
		}

		namespace BGSSaveLoadManager
		{
			inline constexpr REL::Offset Save(0x0058E310);
			inline constexpr REL::Offset Singleton(0x02FEB248);
			inline constexpr REL::Offset Load(0x0058E920);
		}

		namespace BGSStoryTeller
		{
			inline constexpr REL::Offset BeginShutDownQuest(0x004E8240);
			inline constexpr REL::Offset BeginStartUpQuest(0x004E8120);
			inline constexpr REL::Offset Singleton(0x01F889E0);
		}

		namespace BipedAnim
		{
			inline constexpr REL::Offset Dtor(0x001D6200);
			inline constexpr REL::Offset RemoveAllParts(0x001D6530);
		}

		namespace BSAudioManager
		{
			inline constexpr REL::Offset GetSingleton(0x00C29430);
			inline constexpr REL::Offset BuildSoundDataFromDescriptor(0x00C29F60);
		}

		namespace BSFixedString
		{
			inline constexpr REL::Offset Ctor8(0x00C6DB20);
			inline constexpr REL::Offset Ctor_Copy(0x00C6DBB0);
			inline constexpr REL::Offset Set_CStr(0x00C6DC90);
			inline constexpr REL::Offset Set_Copy(0x00C6DD50);
			inline constexpr REL::Offset Dtor8(0x00C6DC70);
			inline constexpr REL::Offset Ctor16(0x00C6E440);
			inline constexpr REL::Offset Dtor16(0x00C6E550);
		}

		namespace BSGraphics
		{
			namespace State
			{
				inline constexpr REL::Offset Singleton(0x03186C10);
			}
		}

		namespace BSInputDeviceManager
		{
			inline constexpr REL::Offset Singleton(0x02FEA520);
		}

		namespace BSLightingShaderMaterialBase
		{
			inline constexpr REL::Offset CreateMaterial(0x0130EAD0);
		}

		namespace BSReadWriteLock
		{
			inline constexpr REL::Offset LockForRead(0x00C42150);
			inline constexpr REL::Offset LockForWrite(0x00C421D0);
			inline constexpr REL::Offset UnlockForRead(0x00C42410);
			inline constexpr REL::Offset UnlockForWrite(0x00C42420);
		}

		namespace BSResourceNiBinaryStream
		{
			inline constexpr REL::Offset Ctor(0x00CBC490);
			inline constexpr REL::Offset Dtor(0x00CBC770);
			inline constexpr REL::Offset Seek(0x00CBC8C0);
			inline constexpr REL::Offset SetEndianSwap(0x00CBC9B0);
		}

		namespace BSScaleformManager
		{
			inline constexpr REL::Offset LoadMovie(0x00F2B480);
			inline constexpr REL::Offset Singleton(0x02FEA518);
		}

		namespace BSScaleformTranslator
		{
			inline constexpr REL::Offset Vtbl(0x01866FA0);
		}

		namespace BSScript
		{
			namespace Object
			{
				inline constexpr REL::Offset GetHandle(0x0126BBD0);
				inline constexpr REL::Offset IncRef(0x0126C810);
				inline constexpr REL::Offset DecRef(0x0126C8C0);
				inline constexpr REL::Offset Dtor(0x0126BB20);
			}

			namespace ObjectTypeInfo
			{
				inline constexpr REL::Offset ReleaseData(0x01270B80);
			}

			namespace ObjectBindPolicy
			{
				inline constexpr REL::Offset BindObject(0x01265F80);
			}

			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					inline constexpr REL::Offset Call(0x0129DD90);
				}
			}

			namespace Stack
			{
				inline constexpr REL::Offset GetStackFrameVariable(0x0129A720);
				inline constexpr REL::Offset Dtor(0x0129A210);
			}
		}

		namespace BSSoundHandle
		{
			inline constexpr REL::Offset IsValid(0x00C28540);
			inline constexpr REL::Offset Play(0x00C283E0);
			inline constexpr REL::Offset SetObjectToFollow(0x00C289C0);
			inline constexpr REL::Offset SetPosition(0x00C287D0);
			inline constexpr REL::Offset Stop(0x00C284B0);
		}

		namespace BSString
		{
			inline constexpr REL::Offset Set_CStr(0x00010A440);
		}

		namespace BSStringPool
		{
			inline constexpr REL::Offset Release8(0x00C6EDB0);
			inline constexpr REL::Offset Release16(0x00C6EF20);
		}

		namespace BSUntypedPointerHandle
		{
			inline constexpr REL::Offset NullHandle(0x01F8319C);
		}

		namespace BucketTable
		{
			inline constexpr REL::Offset GetSingleton(0x00C6F400);
		}

		namespace BSWin32SaveDataSystemUtility
		{
			inline constexpr REL::Offset GetSingleton(0x0137C200);
		}

		namespace Calendar
		{
			inline constexpr REL::Offset Singleton(0x01F85108);
		}

		namespace ChestsLooted
		{
			inline constexpr REL::Offset GetEventSource(0x0088D4E0);
		}

		namespace Console
		{
			inline constexpr REL::Offset SelectedRef(0x030115FC);
			inline constexpr REL::Offset SetSelectedRef(0x008864D0);
		}

		namespace ConsoleLog
		{
			inline constexpr REL::Offset Singleton(0x02FC4FE0);
			inline constexpr REL::Offset VPrint(0x00886DF0);
		}

		namespace ContainerMenu
		{
			inline constexpr REL::Offset GetContainerMode(0x03011720);
			inline constexpr REL::Offset GetTargetRefHandle(0x030117E8);
		}

		namespace ControlMap
		{
			inline constexpr REL::Offset Singleton(0x02F8A7A0);
		}

		namespace CRC32Calculator
		{
			inline constexpr REL::Offset SizeOf32(0x00C41370);
			inline constexpr REL::Offset SizeOf64(0x00C413F0);
			inline constexpr REL::Offset SizeOfSize(0x00C41310);
		}

		namespace DialogueItem
		{
			inline constexpr REL::Offset Ctor(0x00572FD0);
		}

		namespace ExtraAliasInstanceArray
		{
			inline constexpr REL::Offset Vtbl(0x015A3CF0);
		}

		namespace ExtraAshPileRef
		{
			inline constexpr REL::Offset Vtbl(0x015A3630);
		}

		namespace ExtraCannotWear
		{
			inline constexpr REL::Offset Vtbl(0x015A3390);
		}

		namespace ExtraCanTalkToPlayer
		{
			inline constexpr REL::Offset Vtbl(0x015A3A90);
		}

		namespace ExtraCharge
		{
			inline constexpr REL::Offset Vtbl(0x015A3410);
		}

		namespace ExtraContainerChanges
		{
			inline constexpr REL::Offset Vtbl(0x015A65D0);
		}

		namespace ExtraCount
		{
			inline constexpr REL::Offset Vtbl(0x015A3330);
		}

		namespace ExtraDataList
		{
			inline constexpr REL::Offset Add(0x00142140);
			inline constexpr REL::Offset SetExtraFlags(0x00136360);
			inline constexpr REL::Offset SetInventoryChanges(0x0011FBA0);
		}

		namespace ExtraEnchantment
		{
			inline constexpr REL::Offset Vtbl(0x015A37D0);
		}

		namespace ExtraForcedTarget
		{
			inline constexpr REL::Offset Vtbl(0x015A3EB0);
		}

		namespace ExtraHealth
		{
			inline constexpr REL::Offset Vtbl(0x015A33B0);
		}

		namespace ExtraHotkey
		{
			inline constexpr REL::Offset Vtbl(0x015A3470);
		}

		namespace ExtraLightData
		{
			inline constexpr REL::Offset Vtbl(0x015A3D50);
		}

		namespace ExtraOwnership
		{
			inline constexpr REL::Offset Vtbl(0x015A32D0);
		}

		namespace ExtraPoison
		{
			inline constexpr REL::Offset Vtbl(0x015A37B0);
		}

		namespace ExtraRank
		{
			inline constexpr REL::Offset Vtbl(0x015A3310);
		}

		namespace ExtraReferenceHandle
		{
			inline constexpr REL::Offset Vtbl(0x015A34B0);
		}

		namespace ExtraSoul
		{
			inline constexpr REL::Offset Vtbl(0x015A6650);
		}

		namespace ExtraTextDisplayData
		{
			inline constexpr REL::Offset GenerateName(0x0014D130);
			inline constexpr REL::Offset Vtbl(0x015A3E30);
		}

		namespace ExtraUniqueID
		{
			inline constexpr REL::Offset Vtbl(0x015A3EF0);
		}

		namespace FavoritesHandler
		{
			inline constexpr REL::Offset Vtbl(0x0173C9C0);
		}

		namespace FavoritesMenu
		{
			inline constexpr REL::Offset Vtbl(0x01734F50);
		}

		namespace FirstPersonState
		{
			inline constexpr REL::Offset Vtbl(0x0172CEB0);
		}

		namespace GameSettingCollection
		{
			inline constexpr REL::Offset Singleton(0x02F8A780);
		}

		namespace GFxLoader
		{
			inline constexpr REL::Offset CreateMovie(0x00F38CA0);
		}

		namespace GFxMovieView
		{
			inline constexpr REL::Offset InvokeNoReturn(0x00F30F20);
		}

		namespace GFxValue
		{
			namespace ObjectInterface
			{
				inline constexpr REL::Offset AttachMovie(0x00F24EF0);
				inline constexpr REL::Offset DeleteMember(0x00F25FE0);
				inline constexpr REL::Offset GetArraySize(0x00F26720);
				inline constexpr REL::Offset GetDisplayInfo(0x00F26770);
				inline constexpr REL::Offset GetElement(0x00F26A80);
				inline constexpr REL::Offset GetMember(0x00F26CA0);
				inline constexpr REL::Offset GotoAndPlay(0x00F270C0);
				inline constexpr REL::Offset HasMember(0x00F27170);
				inline constexpr REL::Offset Invoke(0x00F273B0);
				inline constexpr REL::Offset ObjectAddRef(0x00F27BD0);
				inline constexpr REL::Offset ObjectRelease(0x00F27C30);
				inline constexpr REL::Offset PushBack(0x00F27E50);
				inline constexpr REL::Offset RemoveElements(0x00F28210);
				inline constexpr REL::Offset SetArraySize(0x00F28870);
				inline constexpr REL::Offset SetDisplayInfo(0x00F28900);
				inline constexpr REL::Offset SetElement(0x00F294B0);
				inline constexpr REL::Offset SetMember(0x00F296F0);
				inline constexpr REL::Offset SetText(0x00F29840);
			}
		}

		namespace GlobalLookupInfo
		{
			inline constexpr REL::Offset Singleton(0x01F88B10);
		}

		namespace GMemory
		{
			inline constexpr REL::Offset GlobalHeap(0x0318CE40);
		}

		namespace GString
		{
			inline constexpr REL::Offset Ctor(0x00F2DA40);
		}

		namespace hkContainerHeapAllocator
		{
			inline constexpr REL::Offset Singleton(0x01EB59C8);
		}

		namespace hkReferencedObject
		{
			inline constexpr REL::Offset AddReference(0x00A01280);
			inline constexpr REL::Offset RemoveReference(0x00A01340);
		}

		namespace IFormFactory
		{
			inline constexpr REL::Offset FormFactories(0x01F88B40);
			inline constexpr REL::Offset FormFactoriesInitialized(0x01F88B13);
		}

		namespace INIPrefSettingCollection
		{
			inline constexpr REL::Offset Singleton(0x030C3B18);
		}

		namespace INISettingCollection
		{
			inline constexpr REL::Offset Singleton(0x03175FE0);
		}

		namespace InterfaceStrings
		{
			inline constexpr REL::Offset Singleton(0x01F85100);
		}

		namespace Inventory
		{
			inline constexpr REL::Offset GetEventSource(0x001FFE10);
		}

		namespace InventoryChanges
		{
			inline constexpr REL::Offset Ctor(0x001E9DA0);
			inline constexpr REL::Offset Dtor(0x001E9E90);
			inline constexpr REL::Offset GenerateLeveledListChanges(0x001F1470);
			// IndirectSig: E8 ? ? ? ? 44 0F B7 F8
			//inline constexpr REL::Offset GetNextUniqueID(0x001ECD33);  // 1_5_97
			inline constexpr REL::Offset SendContainerChangedEvent(0x001FD990);
			inline constexpr REL::Offset SetUniqueID(0x001FD7D0);
			inline constexpr REL::Offset TransferItemUID(0x001FD990);
		}

		namespace InventoryEntryData
		{
			inline constexpr REL::Offset GetValue(0x001E7280);
			inline constexpr REL::Offset IsOwnedBy(0x001E8130);
		}

		namespace ItemCrafted
		{
			inline constexpr REL::Offset GetEventSource(0x0089BE30);
		}

		namespace ItemList
		{
			inline constexpr REL::Offset Update(0x00880E10);
		}

		namespace ItemsPickpocketed
		{
			inline constexpr REL::Offset GetEventSource(0x0088D5D0);
		}

		namespace JournalMenu
		{
			inline constexpr REL::Offset Vtbl(0x0174E278);
		}

		namespace JumpHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F2408);
		}

		namespace LocalMapCamera
		{
			inline constexpr REL::Offset Ctor(0x00205EF0);
			inline constexpr REL::Offset SetNorthRotation(0x002062B0);
		}

		namespace LookHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F2070);
		}

		namespace LooseFileStream
		{
			inline constexpr REL::Offset Ctor(0x00C90A40);
		}

		namespace MagicFavorites
		{
			inline constexpr REL::Offset Singleton(0x02FEB238);
		}

		namespace MagicItem
		{
			inline constexpr REL::Offset CalculateCost(0x00111FE0);
			inline constexpr REL::Offset GetCostliestEffectItem(0x00112270);
		}

		namespace MagicTarget
		{
			inline constexpr REL::Offset HasMagicEffect(0x00557380);
		}

		namespace Main
		{
			inline constexpr REL::Offset Singleton(0x02FEB7A0);
		}

		namespace MemoryManager
		{
			inline constexpr REL::Offset Allocate(0x00C3D0E0);
			inline constexpr REL::Offset Deallocate(0x00C3D3E0);
			inline constexpr REL::Offset GetSingleton(0x00010D590);
			inline constexpr REL::Offset GetThreadScrapHeap(0x00C3C680);
			inline constexpr REL::Offset Reallocate(0x00C3D330);
		}

		namespace MenuControls
		{
			inline constexpr REL::Offset Singleton(0x02FC52E8);
		}

		namespace MenuOpenHandler
		{
			inline constexpr REL::Offset Vtbl(0x0173C970);
		}

		namespace MessageDataFactoryManager
		{
			inline constexpr REL::Offset GetSingleton(0x00335CA0);
		}

		namespace MovementHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F21C8);
		}

		namespace NiAVObject
		{
			inline constexpr REL::Offset SetMotionType(0x00DFD160);
			inline constexpr REL::Offset Update(0x00C9BC10);
		}

		namespace NiCamera
		{
			inline constexpr REL::Offset WorldPtToScreenPt3(0x00CAC0E0);
		}

		namespace NiMemManager
		{
			inline constexpr REL::Offset Singleton(0x030CF888);
		}

		namespace NiNode
		{
			inline constexpr REL::Offset Ctor(0x00C9CCD0);
		}

		namespace NiObject
		{
			inline constexpr REL::Offset CreateDeepCopy(0x00C97A60);
		}

		namespace NiRefObject
		{
			inline constexpr REL::Offset TotalObjectCount(0x0316AD20);
		}

		namespace NiSkinInstance
		{
			inline constexpr REL::Offset Ctor(0x00CC5250);
		}

		namespace PlayerCamera
		{
			inline constexpr REL::Offset Singleton(0x02F8A888);
			inline constexpr REL::Offset UpdateThirdPerson(0x00877DB0);
		}

		namespace PlayerCharacter
		{
			namespace PlayerSkills
			{
				inline constexpr REL::Offset AdvanceLevel(0x0070D630);
			}

			inline constexpr REL::Offset ActivatePickRef(0x006B2C60);
			inline constexpr REL::Offset AttemptPickpocket(0x006D58A0);
			inline constexpr REL::Offset GetArmorValue(0x0069C2D0);
			inline constexpr REL::Offset GetDamage(0x0069C650);
			inline constexpr REL::Offset GetNumTints(0x006D8730);
			inline constexpr REL::Offset GetPickpocketChance(0x003CCD90);
			inline constexpr REL::Offset GetTintMask(0x006D8580);
			inline constexpr REL::Offset PlayPickupEvent(0x006C0640);
			inline constexpr REL::Offset Singleton(0x02FEB9F0);
			inline constexpr REL::Offset StartGrabObject(0x006CC000);
			inline constexpr REL::Offset Vtbl(0x016E2230);
		}

		namespace PlayerControls
		{
			inline constexpr REL::Offset Ctor(0x0072B900);
			inline constexpr REL::Offset Singleton(0x02F8AAA8);
		}

		namespace ProcessLists
		{
			inline constexpr REL::Offset Singleton(0x01F831B0);
			inline constexpr REL::Offset StopCombatAndAlarmOnActor(0x00700330);
		}

		namespace ReadyWeaponHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F22A8);
		}

		namespace REFR_LOCK
		{
			inline constexpr REL::Offset GetLockLevel(0x00145380);
		}

		namespace RunHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F23B8);
		}

		namespace ScrapHeap
		{
			inline constexpr REL::Offset Allocate(0x00C3E320);
			inline constexpr REL::Offset Deallocate(0x00C3E940);
		}

		namespace Script
		{
			inline constexpr REL::Offset CompileAndRun(0x002F8AF0);
		}

		namespace ScriptEventSourceHolder
		{
			inline constexpr REL::Offset GetSingleton(0x001964C0);
			inline constexpr REL::Offset SendActivateEvent(0x002B37E0);
		}

		namespace SCRIPT_FUNCTION
		{
			inline constexpr REL::Offset FirstConsoleCommand(0x01E83FB0);
			inline constexpr REL::Offset FirstScriptCommand(0x01E75A00);
		}

		namespace ShoutHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F2488);
		}

		namespace Sky
		{
			inline constexpr REL::Offset GetSingleton(0x001876A0);
		}

		namespace SkyrimVM
		{
			inline constexpr REL::Offset QueuePostRenderCall(0x0095FD10);
			inline constexpr REL::Offset Singleton(0x01F889D8);
		}

		namespace SneakHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F2448);
		}

		namespace SprintHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F2208);
		}

		namespace TaskQueueInterface
		{
			inline constexpr REL::Offset Singleton(0x02FFD778);
		}

		namespace TES
		{
			inline constexpr REL::Offset Singleton(0x02FEB6F8);
		}

		namespace TESCamera
		{
			inline constexpr REL::Offset SetState(0x00505F60);
		}

		namespace TESCondition
		{
			namespace Node
			{
				inline constexpr REL::Offset Run(0x00455010);
			}

			inline constexpr REL::Offset Run(0x004542F0);
		}

		namespace TESDataHandler
		{
			inline constexpr REL::Offset LoadScripts(0x00181B80);
			inline constexpr REL::Offset Singleton(0x01F82AD8);
		}

		namespace TESDescription
		{
			inline constexpr REL::Offset GetDescription(0x001A01B0);
		}

		namespace TESFile
		{
			inline constexpr REL::Offset Duplicate(0x0018E210);
			inline constexpr REL::Offset GetCurrentSubRecordType(0x0018D6F0);
			inline constexpr REL::Offset GetFormType(0x0018D2A0);
			inline constexpr REL::Offset ReadData(0x0018D7F0);
			inline constexpr REL::Offset Seek(0x0018D330);
			inline constexpr REL::Offset SeekNextSubrecord(0x0018D740);
		}

		namespace TESForm
		{
			inline constexpr REL::Offset AddCompileIndex(0x001A5510);
			inline constexpr REL::Offset AllForms(0x01F88B18);
			inline constexpr REL::Offset AllFormsMapLock(0x01F88FB0);
			inline constexpr REL::Offset AllFormsByEditorID(0x01F88B20);
			inline constexpr REL::Offset AllFormsEditorIDMapLock(0x01F88FB8);
		}

		namespace TESHavokUtilities
		{
			inline constexpr REL::Offset FindCollidableRef(0x003B4940);
		}

		namespace TESNPC
		{
			inline constexpr REL::Offset ChangeHeadPart(0x00375550);
			inline constexpr REL::Offset GetBaseOverlays(0x00378490);
			inline constexpr REL::Offset GetNumBaseOverlays(0x00378520);
			inline constexpr REL::Offset HasOverlays(0x00378380);
			inline constexpr REL::Offset SetSkinFromTint(0x0036FD80);
			inline constexpr REL::Offset UpdateNeck(0x0036FFD0);
			inline constexpr REL::Offset Vtbl(0x01616E60);
		}

		namespace TESObjectACTI
		{
			inline constexpr REL::Offset Vtbl(0x015CF2C0);
		}

		namespace TESObjectCONT
		{
			inline constexpr REL::Offset Vtbl(0x015D1500);
		}

		namespace TESObjectREFR
		{
			inline constexpr REL::Offset InitChildActivates(0x002BA430);
			inline constexpr REL::Offset GetDisplayFullName(0x002A78F0);
			inline constexpr REL::Offset GetLock(0x002B8C30);
			inline constexpr REL::Offset GetOwner(0x002B7DE0);
			inline constexpr REL::Offset GetStealValue(0x001E9C20);
			inline constexpr REL::Offset FindReferenceFor3D(0x002A5CF0);
			inline constexpr REL::Offset InitInventoryIfRequired(0x001E98B0);
			inline constexpr REL::Offset IsCrimeToActivate(0x002ABA40);
			inline constexpr REL::Offset MoveTo(0x009E90E0);
			inline constexpr REL::Offset PlayAnimation(0x00199B60);
		}

		namespace TESQuest
		{
			inline constexpr REL::Offset EnsureQuestStarted(0x003802B0);
			inline constexpr REL::Offset ResetQuest(0x00380830);
		}

		namespace ThirdPersonState
		{
			inline constexpr REL::Offset Vtbl(0x016A57A0);
		}

		namespace TogglePOVHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F24C8);
		}

		namespace ToggleRunHandler
		{
			inline constexpr REL::Offset Vtbl(0x016F2378);
		}

		namespace UI
		{
			inline constexpr REL::Offset Singleton(0x01F83200);
		}

		namespace UIBlurManager
		{
			inline constexpr REL::Offset DecrementBlurCount(0x00902C50);
			inline constexpr REL::Offset IncrementBlurCount(0x00902C10);
			inline constexpr REL::Offset Singleton(0x02FEB288);
		}

		namespace UIMessageQueue
		{
			inline constexpr REL::Offset AddMessage(0x00175A10);
			inline constexpr REL::Offset CreateUIMessageData(0x00F1FCA0);
			inline constexpr REL::Offset ProcessCommands(0x00F1FBC0);
			inline constexpr REL::Offset Singleton(0x01F850F8);
		}

		namespace UserEvents
		{
			inline constexpr REL::Offset Singleton(0x02FEA140);
		}

		inline constexpr REL::Offset CreateRefHandle(0x001428A0);
		inline constexpr REL::Offset DebugNotification(0x00908170);
		inline constexpr REL::Offset LookupReferenceByHandle(0x00143180);
		inline constexpr REL::Offset PlaySound(0x0090B1D0);
		inline constexpr REL::Offset RTDynamicCast(0x0138BABA);
		inline constexpr REL::Offset TlsIndex(0x036F2F58);
	}
}
