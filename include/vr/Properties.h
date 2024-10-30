#pragma once

namespace vr
{
	// Refers to a single container of properties
	using PropertyContainerHandle_t = std::uint64_t;
	using PropertyTypeTag_t = std::uint32_t;

	static constexpr PropertyContainerHandle_t k_ulInvalidPropertyContainer = 0;
	static constexpr PropertyTypeTag_t         k_unInvalidPropertyTag = 0;

	// Use these tags to set/get common types as struct properties
	static constexpr PropertyTypeTag_t k_unFloatPropertyTag = 1;
	static constexpr PropertyTypeTag_t k_unInt32PropertyTag = 2;
	static constexpr PropertyTypeTag_t k_unUint64PropertyTag = 3;
	static constexpr PropertyTypeTag_t k_unBoolPropertyTag = 4;
	static constexpr PropertyTypeTag_t k_unStringPropertyTag = 5;

	static constexpr PropertyTypeTag_t k_unHmdMatrix34PropertyTag = 20;
	static constexpr PropertyTypeTag_t k_unHmdMatrix44PropertyTag = 21;
	static constexpr PropertyTypeTag_t k_unHmdVector3PropertyTag = 22;
	static constexpr PropertyTypeTag_t k_unHmdVector4PropertyTag = 23;

	static constexpr PropertyTypeTag_t k_unHiddenAreaPropertyTag = 30;

	static constexpr PropertyTypeTag_t k_unOpenVRInternalReserved_Start = 1000;
	static constexpr PropertyTypeTag_t k_unOpenVRInternalReserved_End = 10000;

	// Each entry in this enum represents a property that can be retrieved about a
	// tracked device. Many fields are only valid for one ETrackedDeviceClass.
	enum ETrackedDeviceProperty
	{
		Prop_Invalid = 0,

		// general properties that apply to all device classes
		Prop_TrackingSystemName_String = 1000,
		Prop_ModelNumber_String = 1001,
		Prop_SerialNumber_String = 1002,
		Prop_RenderModelName_String = 1003,
		Prop_WillDriftInYaw_Bool = 1004,
		Prop_ManufacturerName_String = 1005,
		Prop_TrackingFirmwareVersion_String = 1006,
		Prop_HardwareRevision_String = 1007,
		Prop_AllWirelessDongleDescriptions_String = 1008,
		Prop_ConnectedWirelessDongle_String = 1009,
		Prop_DeviceIsWireless_Bool = 1010,
		Prop_DeviceIsCharging_Bool = 1011,
		Prop_DeviceBatteryPercentage_Float = 1012,  // 0 is empty, 1 is full
		Prop_StatusDisplayTransform_Matrix34 = 1013,
		Prop_Firmware_UpdateAvailable_Bool = 1014,
		Prop_Firmware_ManualUpdate_Bool = 1015,
		Prop_Firmware_ManualUpdateURL_String = 1016,
		Prop_HardwareRevision_Uint64 = 1017,
		Prop_FirmwareVersion_Uint64 = 1018,
		Prop_FPGAVersion_Uint64 = 1019,
		Prop_VRCVersion_Uint64 = 1020,
		Prop_RadioVersion_Uint64 = 1021,
		Prop_DongleVersion_Uint64 = 1022,
		Prop_BlockServerShutdown_Bool = 1023,
		Prop_CanUnifyCoordinateSystemWithHmd_Bool = 1024,
		Prop_ContainsProximitySensor_Bool = 1025,
		Prop_DeviceProvidesBatteryStatus_Bool = 1026,
		Prop_DeviceCanPowerOff_Bool = 1027,
		Prop_Firmware_ProgrammingTarget_String = 1028,
		Prop_DeviceClass_Int32 = 1029,
		Prop_HasCamera_Bool = 1030,
		Prop_DriverVersion_String = 1031,
		Prop_Firmware_ForceUpdateRequired_Bool = 1032,
		Prop_ViveSystemButtonFixRequired_Bool = 1033,
		Prop_ParentDriver_Uint64 = 1034,
		Prop_ResourceRoot_String = 1035,

		// Properties that are unique to TrackedDeviceClass_HMD
		Prop_ReportsTimeSinceVSync_Bool = 2000,
		Prop_SecondsFromVsyncToPhotons_Float = 2001,
		Prop_DisplayFrequency_Float = 2002,
		Prop_UserIpdMeters_Float = 2003,
		Prop_CurrentUniverseId_Uint64 = 2004,
		Prop_PreviousUniverseId_Uint64 = 2005,
		Prop_DisplayFirmwareVersion_Uint64 = 2006,
		Prop_IsOnDesktop_Bool = 2007,
		Prop_DisplayMCType_Int32 = 2008,
		Prop_DisplayMCOffset_Float = 2009,
		Prop_DisplayMCScale_Float = 2010,
		Prop_EdidVendorID_Int32 = 2011,
		Prop_DisplayMCImageLeft_String = 2012,
		Prop_DisplayMCImageRight_String = 2013,
		Prop_DisplayGCBlackClamp_Float = 2014,
		Prop_EdidProductID_Int32 = 2015,
		Prop_CameraToHeadTransform_Matrix34 = 2016,
		Prop_DisplayGCType_Int32 = 2017,
		Prop_DisplayGCOffset_Float = 2018,
		Prop_DisplayGCScale_Float = 2019,
		Prop_DisplayGCPrescale_Float = 2020,
		Prop_DisplayGCImage_String = 2021,
		Prop_LensCenterLeftU_Float = 2022,
		Prop_LensCenterLeftV_Float = 2023,
		Prop_LensCenterRightU_Float = 2024,
		Prop_LensCenterRightV_Float = 2025,
		Prop_UserHeadToEyeDepthMeters_Float = 2026,
		Prop_CameraFirmwareVersion_Uint64 = 2027,
		Prop_CameraFirmwareDescription_String = 2028,
		Prop_DisplayFPGAVersion_Uint64 = 2029,
		Prop_DisplayBootloaderVersion_Uint64 = 2030,
		Prop_DisplayHardwareVersion_Uint64 = 2031,
		Prop_AudioFirmwareVersion_Uint64 = 2032,
		Prop_CameraCompatibilityMode_Int32 = 2033,
		Prop_ScreenshotHorizontalFieldOfViewDegrees_Float = 2034,
		Prop_ScreenshotVerticalFieldOfViewDegrees_Float = 2035,
		Prop_DisplaySuppressed_Bool = 2036,
		Prop_DisplayAllowNightMode_Bool = 2037,
		Prop_DisplayMCImageWidth_Int32 = 2038,
		Prop_DisplayMCImageHeight_Int32 = 2039,
		Prop_DisplayMCImageNumChannels_Int32 = 2040,
		Prop_DisplayMCImageData_Binary = 2041,
		Prop_SecondsFromPhotonsToVblank_Float = 2042,
		Prop_DriverDirectModeSendsVsyncEvents_Bool = 2043,
		Prop_DisplayDebugMode_Bool = 2044,
		Prop_GraphicsAdapterLuid_Uint64 = 2045,
		Prop_DriverProvidedChaperonePath_String = 2048,

		// Properties that are unique to TrackedDeviceClass_Controller
		Prop_AttachedDeviceId_String = 3000,
		Prop_SupportedButtons_Uint64 = 3001,
		Prop_Axis0Type_Int32 = 3002,           // Return value is of type EVRControllerAxisType
		Prop_Axis1Type_Int32 = 3003,           // Return value is of type EVRControllerAxisType
		Prop_Axis2Type_Int32 = 3004,           // Return value is of type EVRControllerAxisType
		Prop_Axis3Type_Int32 = 3005,           // Return value is of type EVRControllerAxisType
		Prop_Axis4Type_Int32 = 3006,           // Return value is of type EVRControllerAxisType
		Prop_ControllerRoleHint_Int32 = 3007,  // Return value is of type ETrackedControllerRole

		// Properties that are unique to TrackedDeviceClass_TrackingReference
		Prop_FieldOfViewLeftDegrees_Float = 4000,
		Prop_FieldOfViewRightDegrees_Float = 4001,
		Prop_FieldOfViewTopDegrees_Float = 4002,
		Prop_FieldOfViewBottomDegrees_Float = 4003,
		Prop_TrackingRangeMinimumMeters_Float = 4004,
		Prop_TrackingRangeMaximumMeters_Float = 4005,
		Prop_ModeLabel_String = 4006,

		// Properties that are used for user interface like icons names
		Prop_IconPathName_String = 5000,                       // DEPRECATED. Value not referenced. Now expected to be part of icon path properties.
		Prop_NamedIconPathDeviceOff_String = 5001,             // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
		Prop_NamedIconPathDeviceSearching_String = 5002,       // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
		Prop_NamedIconPathDeviceSearchingAlert_String = 5003,  // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
		Prop_NamedIconPathDeviceReady_String = 5004,           // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
		Prop_NamedIconPathDeviceReadyAlert_String = 5005,      // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
		Prop_NamedIconPathDeviceNotReady_String = 5006,        // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
		Prop_NamedIconPathDeviceStandby_String = 5007,         // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
		Prop_NamedIconPathDeviceAlertLow_String = 5008,        // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others

		// Properties that are used by helpers, but are opaque to applications
		Prop_DisplayHiddenArea_Binary_Start = 5100,
		Prop_DisplayHiddenArea_Binary_End = 5150,

		// Properties that are unique to drivers
		Prop_UserConfigPath_String = 6000,
		Prop_InstallPath_String = 6001,
		Prop_HasDisplayComponent_Bool = 6002,
		Prop_HasControllerComponent_Bool = 6003,
		Prop_HasCameraComponent_Bool = 6004,
		Prop_HasDriverDirectModeComponent_Bool = 6005,
		Prop_HasVirtualDisplayComponent_Bool = 6006,

		// Vendors are free to expose private debug data in this reserved region
		Prop_VendorSpecific_Reserved_Start = 10000,
		Prop_VendorSpecific_Reserved_End = 10999,
	};

	// No string property will ever be longer than this length
	static const uint32_t k_unMaxPropertyStringSize = 32 * 1024;

	// Used to return errors that occur when reading properties.
	enum ETrackedPropertyError
	{
		TrackedProp_Success = 0,
		TrackedProp_WrongDataType = 1,
		TrackedProp_WrongDeviceClass = 2,
		TrackedProp_BufferTooSmall = 3,
		TrackedProp_UnknownProperty = 4,  // Driver has not set the property (and may not ever).
		TrackedProp_InvalidDevice = 5,
		TrackedProp_CouldNotContactServer = 6,
		TrackedProp_ValueNotProvidedByDevice = 7,
		TrackedProp_StringExceedsMaximumLength = 8,
		TrackedProp_NotYetAvailable = 9,  // The property value isn't known yet, but is expected soon. Call again later.
		TrackedProp_PermissionDenied = 10,
		TrackedProp_InvalidOperation = 11,
	};
}
