#pragma once

#include "RE/B/BGSConstructFormsInAllFilesMap.h"
#include "RE/B/BGSFormChanges.h"
#include "RE/B/BGSLoadGameSubBuffer.h"
#include "RE/B/BSAtomic.h"
#include "RE/B/BSCoreTypes.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/T/TESDataHandler.h"

namespace RE
{
	class BGSLoadFormData;

	class BGSSaveLoadFormIDMap
	{
	public:
		BSTHashMap<FormID, std::uint32_t> formIDToIndex;  // 00
		BSTHashMap<std::uint32_t, FormID> indexToFormID;  // 30
		std::uint32_t                     nextIndex;      // 60
		std::uint32_t                     pad64;          // 64
	};
	static_assert(sizeof(BGSSaveLoadFormIDMap) == 0x68);

	class BGSCellNumericIDArrayMap : public BSTHashMap<FormID, BSTArray<FormID>>
	{
	};
	static_assert(sizeof(BGSCellNumericIDArrayMap) == 0x30);

	class BGSSaveLoadReferencesMap
	{
	public:
		BSTHashMap<FormID, FormID>                           movedReferences;  // 00
		BGSCellNumericIDArrayMap                             cellReferences;   // 30 - interior or sky cells
		BSTHashMap<std::uint32_t, BGSCellNumericIDArrayMap*> worldReferences;  // 60 - grid X/Y packed into 32 bit key
	};
	static_assert(sizeof(BGSSaveLoadReferencesMap) == 0x90);

	class BGSReconstructFormsInAllFilesMap : public BGSConstructFormsInAllFilesMap
	{
	};
	static_assert(sizeof(BGSReconstructFormsInAllFilesMap) == 0x80);

	struct QUEUED_SUB_BUFFER_TYPES
	{
		enum QUEUED_SUB_BUFFER_TYPE
		{
			kUnk0,
			kUnk1,
			kUnk2,

			kTotal
		};
	};
	using QUEUED_SUB_BUFFER_TYPE = QUEUED_SUB_BUFFER_TYPES::QUEUED_SUB_BUFFER_TYPE;

	class BGSSaveLoadQueuedSubBufferMap
	{
	public:
		BSTHashMap<TESForm*, BGSLoadGameSubBuffer> maps[QUEUED_SUB_BUFFER_TYPES::kTotal];
	};
	static_assert(sizeof(BGSSaveLoadQueuedSubBufferMap) == 0x90);

	class BGSSaveLoadHistory
	{
	public:
		BSTArray<const char*> notes;  // 00
	};
	static_assert(sizeof(BGSSaveLoadHistory) == 0x18);

	class BGSSaveLoadChangesMap
	{
	public:
		BSTHashMap<FormID, BGSFormChanges> changes;  // 00
		BSReadWriteLock                    lock;     // 30
	};
	static_assert(sizeof(BGSSaveLoadChangesMap) == 0x38);

	class BGSSaveLoadGame
	{
	public:
		enum class GlobalFlags
		{
			kAllowChanges = 1 << 0,
			kSaveGameLoading = 1 << 1,
			kSaveGameSaving = 1 << 2,
			kInitingForms = 1 << 3,
			kDeferInitForms = 1 << 4,
			kPositioningPlayerCharacter = 1 << 5,
			kPlayerLocationInvalid = 1 << 6
		};

		[[nodiscard]] static BGSSaveLoadGame* GetSingleton();

		[[nodiscard]] bool GetGlobalAllowChanges() const noexcept { return globalFlags.all(GlobalFlags::kAllowChanges); }
		[[nodiscard]] bool GetSaveGameLoading() const noexcept { return globalFlags.all(GlobalFlags::kSaveGameLoading); }
		[[nodiscard]] bool GetSaveGameSaving() const noexcept { return globalFlags.all(GlobalFlags::kSaveGameSaving); }
		[[nodiscard]] bool GetInitingForms() const noexcept { return globalFlags.all(GlobalFlags::kInitingForms); }
		[[nodiscard]] bool GetDeferInitForms() const noexcept { return globalFlags.all(GlobalFlags::kDeferInitForms); }
		[[nodiscard]] bool GetPositioningPlayerCharacter() const noexcept { return globalFlags.all(GlobalFlags::kPositioningPlayerCharacter); }

		// members
#ifndef SKYRIMVR
		TESFileCollection files;  // 000
#else
		std::uint8_t fileIndexMap[0xFF];         // 000
		std::uint8_t reverseFileIndexMap[0xFF];  // 0FF
#endif
		BGSSaveLoadFormIDMap                         worldspaceFormIDMap;         // 030
		BSTHashMap<std::uint32_t, ActorHandle>       queuedInitPackageLocations;  // 098
		BGSSaveLoadReferencesMap                     references;                  // 0C8
		BSTHashMap<FormID, FormID>                   changedFormIDs;              // 158
		BGSReconstructFormsInAllFilesMap             reconstructFormsMap;         // 188
		BGSSaveLoadQueuedSubBufferMap                queuedSubBuffers;            // 208
		BGSSaveLoadFormIDMap                         formIDMap;                   // 298
		BGSSaveLoadHistory                           history;                     // 300
		BSTArray<BGSLoadFormData*>                   loadFormData;                // 318
		BGSSaveLoadChangesMap*                       changesMap;                  // 330
		BGSSaveLoadChangesMap*                       oldChangesMap;               // 338
		stl::enumeration<GlobalFlags, std::uint32_t> globalFlags;                 // 340
		std::uint8_t                                 currentMinorVersion;         // 344
		std::uint8_t                                 pad345;                      // 345
		std::uint16_t                                pad346;                      // 346
	};
#ifndef SKYRIMVR
	static_assert(sizeof(BGSSaveLoadGame) == 0x348);
#else
	static_assert(sizeof(BGSSaveLoadGame) == 0x518);
#endif
}
