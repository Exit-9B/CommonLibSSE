#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/E/ExtraDataList.h"
#include "RE/M/MenuEventHandler.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class InventoryEntryData;
	class NewInventoryMenuItemLoadTask;
	class NiAVObject;
	class TESBoundObject;
	class TESObjectREFR;

	struct LoadedInventoryModel
	{
	public:
		// members
		TESForm*              itemBase;  // 00 - smart ptr
		TESBoundObject*       modelObj;  // 08
		NiPointer<NiAVObject> spModel;   // 10
		std::uint64_t         unk18;     // 18
	};
	static_assert(sizeof(LoadedInventoryModel) == 0x20);

	class Inventory3DManager :
		public MenuEventHandler,                    // 00
		public BSTSingletonSDM<Inventory3DManager>  // 10
	{
	public:
		~Inventory3DManager() override;  // 00

		static Inventory3DManager* GetSingleton();

		static void SetMouseRotation(bool a_active);
		static void StartMouseRotation() { SetMouseRotation(true); }
		static void StopMouseRotation() { SetMouseRotation(false); }

		void          Begin3D(std::uint32_t a_arg1);
		void          End3D();
		void          UpdateItem3D(InventoryEntryData* a_objDesc);
		void          UpdateItem3D(TESForm* a_form, ExtraDataList* a_extraList = nullptr);
		void          Clear3D();
		std::uint32_t Render();

		// members
		std::uint8_t                                  unk011;           // 011
		std::uint16_t                                 unk012;           // 012
		NiPoint3                                      currentPosition;  // 014
		NiPoint3                                      position;         // 020
		float                                         currentScale;     // 02C
		float                                         defaultScale;     // 030
		std::uint32_t                                 state;            // 034
		TESObjectREFR*                                tempRef;          // 038
		ExtraDataList                                 originalExtra;    // 040
		BSTSmallArray<LoadedInventoryModel, 7>        loadedModels;     // 058
		std::uint32_t                                 unk148;           // 148
		float                                         zoomProgress;     // 14C - 1 if zoomed in, 0 if not, in-between during transition
		BSTSmartPointer<NewInventoryMenuItemLoadTask> loadTask;         // 150
		std::uint8_t                                  unk158;           // 158
		std::uint8_t                                  unk159;           // 159
		std::uint8_t                                  unk15A;           // 15A
		std::uint8_t                                  pad15B;           // 15B
		std::uint32_t                                 pad15C;           // 15C
	};
#if !defined(SKYRIMVR) && !defined(SKYRIMSE_PRE_1_6_629)
	static_assert(sizeof(Inventory3DManager) == 0x168);
#else
	static_assert(sizeof(Inventory3DManager) == 0x160);
#endif
}
