#pragma once

#include "REL/Relocation.h"

namespace RE
{
	namespace Offset
	{
		namespace BGSDefaultObjectManager
		{
			inline constexpr REL::Offset GetSingleton(0x00182100);
		}

		namespace BSFixedString
		{
			inline constexpr REL::Offset Ctor8(0x00C4E920);
			inline constexpr REL::Offset Ctor16(0x00C4F2E0);
		}

		namespace BSGraphics
		{
			namespace State
			{
				inline constexpr REL::Offset Singleton(0x030C6D90);
			}
		}

		namespace BSInputDeviceManager
		{
			inline constexpr REL::Offset Singleton(0x02FBFD88);
		}

		namespace BSPointerHandleManagerInterface
		{
			inline constexpr REL::Offset GetHandle(0x001FA210);
			inline constexpr REL::Offset GetSmartPointer(0x00139160);
		}

		namespace BSReadWriteLock
		{
			inline constexpr REL::Offset LockForRead(0x00C2BEF0);
			inline constexpr REL::Offset LockForWrite(0x00C2BF70);
			inline constexpr REL::Offset UnlockForRead(0x00C2C1B0);
			inline constexpr REL::Offset UnlockForWrite(0x00C2C1C0);
		}

		namespace BSScaleformManager
		{
			inline constexpr REL::Offset LoadMovie(0x00F10E00);
			inline constexpr REL::Offset Singleton(0x02FBFD80);
			//inline constexpr REL::Offset FileExists;
		}

		namespace BSScript
		{
			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					inline constexpr REL::Offset Call(0x01379740);
				}
			}

			namespace Object
			{
				inline constexpr REL::Offset GetHandle(0x0135DC30);
				inline constexpr REL::Offset IncRef(0x0135E890);
				inline constexpr REL::Offset DecRef(0x0135E940);
				inline constexpr REL::Offset Dtor(0x0135DB80);
			}

			namespace ObjectBindPolicy
			{
				inline constexpr REL::Offset BindObject(0x01359520);
			}

			namespace Stack
			{
				inline constexpr REL::Offset GetStackFrameVariable(0x0136E240);
				inline constexpr REL::Offset Dtor(0x0136DD30);
			}
		}

		namespace BSResourceNiBinaryStream
		{
			inline constexpr REL::Offset Ctor(0x00C9E760);
			inline constexpr REL::Offset Dtor(0x00C9EA40);
			inline constexpr REL::Offset Seek(0x00C9EB90);
			inline constexpr REL::Offset SetEndianSwap(0x00C9EC60);
		}

		namespace BSStringPool
		{
			inline constexpr REL::Offset Release8(0x00C4FCF0);
			inline constexpr REL::Offset Release16(0x00C4FF00);
		}

		namespace ExtraDataList
		{
			//inline constexpr REL::Offset Add;
			//inline constexpr REL::Offset SetExtraFlags;
			//inline constexpr REL::Offset SetInventoryChanges;
		}

		namespace ExtraOwnership
		{
			//inline constexpr REL::Offset Vtbl;
		}

		namespace ExtraReferenceHandle
		{
			//inline constexpr REL::Offset Vtbl;
		}

		namespace ExtraTextDisplayData
		{
			//inline constexpr REL::Offset Vtbl;
			//inline constexpr REL::Offset GetDisplayName;
		}

		namespace GFxLoader
		{
			inline constexpr REL::Offset CreateMovie(0x00F95DB0);
		}

		namespace GFxMovieView
		{
			inline constexpr REL::Offset InvokeNoReturn(0x00F1F800);
		}

		namespace GFxValue
		{
			namespace ObjectInterface
			{
				//inline constexpr REL::Offset AttachMovie;
				//inline constexpr REL::Offset DeleteMember;
				inline constexpr REL::Offset GetArraySize(0x00F0C310);
				//inline constexpr REL::Offset GetDisplayInfo;
				//inline constexpr REL::Offset GetElement;
				//inline constexpr REL::Offset GetMember;
				//inline constexpr REL::Offset GotoAndPlay;
				//inline constexpr REL::Offset HasMember;
				//inline constexpr REL::Offset Invoke;
				inline constexpr REL::Offset ObjectAddRef(0x00F0D6A0);
				inline constexpr REL::Offset ObjectRelease(0x00F0D700);
				inline constexpr REL::Offset PushBack(0x00F0D920);
				//inline constexpr REL::Offset RemoveElements;
				//inline constexpr REL::Offset SetArraySize;
				//inline constexpr REL::Offset SetDisplayInfo;
				//inline constexpr REL::Offset SetElement;
				//inline constexpr REL::Offset SetMember;
				//inline constexpr REL::Offset SetText;
			}
		}

		namespace GMemory
		{
			inline constexpr REL::Offset GlobalHeap(0x030CC600);
		}

		namespace GString
		{
			inline constexpr REL::Offset Ctor(0x00F1ACC0);
		}

		namespace IFormFactory
		{
			inline constexpr REL::Offset FormFactories(0x01F5E4A0);
			inline constexpr REL::Offset FormFactoriesInitialized(0x01F5E490);
		}

		namespace MemoryManager
		{
			inline constexpr REL::Offset GetSingleton(0x00106EC0);
			inline constexpr REL::Offset Allocate(0x00C26F00);
			inline constexpr REL::Offset Deallocate(0x00C27350);
			inline constexpr REL::Offset GetThreadScrapHeap(0x00C264A0);
			inline constexpr REL::Offset Reallocate(0x00C27150);
			//inline constexpr REL::Offset RegisterMemoryManager;
		}

		namespace ScrapHeap
		{
			inline constexpr REL::Offset Allocate(0x00C28310);
			inline constexpr REL::Offset Deallocate(0x00C28910);
		}

		namespace Script
		{
			inline constexpr REL::Offset CompileAndRun(0x002FBA00);
		}

		namespace INISettingCollection
		{
			//inline constexpr REL::Offset fSafeZoneXWide;
			//inline constexpr REL::Offset fSafeZoneYWide;
			//inline constexpr REL::Offset fSafeZoneX;
			//inline constexpr REL::Offset fSafeZoneY;
		}

		namespace SkyrimVM
		{
			inline constexpr REL::Offset QueuePostRenderCall(0x009520B0);
			inline constexpr REL::Offset Singleton(0x01F5E378);
		}

		namespace TESDataHandler
		{
			//inline constexpr REL::Offset LoadScripts;
			inline constexpr REL::Offset Singleton(0x01F58C28);
		}

		namespace TESForm
		{
			inline constexpr REL::Offset AddCompileIndex(0x01A0530);
			inline constexpr REL::Offset AllForms(0x01F5E498);
			inline constexpr REL::Offset AllFormsMapLock(0x01F5E928);
			inline constexpr REL::Offset AllFormsByEditorID(0x01F5E8F0);
			inline constexpr REL::Offset AllFormsEditorIDMapLock(0x01F5E930);
		}

		namespace TESObjectREFR
		{
			//inline constexpr REL::Offset FindReferenceFor3D;
			//inline constexpr REL::Offset GetDisplayFullName;
			//inline constexpr REL::Offset GetLock;
			//inline constexpr REL::Offset GetOwner;
			//inline constexpr REL::Offset GetStealValue;
			//inline constexpr REL::Offset GetWeightInContainer;
			//inline constexpr REL::Offset HasQuestObject;
			//inline constexpr REL::Offset InitChildActivates;
			//inline constexpr REL::Offset InitInventoryIfRequired;
			//inline constexpr REL::Offset IsAnOwner;
			//inline constexpr REL::Offset IsCrimeToActivate;
			//inline constexpr REL::Offset MakeInventoryChanges;
			//inline constexpr REL::Offset MoveTo;
			//inline constexpr REL::Offset PlayAnimation;
		}

		namespace UI
		{
			inline constexpr REL::Offset Singleton(0x01F59320);
		}

		inline constexpr REL::Offset RTDynamicCast(0x014775BA);
	}
}
