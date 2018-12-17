#pragma once

#include "skse64/GameFormComponents.h"  // TESFullName, TESModelTextureSwap, TESIcon, BGSMessageIcon, TESWeightForm, TESValueForm, BGSDestructibleObjectForm, BGSEquipType

#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject


namespace RE
{
	class TESObjectLIGH :
		public TESBoundAnimObject,			// 000
		public TESFullName,					// 030
		public TESModelTextureSwap,			// 040
		public TESIcon,						// 078
		public BGSMessageIcon,				// 088
		public TESWeightForm,				// 0A0
		public TESValueForm,				// 0B0
		public BGSDestructibleObjectForm,	// 0C0
		public BGSEquipType					// 0D0
	{
	public:
		enum { kTypeID = FormType::Light };


		enum Flag : UInt32
		{
			kFlag_TypeOmni = 0,
			kFlag_Dynamic = 1 << 0,
			kFlag_Carryable = 1 << 1,
			kFlag_Negative = 1 << 2,
			kFlag_Flicker = 1 << 3,
			kFlag_Unk00000010 = 1 << 4,
			kFlag_OffByDefault = 1 << 5,
			kFlag_FlickerSlow = 1 << 6,
			kFlag_Pulse = 1 << 7,
			kFlag_PulseSlow = 1 << 8,
			kFlag_TypeSpot = 1 << 9,
			kFlag_TypeSpotShadow = 1 << 10,
			kFlag_TypeHemiShadow = 1 << 11,
			kFlag_TypeOmniShadow = 1 << 12,
			kFlag_PortalStrict = 1 << 13,

			kFlag_Type = kFlag_TypeSpot | kFlag_TypeSpotShadow | kFlag_TypeHemiShadow | kFlag_TypeOmniShadow
		};


		struct DataE0
		{
			struct Color
			{
				UInt8	red;	// 0
				UInt8	green;	// 1
				UInt8	blue;	// 2
				UInt8	pad3;	// 3
			};


			struct FlickerEffect
			{
				UInt32	period;				// 0
				UInt32	intensityAmplitude;	// 4
				UInt32	movementAmplitude;	// 8
			};


			SInt32			time;			// 00
			UInt32			radius;			// 04
			Color			color;			// 08
			Flag			flags;			// 0C
			UInt32			fallofExponent;	// 10
			float			FOV;			// 14 - 90
			float			nearClip;		// 18 - .001
			FlickerEffect	flickerEffect;	// 1C
		};


		struct Data118
		{
			UInt64	unk0;	// 00
			UInt32	unk4;	// 08
			UInt32	padC;	// 0C
			UInt64	unk8;	// 10
		};


		virtual ~TESObjectLIGH();																																		// 0

		// override (TESBoundAnimObject)
		virtual bool	LoadForm(TESFile* a_mod) override;																												// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;																									// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;																									// 0F
		virtual void	InitItem() override;																															// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, uintptr_t a_arg3, uintptr_t a_arg4, uintptr_t a_arg5) override;	// 37

		bool			CanBeCarried() const;


		DataE0	unkE0;		// 0E0 - DATA
		float	fadeValue;	// 108 - FNAM
		UInt32	pad10C;		// 10C - SNAM
		UInt64	unk110;		// 110
		Data118	unk118;		// 118
	};
	STATIC_ASSERT(sizeof(TESObjectLIGH) == 0x130);
}