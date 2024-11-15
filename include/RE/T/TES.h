#pragma once

#include "RE/B/BSSimpleList.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTTuple.h"
#include "RE/C/Color.h"
#include "RE/I/ICellAttachDetachEventSource.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	namespace BSResource
	{
		struct ArchiveStreamOpenedEvent;
	}

	class BSFogProperty;
	class BSSystemEvent;
	class BSTempNodeManager;
	class GridCellArray;
	class ImageSpaceModifierInstance;
	class LoadedAreaBound;
	class NavMeshInfoMap;
	class NiAVObject;
	class NiDirectionalLight;
	class NiNode;
	class NiTexture;
	class QueuedFile;
	class Sky;
	class TESActorBase;
	class TESObjectCELL;
	class TESWorldSpace;

	struct PositionPlayerEvent;

	class TES :
		public ICellAttachDetachEventSource,                        // 000
		public BSTEventSink<BSResource::ArchiveStreamOpenedEvent>,  // 060
		public BSTEventSink<PositionPlayerEvent>                    // 068
	{
	public:
		inline static constexpr auto RTTI = RTTI_TES;

		enum class BorderMode
		{
			Off,
			On,
			OverEverything
		};

		class ParticleObjectCache
		{
		public:
			// members
			NiPointer<NiAVObject>  particleObject;  // 00
			NiPointer<NiAVObject>* clones;          // 08
			ParticleObjectCache*   next;            // 10
		};
		static_assert(sizeof(ParticleObjectCache) == 0x18);

		class SystemEventAdapter : public BSTEventSink<BSSystemEvent>
		{
		public:
			inline static constexpr auto RTTI = RTTI_TES;

			~SystemEventAdapter() override;  // 00

			// override (BSTEventSink<BSSystemEvent>)
			BSEventNotifyControl ProcessEvent(const BSSystemEvent* a_event, BSTEventSource<BSSystemEvent>* a_eventSource) override;  // 01

			// members
			std::uint64_t unk08;  // 08
		};
		static_assert(sizeof(SystemEventAdapter) == 0x10);

		~TES() override;  // 00

		// override (BSTEventSink<BSResource::ArchiveStreamOpenedEvent>)
		BSEventNotifyControl ProcessEvent(const BSResource::ArchiveStreamOpenedEvent* a_event, BSTEventSource<BSResource::ArchiveStreamOpenedEvent>* a_eventSource) override;  // 01 - { return BSEventNotifyControl::kContinue; }

		// override (BSTEventSink<PositionPlayerEvent>)
		BSEventNotifyControl ProcessEvent(const PositionPlayerEvent* a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;  // 01

		static TES* GetSingleton();

		// members
		std::uint64_t                                       unk070;                     // 070
		GridCellArray*                                      gridCells;                  // 078
		NiNode*                                             objRoot;                    // 080
		NiNode*                                             lodLandRoot;                // 088
		NiNode*                                             objLODWaterRoot;            // 090
		BSTempNodeManager*                                  tempNodeManager;            // 098
		NiPointer<NiDirectionalLight>                       sunLight;                   // 0A0
		NiPointer<BSFogProperty>                            fog;                        // 0A8
		std::int32_t                                        currentGridX;               // 0B0
		std::int32_t                                        currentGridY;               // 0B4
		std::int32_t                                        queuedGridX;                // 0B8
		std::int32_t                                        queuedGridY;                // 0BC
		TESObjectCELL*                                      interiorCell;               // 0C0
		TESObjectCELL**                                     interiorBuffer;             // 0C8
		TESObjectCELL**                                     exteriorBuffer;             // 0D0
		std::uint64_t                                       unk0D8;                     // 0D8
		std::int32_t                                        saveGridX;                  // 0E0
		std::int32_t                                        saveGridY;                  // 0E4
		std::uint64_t                                       unk0E8;                     // 0E8
		std::uint64_t                                       unk0F0;                     // 0F0
		std::uint64_t                                       unk0F8;                     // 0F8
		Sky*                                                sky;                        // 100
		BSSimpleList<NiPointer<ImageSpaceModifierInstance>> activeImageSpaceModifiers;  // 108
		std::uint64_t                                       unk118;                     // 118
		std::uint64_t                                       unk120;                     // 120
		std::uint8_t                                        unk128;                     // 128
#if !defined(SKYRIMVR)
		BorderMode showLANDborders;  // 12C
		Color      borderColor;      // 130
#else
		bool showLANDborders;  // 129
#endif
		bool                                                  interiorUnloaded;        // 134
		bool                                                  inWorldMapMode;          // 135
		std::uint8_t                                          unk136;                  // 136
		bool                                                  loadingMenuDisabled;     // 137
		bool                                                  cellTestRunning;         // 138
		std::uint8_t                                          unk139;                  // 139
		std::uint16_t                                         unk13A;                  // 13A
		bool                                                  allowUnusedPurge;        // 13C
		float                                                 gridShiftDistanceX;      // 140
		float                                                 gridShiftDistanceY;      // 144
		TESWorldSpace*                                        worldSpace;              // 148
		BSSimpleList<BSTTuple<TESActorBase*, std::uint16_t>*> deadCount;               // 150
		NiPointer<QueuedFile>                                 preloadedAddonNodes;     // 160
		NiPointer<NiTexture>                                  preloadedBloodTexture;   // 168
		NiPointer<QueuedFile>                                 preloadedForms;          // 170
		NiPointer<QueuedFile>                                 preloadedDefaultModels;  // 178
		char                                                  unk180[260];             // 180
		std::uint32_t                                         unk284;                  // 284
		std::uint32_t                                         unk288;                  // 288
		std::uint16_t                                         unk28C;                  // 28C
		std::uint16_t                                         pad28E;                  // 28E
		ParticleObjectCache*                                  particleObjectCache;     // 290
		SystemEventAdapter                                    systemEventAdapter;      // 298
		std::int32_t                                          placeableWaterCount;     // 2A8
		std::uint32_t                                         pad2AC;                  // 2AC
		NavMeshInfoMap*                                       navMeshInfoMap;          // 2B0
		NiPointer<LoadedAreaBound>                            loadedAreaBound;         // 2B8
	};
#if !defined(SKYRIMVR)
	static_assert(sizeof(TES) == 0x2C0);
#else
	static_assert(sizeof(TES) == 0x2B8);
#endif
}
