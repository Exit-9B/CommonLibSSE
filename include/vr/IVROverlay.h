#pragma once

#include "vr/Hmd.h"
#include "vr/OpenVRTypes.h"
#include "vr/VREvent.h"

namespace vr
{
	// The maximum length of an overlay key in bytes, counting the terminating null character.
	static constexpr std::uint32_t k_unVROverlayMaxKeyLength = 128;

	// The maximum length of an overlay name in bytes, counting the terminating null character.
	static constexpr std::uint32_t k_unVROverlayMaxNameLength = 128;

	// The maximum number of overlays that can exist in the system at one time.
	static constexpr std::uint32_t k_unMaxOverlayCount = 64;

	// The maximum number of overlay intersection mask primitives per overlay
	static constexpr std::uint32_t k_unMaxOverlayIntersectionMaskPrimitivesCount = 32;

	// Types of input supported by VR Overlays
	enum VROverlayInputMethod
	{
		VROverlayInputMethod_None = 0,   // No input events will be generated automatically for this overlay
		VROverlayInputMethod_Mouse = 1,  // Tracked controllers will get mouse events automatically
	};

	// Allows the caller to figure out which overlay transform getter to call.
	enum VROverlayTransformType
	{
		VROverlayTransform_Absolute = 0,
		VROverlayTransform_TrackedDeviceRelative = 1,
		VROverlayTransform_SystemOverlay = 2,
		VROverlayTransform_TrackedComponent = 3,
	};

	// Overlay control settings
	enum VROverlayFlags
	{
		VROverlayFlags_None = 0,

		// The following only take effect when rendered using the high quality render path (see SetHighQualityOverlay).
		VROverlayFlags_Curved = 1,
		VROverlayFlags_RGSS4X = 2,

		// Set this flag on a dashboard overlay to prevent a tab from showing up for that overlay
		VROverlayFlags_NoDashboardTab = 3,

		// Set this flag on a dashboard that is able to deal with gamepad focus events
		VROverlayFlags_AcceptsGamepadEvents = 4,

		// Indicates that the overlay should dim/brighten to show gamepad focus
		VROverlayFlags_ShowGamepadFocus = 5,

		// When in VROverlayInputMethod_Mouse you can optionally enable sending VRScroll_t
		VROverlayFlags_SendVRScrollEvents = 6,
		VROverlayFlags_SendVRTouchpadEvents = 7,

		// If set this will render a vertical scroll wheel on the primary controller,
		//  only needed if not using VROverlayFlags_SendVRScrollEvents but you still want to represent a scroll wheel
		VROverlayFlags_ShowTouchPadScrollWheel = 8,

		// If this is set ownership and render access to the overlay are transferred
		// to the new scene process on a call to IVRApplications::LaunchInternalProcess
		VROverlayFlags_TransferOwnershipToInternalProcess = 9,

		// If set, renders 50% of the texture in each eye, side by side
		VROverlayFlags_SideBySide_Parallel = 10,  // Texture is left/right
		VROverlayFlags_SideBySide_Crossed = 11,   // Texture is crossed and right/left

		VROverlayFlags_Panorama = 12,        // Texture is a panorama
		VROverlayFlags_StereoPanorama = 13,  // Texture is a stereo panorama

		// If this is set on an overlay owned by the scene application that overlay
		// will be sorted with the "Other" overlays on top of all other scene overlays
		VROverlayFlags_SortWithNonSceneOverlays = 14,

		// If set, the overlay will be shown in the dashboard, otherwise it will be hidden.
		VROverlayFlags_VisibleInDashboard = 15,
	};

	enum VRMessageOverlayResponse
	{
		VRMessageOverlayResponse_ButtonPress_0 = 0,
		VRMessageOverlayResponse_ButtonPress_1 = 1,
		VRMessageOverlayResponse_ButtonPress_2 = 2,
		VRMessageOverlayResponse_ButtonPress_3 = 3,
		VRMessageOverlayResponse_CouldntFindSystemOverlay = 4,
		VRMessageOverlayResponse_CouldntFindOrCreateClientOverlay = 5,
		VRMessageOverlayResponse_ApplicationQuit = 6
	};

	struct VROverlayIntersectionParams_t
	{
		HmdVector3_t            vSource;
		HmdVector3_t            vDirection;
		ETrackingUniverseOrigin eOrigin;
	};

	struct VROverlayIntersectionResults_t
	{
		HmdVector3_t vPoint;
		HmdVector3_t vNormal;
		HmdVector2_t vUVs;
		float        fDistance;
	};

	// Input modes for the Big Picture gamepad text entry
	enum EGamepadTextInputMode
	{
		k_EGamepadTextInputModeNormal = 0,
		k_EGamepadTextInputModePassword = 1,
		k_EGamepadTextInputModeSubmit = 2,
	};

	// Controls number of allowed lines for the Big Picture gamepad text entry
	enum EGamepadTextInputLineMode
	{
		k_EGamepadTextInputLineModeSingleLine = 0,
		k_EGamepadTextInputLineModeMultipleLines = 1
	};

	// Directions for changing focus between overlays with the gamepad
	enum EOverlayDirection
	{
		OverlayDirection_Up = 0,
		OverlayDirection_Down = 1,
		OverlayDirection_Left = 2,
		OverlayDirection_Right = 3,

		OverlayDirection_Count = 4,
	};

	enum EVROverlayIntersectionMaskPrimitiveType
	{
		OverlayIntersectionPrimitiveType_Rectangle,
		OverlayIntersectionPrimitiveType_Circle,
	};

	struct IntersectionMaskRectangle_t
	{
		float m_flTopLeftX;
		float m_flTopLeftY;
		float m_flWidth;
		float m_flHeight;
	};

	struct IntersectionMaskCircle_t
	{
		float m_flCenterX;
		float m_flCenterY;
		float m_flRadius;
	};

	union VROverlayIntersectionMaskPrimitive_Data_t
	{
		IntersectionMaskRectangle_t m_Rectangle;
		IntersectionMaskCircle_t    m_Circle;
	};

	struct VROverlayIntersectionMaskPrimitive_t
	{
		EVROverlayIntersectionMaskPrimitiveType   m_nPrimitiveType;
		VROverlayIntersectionMaskPrimitive_Data_t m_Primitive;
	};

	class IVROverlay
	{
	public:
		virtual EVROverlayError          FindOverlay(const char* pchOverlayKey, VROverlayHandle_t* pOverlayHandle) = 0;                                                                                                                                                                                                     // 00
		virtual EVROverlayError          CreateOverlay(const char* pchOverlayKey, const char* pchOverlayName, VROverlayHandle_t* pOverlayHandle) = 0;                                                                                                                                                                       // 01
		virtual EVROverlayError          DestroyOverlay(VROverlayHandle_t ulOverlayHandle) = 0;                                                                                                                                                                                                                             // 02
		virtual EVROverlayError          SetHighQualityOverlay(VROverlayHandle_t ulOverlayHandle) = 0;                                                                                                                                                                                                                      // 03
		virtual vr::VROverlayHandle_t    GetHighQualityOverlay() = 0;                                                                                                                                                                                                                                                       // 04
		virtual std::uint32_t            GetOverlayKey(VROverlayHandle_t ulOverlayHandle, char* pchValue, std::uint32_t unBufferSize, EVROverlayError* pError = 0L) = 0;                                                                                                                                                    // 05
		virtual std::uint32_t            GetOverlayName(VROverlayHandle_t ulOverlayHandle, char* pchValue, std::uint32_t unBufferSize, EVROverlayError* pError = 0L) = 0;                                                                                                                                                   // 06
		virtual EVROverlayError          SetOverlayName(VROverlayHandle_t ulOverlayHandle, const char* pchName) = 0;                                                                                                                                                                                                        // 07
		virtual EVROverlayError          GetOverlayImageData(VROverlayHandle_t ulOverlayHandle, void* pvBuffer, std::uint32_t unBufferSize, std::uint32_t* punWidth, std::uint32_t* punHeight) = 0;                                                                                                                         // 08
		virtual const char*              GetOverlayErrorNameFromEnum(EVROverlayError error) = 0;                                                                                                                                                                                                                            // 09
		virtual EVROverlayError          SetOverlayRenderingPid(VROverlayHandle_t ulOverlayHandle, std::uint32_t unPID) = 0;                                                                                                                                                                                                // 0A
		virtual std::uint32_t            GetOverlayRenderingPid(VROverlayHandle_t ulOverlayHandle) = 0;                                                                                                                                                                                                                     // 0B
		virtual EVROverlayError          SetOverlayFlag(VROverlayHandle_t ulOverlayHandle, VROverlayFlags eOverlayFlag, bool bEnabled) = 0;                                                                                                                                                                                 // 0C
		virtual EVROverlayError          GetOverlayFlag(VROverlayHandle_t ulOverlayHandle, VROverlayFlags eOverlayFlag, bool* pbEnabled) = 0;                                                                                                                                                                               // 0D
		virtual EVROverlayError          SetOverlayColor(VROverlayHandle_t ulOverlayHandle, float fRed, float fGreen, float fBlue) = 0;                                                                                                                                                                                     // 0E
		virtual EVROverlayError          GetOverlayColor(VROverlayHandle_t ulOverlayHandle, float* pfRed, float* pfGreen, float* pfBlue) = 0;                                                                                                                                                                               // 0F
		virtual EVROverlayError          SetOverlayAlpha(VROverlayHandle_t ulOverlayHandle, float fAlpha) = 0;                                                                                                                                                                                                              // 10
		virtual EVROverlayError          GetOverlayAlpha(VROverlayHandle_t ulOverlayHandle, float* pfAlpha) = 0;                                                                                                                                                                                                            // 11
		virtual EVROverlayError          SetOverlayTexelAspect(VROverlayHandle_t ulOverlayHandle, float fTexelAspect) = 0;                                                                                                                                                                                                  // 12
		virtual EVROverlayError          GetOverlayTexelAspect(VROverlayHandle_t ulOverlayHandle, float* pfTexelAspect) = 0;                                                                                                                                                                                                // 13
		virtual EVROverlayError          SetOverlaySortOrder(VROverlayHandle_t ulOverlayHandle, std::uint32_t unSortOrder) = 0;                                                                                                                                                                                             // 14
		virtual EVROverlayError          GetOverlaySortOrder(VROverlayHandle_t ulOverlayHandle, std::uint32_t* punSortOrder) = 0;                                                                                                                                                                                           // 15
		virtual EVROverlayError          SetOverlayWidthInMeters(VROverlayHandle_t ulOverlayHandle, float fWidthInMeters) = 0;                                                                                                                                                                                              // 16
		virtual EVROverlayError          GetOverlayWidthInMeters(VROverlayHandle_t ulOverlayHandle, float* pfWidthInMeters) = 0;                                                                                                                                                                                            // 17
		virtual EVROverlayError          SetOverlayAutoCurveDistanceRangeInMeters(VROverlayHandle_t ulOverlayHandle, float fMinDistanceInMeters, float fMaxDistanceInMeters) = 0;                                                                                                                                           // 18
		virtual EVROverlayError          GetOverlayAutoCurveDistanceRangeInMeters(VROverlayHandle_t ulOverlayHandle, float* pfMinDistanceInMeters, float* pfMaxDistanceInMeters) = 0;                                                                                                                                       // 19
		virtual EVROverlayError          SetOverlayTextureColorSpace(VROverlayHandle_t ulOverlayHandle, EColorSpace eTextureColorSpace) = 0;                                                                                                                                                                                // 1A
		virtual EVROverlayError          GetOverlayTextureColorSpace(VROverlayHandle_t ulOverlayHandle, EColorSpace* peTextureColorSpace) = 0;                                                                                                                                                                              // 1B
		virtual EVROverlayError          SetOverlayTextureBounds(VROverlayHandle_t ulOverlayHandle, const VRTextureBounds_t* pOverlayTextureBounds) = 0;                                                                                                                                                                    // 1C
		virtual EVROverlayError          GetOverlayTextureBounds(VROverlayHandle_t ulOverlayHandle, VRTextureBounds_t* pOverlayTextureBounds) = 0;                                                                                                                                                                          // 1D
		virtual std::uint32_t            GetOverlayRenderModel(vr::VROverlayHandle_t ulOverlayHandle, char* pchValue, std::uint32_t unBufferSize, HmdColor_t* pColor, vr::EVROverlayError* pError) = 0;                                                                                                                     // 1E
		virtual vr::EVROverlayError      SetOverlayRenderModel(vr::VROverlayHandle_t ulOverlayHandle, const char* pchRenderModel, const HmdColor_t* pColor) = 0;                                                                                                                                                            // 1F
		virtual EVROverlayError          GetOverlayTransformType(VROverlayHandle_t ulOverlayHandle, VROverlayTransformType* peTransformType) = 0;                                                                                                                                                                           // 20
		virtual EVROverlayError          SetOverlayTransformAbsolute(VROverlayHandle_t ulOverlayHandle, ETrackingUniverseOrigin eTrackingOrigin, const HmdMatrix34_t* pmatTrackingOriginToOverlayTransform) = 0;                                                                                                            // 21
		virtual EVROverlayError          GetOverlayTransformAbsolute(VROverlayHandle_t ulOverlayHandle, ETrackingUniverseOrigin* peTrackingOrigin, HmdMatrix34_t* pmatTrackingOriginToOverlayTransform) = 0;                                                                                                                // 22
		virtual EVROverlayError          SetOverlayTransformTrackedDeviceRelative(VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t unTrackedDevice, const HmdMatrix34_t* pmatTrackedDeviceToOverlayTransform) = 0;                                                                                                   // 23
		virtual EVROverlayError          GetOverlayTransformTrackedDeviceRelative(VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t* punTrackedDevice, HmdMatrix34_t* pmatTrackedDeviceToOverlayTransform) = 0;                                                                                                       // 24
		virtual EVROverlayError          SetOverlayTransformTrackedDeviceComponent(VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t unDeviceIndex, const char* pchComponentName) = 0;                                                                                                                                // 25
		virtual EVROverlayError          GetOverlayTransformTrackedDeviceComponent(VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t* punDeviceIndex, char* pchComponentName, std::uint32_t unComponentNameSize) = 0;                                                                                                 // 26
		virtual vr::EVROverlayError      GetOverlayTransformOverlayRelative(VROverlayHandle_t ulOverlayHandle, VROverlayHandle_t* ulOverlayHandleParent, HmdMatrix34_t* pmatParentOverlayToOverlayTransform) = 0;                                                                                                           // 27
		virtual vr::EVROverlayError      SetOverlayTransformOverlayRelative(VROverlayHandle_t ulOverlayHandle, VROverlayHandle_t ulOverlayHandleParent, const HmdMatrix34_t* pmatParentOverlayToOverlayTransform) = 0;                                                                                                      // 28
		virtual EVROverlayError          ShowOverlay(VROverlayHandle_t ulOverlayHandle) = 0;                                                                                                                                                                                                                                // 29
		virtual EVROverlayError          HideOverlay(VROverlayHandle_t ulOverlayHandle) = 0;                                                                                                                                                                                                                                // 2A
		virtual bool                     IsOverlayVisible(VROverlayHandle_t ulOverlayHandle) = 0;                                                                                                                                                                                                                           // 2B
		virtual EVROverlayError          GetTransformForOverlayCoordinates(VROverlayHandle_t ulOverlayHandle, ETrackingUniverseOrigin eTrackingOrigin, HmdVector2_t coordinatesInOverlay, HmdMatrix34_t* pmatTransform) = 0;                                                                                                // 2C
		virtual bool                     PollNextOverlayEvent(VROverlayHandle_t ulOverlayHandle, VREvent_t* pEvent, std::uint32_t uncbVREvent) = 0;                                                                                                                                                                         // 2D
		virtual EVROverlayError          GetOverlayInputMethod(VROverlayHandle_t ulOverlayHandle, VROverlayInputMethod* peInputMethod) = 0;                                                                                                                                                                                 // 2E
		virtual EVROverlayError          SetOverlayInputMethod(VROverlayHandle_t ulOverlayHandle, VROverlayInputMethod eInputMethod) = 0;                                                                                                                                                                                   // 2F
		virtual EVROverlayError          GetOverlayMouseScale(VROverlayHandle_t ulOverlayHandle, HmdVector2_t* pvecMouseScale) = 0;                                                                                                                                                                                         // 30
		virtual EVROverlayError          SetOverlayMouseScale(VROverlayHandle_t ulOverlayHandle, const HmdVector2_t* pvecMouseScale) = 0;                                                                                                                                                                                   // 31
		virtual bool                     ComputeOverlayIntersection(VROverlayHandle_t ulOverlayHandle, const VROverlayIntersectionParams_t* pParams, VROverlayIntersectionResults_t* pResults) = 0;                                                                                                                         // 32
		virtual bool                     IsHoverTargetOverlay(VROverlayHandle_t ulOverlayHandle) = 0;                                                                                                                                                                                                                       // 33
		virtual vr::VROverlayHandle_t    GetGamepadFocusOverlay() = 0;                                                                                                                                                                                                                                                      // 34
		virtual EVROverlayError          SetGamepadFocusOverlay(VROverlayHandle_t ulNewFocusOverlay) = 0;                                                                                                                                                                                                                   // 35
		virtual EVROverlayError          SetOverlayNeighbor(EOverlayDirection eDirection, VROverlayHandle_t ulFrom, VROverlayHandle_t ulTo) = 0;                                                                                                                                                                            // 36
		virtual EVROverlayError          MoveGamepadFocusToNeighbor(EOverlayDirection eDirection, VROverlayHandle_t ulFrom) = 0;                                                                                                                                                                                            // 37
		virtual EVROverlayError          SetOverlayDualAnalogTransform(VROverlayHandle_t ulOverlay, EDualAnalogWhich eWhich, const HmdVector2_t& vCenter, float fRadius) = 0;                                                                                                                                               // 38
		virtual EVROverlayError          GetOverlayDualAnalogTransform(VROverlayHandle_t ulOverlay, EDualAnalogWhich eWhich, HmdVector2_t* pvCenter, float* pfRadius) = 0;                                                                                                                                                  // 39
		virtual EVROverlayError          SetOverlayTexture(VROverlayHandle_t ulOverlayHandle, const Texture_t* pTexture) = 0;                                                                                                                                                                                               // 3A
		virtual EVROverlayError          ClearOverlayTexture(VROverlayHandle_t ulOverlayHandle) = 0;                                                                                                                                                                                                                        // 3B
		virtual EVROverlayError          SetOverlayRaw(VROverlayHandle_t ulOverlayHandle, void* pvBuffer, std::uint32_t unWidth, std::uint32_t unHeight, std::uint32_t unDepth) = 0;                                                                                                                                        // 3C
		virtual EVROverlayError          SetOverlayFromFile(VROverlayHandle_t ulOverlayHandle, const char* pchFilePath) = 0;                                                                                                                                                                                                // 3D
		virtual EVROverlayError          GetOverlayTexture(VROverlayHandle_t ulOverlayHandle, void** pNativeTextureHandle, void* pNativeTextureRef, std::uint32_t* pWidth, std::uint32_t* pHeight, std::uint32_t* pNativeFormat, ETextureType* pAPIType, EColorSpace* pColorSpace, VRTextureBounds_t* pTextureBounds) = 0;  // 3E
		virtual EVROverlayError          ReleaseNativeOverlayHandle(VROverlayHandle_t ulOverlayHandle, void* pNativeTextureHandle) = 0;                                                                                                                                                                                     // 3F
		virtual EVROverlayError          GetOverlayTextureSize(VROverlayHandle_t ulOverlayHandle, std::uint32_t* pWidth, std::uint32_t* pHeight) = 0;                                                                                                                                                                       // 40
		virtual EVROverlayError          CreateDashboardOverlay(const char* pchOverlayKey, const char* pchOverlayFriendlyName, VROverlayHandle_t* pMainHandle, VROverlayHandle_t* pThumbnailHandle) = 0;                                                                                                                    // 41
		virtual bool                     IsDashboardVisible() = 0;                                                                                                                                                                                                                                                          // 42
		virtual bool                     IsActiveDashboardOverlay(VROverlayHandle_t ulOverlayHandle) = 0;                                                                                                                                                                                                                   // 43
		virtual EVROverlayError          SetDashboardOverlaySceneProcess(VROverlayHandle_t ulOverlayHandle, std::uint32_t unProcessId) = 0;                                                                                                                                                                                 // 44
		virtual EVROverlayError          GetDashboardOverlaySceneProcess(VROverlayHandle_t ulOverlayHandle, std::uint32_t* punProcessId) = 0;                                                                                                                                                                               // 45
		virtual void                     ShowDashboard(const char* pchOverlayToShow) = 0;                                                                                                                                                                                                                                   // 46
		virtual vr::TrackedDeviceIndex_t GetPrimaryDashboardDevice() = 0;                                                                                                                                                                                                                                                   // 47
		virtual EVROverlayError          ShowKeyboard(EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char* pchDescription, std::uint32_t unCharMax, const char* pchExistingText, bool bUseMinimalMode, uint64_t uUserValue) = 0;                                                         // 48
		virtual EVROverlayError          ShowKeyboardForOverlay(VROverlayHandle_t ulOverlayHandle, EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char* pchDescription, std::uint32_t unCharMax, const char* pchExistingText, bool bUseMinimalMode, uint64_t uUserValue) = 0;            // 49
		virtual std::uint32_t            GetKeyboardText(char* pchText, std::uint32_t cchText) = 0;                                                                                                                                                                                                                         // 4A
		virtual void                     HideKeyboard() = 0;                                                                                                                                                                                                                                                                // 4B
		virtual void                     SetKeyboardTransformAbsolute(ETrackingUniverseOrigin eTrackingOrigin, const HmdMatrix34_t* pmatTrackingOriginToKeyboardTransform) = 0;                                                                                                                                             // 4C
		virtual void                     SetKeyboardPositionForOverlay(VROverlayHandle_t ulOverlayHandle, HmdRect2_t avoidRect) = 0;                                                                                                                                                                                        // 4D
		virtual EVROverlayError          SetOverlayIntersectionMask(VROverlayHandle_t ulOverlayHandle, VROverlayIntersectionMaskPrimitive_t* pMaskPrimitives, std::uint32_t unNumMaskPrimitives, std::uint32_t unPrimitiveSize = sizeof(VROverlayIntersectionMaskPrimitive_t)) = 0;                                         // 4E
		virtual EVROverlayError          GetOverlayFlags(VROverlayHandle_t ulOverlayHandle, std::uint32_t* pFlags) = 0;                                                                                                                                                                                                     // 4F
		virtual VRMessageOverlayResponse ShowMessageOverlay(const char* pchText, const char* pchCaption, const char* pchButton0Text, const char* pchButton1Text = nullptr, const char* pchButton2Text = nullptr, const char* pchButton3Text = nullptr) = 0;                                                                 // 50
		virtual void                     CloseMessageOverlay() = 0;                                                                                                                                                                                                                                                         // 51
	};
}
