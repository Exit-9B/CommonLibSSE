#pragma once

#include "vr/Properties.h"

namespace vr
{
	/** The types of events that could be posted (and what the parameters mean for each event type) */
	enum EVREventType
	{
		VREvent_None = 0,

		VREvent_TrackedDeviceActivated = 100,
		VREvent_TrackedDeviceDeactivated = 101,
		VREvent_TrackedDeviceUpdated = 102,
		VREvent_TrackedDeviceUserInteractionStarted = 103,
		VREvent_TrackedDeviceUserInteractionEnded = 104,
		VREvent_IpdChanged = 105,
		VREvent_EnterStandbyMode = 106,
		VREvent_LeaveStandbyMode = 107,
		VREvent_TrackedDeviceRoleChanged = 108,
		VREvent_WatchdogWakeUpRequested = 109,
		VREvent_LensDistortionChanged = 110,
		VREvent_PropertyChanged = 111,
		VREvent_WirelessDisconnect = 112,
		VREvent_WirelessReconnect = 113,

		VREvent_ButtonPress = 200,    // data is controller
		VREvent_ButtonUnpress = 201,  // data is controller
		VREvent_ButtonTouch = 202,    // data is controller
		VREvent_ButtonUntouch = 203,  // data is controller

		VREvent_DualAnalog_Press = 250,        // data is dualAnalog
		VREvent_DualAnalog_Unpress = 251,      // data is dualAnalog
		VREvent_DualAnalog_Touch = 252,        // data is dualAnalog
		VREvent_DualAnalog_Untouch = 253,      // data is dualAnalog
		VREvent_DualAnalog_Move = 254,         // data is dualAnalog
		VREvent_DualAnalog_ModeSwitch1 = 255,  // data is dualAnalog
		VREvent_DualAnalog_ModeSwitch2 = 256,  // data is dualAnalog
		VREvent_DualAnalog_Cancel = 257,       // data is dualAnalog

		VREvent_MouseMove = 300,            // data is mouse
		VREvent_MouseButtonDown = 301,      // data is mouse
		VREvent_MouseButtonUp = 302,        // data is mouse
		VREvent_FocusEnter = 303,           // data is overlay
		VREvent_FocusLeave = 304,           // data is overlay
		VREvent_Scroll = 305,               // data is mouse
		VREvent_TouchPadMove = 306,         // data is mouse
		VREvent_OverlayFocusChanged = 307,  // data is overlay, global event

		VREvent_InputFocusCaptured = 400,                         // data is process DEPRECATED
		VREvent_InputFocusReleased = 401,                         // data is process DEPRECATED
		VREvent_SceneFocusLost = 402,                             // data is process
		VREvent_SceneFocusGained = 403,                           // data is process
		VREvent_SceneApplicationChanged = 404,                    // data is process - The App actually drawing the scene changed (usually to or from the compositor)
		VREvent_SceneFocusChanged = 405,                          // data is process - New app got access to draw the scene
		VREvent_InputFocusChanged = 406,                          // data is process
		VREvent_SceneApplicationSecondaryRenderingStarted = 407,  // data is process

		VREvent_HideRenderModels = 410,  // Sent to the scene application to request hiding render models temporarily
		VREvent_ShowRenderModels = 411,  // Sent to the scene application to request restoring render model visibility

		VREvent_ConsoleOpened = 420,
		VREvent_ConsoleClosed = 421,

		VREvent_OverlayShown = 500,
		VREvent_OverlayHidden = 501,
		VREvent_DashboardActivated = 502,
		VREvent_DashboardDeactivated = 503,
		VREvent_DashboardThumbSelected = 504,     // Sent to the overlay manager - data is overlay
		VREvent_DashboardRequested = 505,         // Sent to the overlay manager - data is overlay
		VREvent_ResetDashboard = 506,             // Send to the overlay manager
		VREvent_RenderToast = 507,                // Send to the dashboard to render a toast - data is the notification ID
		VREvent_ImageLoaded = 508,                // Sent to overlays when a SetOverlayRaw or SetOverlayFromFile call finishes loading
		VREvent_ShowKeyboard = 509,               // Sent to keyboard renderer in the dashboard to invoke it
		VREvent_HideKeyboard = 510,               // Sent to keyboard renderer in the dashboard to hide it
		VREvent_OverlayGamepadFocusGained = 511,  // Sent to an overlay when IVROverlay::SetFocusOverlay is called on it
		VREvent_OverlayGamepadFocusLost = 512,    // Send to an overlay when it previously had focus and IVROverlay::SetFocusOverlay is called on something else
		VREvent_OverlaySharedTextureChanged = 513,
		VREvent_DashboardGuideButtonDown = 514,
		VREvent_DashboardGuideButtonUp = 515,
		VREvent_ScreenshotTriggered = 516,  // Screenshot button combo was pressed, Dashboard should request a screenshot
		VREvent_ImageFailed = 517,          // Sent to overlays when a SetOverlayRaw or SetOverlayfromFail fails to load
		VREvent_DashboardOverlayCreated = 518,

		// Screenshot API
		VREvent_RequestScreenshot = 520,              // Sent by vrclient application to compositor to take a screenshot
		VREvent_ScreenshotTaken = 521,                // Sent by compositor to the application that the screenshot has been taken
		VREvent_ScreenshotFailed = 522,               // Sent by compositor to the application that the screenshot failed to be taken
		VREvent_SubmitScreenshotToDashboard = 523,    // Sent by compositor to the dashboard that a completed screenshot was submitted
		VREvent_ScreenshotProgressToDashboard = 524,  // Sent by compositor to the dashboard that a completed screenshot was submitted

		VREvent_PrimaryDashboardDeviceChanged = 525,

		VREvent_Notification_Shown = 600,
		VREvent_Notification_Hidden = 601,
		VREvent_Notification_BeginInteraction = 602,
		VREvent_Notification_Destroyed = 603,

		VREvent_Quit = 700,                    // data is process
		VREvent_ProcessQuit = 701,             // data is process
		VREvent_QuitAborted_UserPrompt = 702,  // data is process
		VREvent_QuitAcknowledged = 703,        // data is process
		VREvent_DriverRequestedQuit = 704,     // The driver has requested that SteamVR shut down

		VREvent_ChaperoneDataHasChanged = 800,
		VREvent_ChaperoneUniverseHasChanged = 801,
		VREvent_ChaperoneTempDataHasChanged = 802,
		VREvent_ChaperoneSettingsHaveChanged = 803,
		VREvent_SeatedZeroPoseReset = 804,

		VREvent_AudioSettingsHaveChanged = 820,

		VREvent_BackgroundSettingHasChanged = 850,
		VREvent_CameraSettingsHaveChanged = 851,
		VREvent_ReprojectionSettingHasChanged = 852,
		VREvent_ModelSkinSettingsHaveChanged = 853,
		VREvent_EnvironmentSettingsHaveChanged = 854,
		VREvent_PowerSettingsHaveChanged = 855,
		VREvent_EnableHomeAppSettingsHaveChanged = 856,
		VREvent_SteamVRSectionSettingChanged = 857,
		VREvent_LighthouseSectionSettingChanged = 858,
		VREvent_NullSectionSettingChanged = 859,
		VREvent_UserInterfaceSectionSettingChanged = 860,
		VREvent_NotificationsSectionSettingChanged = 861,
		VREvent_KeyboardSectionSettingChanged = 862,
		VREvent_PerfSectionSettingChanged = 863,
		VREvent_DashboardSectionSettingChanged = 864,
		VREvent_WebInterfaceSectionSettingChanged = 865,

		VREvent_StatusUpdate = 900,

		VREvent_WebInterface_InstallDriverCompleted = 950,

		VREvent_MCImageUpdated = 1000,

		VREvent_FirmwareUpdateStarted = 1100,
		VREvent_FirmwareUpdateFinished = 1101,

		VREvent_KeyboardClosed = 1200,
		VREvent_KeyboardCharInput = 1201,
		VREvent_KeyboardDone = 1202,  // Sent when DONE button clicked on keyboard

		VREvent_ApplicationTransitionStarted = 1300,
		VREvent_ApplicationTransitionAborted = 1301,
		VREvent_ApplicationTransitionNewAppStarted = 1302,
		VREvent_ApplicationListUpdated = 1303,
		VREvent_ApplicationMimeTypeLoad = 1304,
		VREvent_ApplicationTransitionNewAppLaunchComplete = 1305,
		VREvent_ProcessConnected = 1306,
		VREvent_ProcessDisconnected = 1307,

		VREvent_Compositor_MirrorWindowShown = 1400,
		VREvent_Compositor_MirrorWindowHidden = 1401,
		VREvent_Compositor_ChaperoneBoundsShown = 1410,
		VREvent_Compositor_ChaperoneBoundsHidden = 1411,

		VREvent_TrackedCamera_StartVideoStream = 1500,
		VREvent_TrackedCamera_StopVideoStream = 1501,
		VREvent_TrackedCamera_PauseVideoStream = 1502,
		VREvent_TrackedCamera_ResumeVideoStream = 1503,
		VREvent_TrackedCamera_EditingSurface = 1550,

		VREvent_PerformanceTest_EnableCapture = 1600,
		VREvent_PerformanceTest_DisableCapture = 1601,
		VREvent_PerformanceTest_FidelityLevel = 1602,

		VREvent_MessageOverlay_Closed = 1650,
		VREvent_MessageOverlayCloseRequested = 1651,

		VREvent_Input_HapticVibration = 1700,  // data is hapticVibration

		// Vendors are free to expose private events in this reserved region
		VREvent_VendorSpecific_Reserved_Start = 10000,
		VREvent_VendorSpecific_Reserved_End = 19999,
	};

	/** Level of Hmd activity */
	// UserInteraction_Timeout means the device is in the process of timing out.
	// InUse = ( k_EDeviceActivityLevel_UserInteraction || k_EDeviceActivityLevel_UserInteraction_Timeout )
	// VREvent_TrackedDeviceUserInteractionStarted fires when the devices transitions from Standby -> UserInteraction or Idle -> UserInteraction.
	// VREvent_TrackedDeviceUserInteractionEnded fires when the devices transitions from UserInteraction_Timeout -> Idle
	enum EDeviceActivityLevel
	{
		k_EDeviceActivityLevel_Unknown = -1,
		k_EDeviceActivityLevel_Idle = 0,                     // No activity for the last 10 seconds
		k_EDeviceActivityLevel_UserInteraction = 1,          // Activity (movement or prox sensor) is happening now
		k_EDeviceActivityLevel_UserInteraction_Timeout = 2,  // No activity for the last 0.5 seconds
		k_EDeviceActivityLevel_Standby = 3,                  // Idle for at least 5 seconds (configurable in Settings -> Power Management)
	};

	/** VR controller button and axis IDs */
	enum EVRButtonId
	{
		k_EButton_System = 0,
		k_EButton_ApplicationMenu = 1,
		k_EButton_Grip = 2,
		k_EButton_DPad_Left = 3,
		k_EButton_DPad_Up = 4,
		k_EButton_DPad_Right = 5,
		k_EButton_DPad_Down = 6,
		k_EButton_A = 7,

		k_EButton_ProximitySensor = 31,

		k_EButton_Axis0 = 32,
		k_EButton_Axis1 = 33,
		k_EButton_Axis2 = 34,
		k_EButton_Axis3 = 35,
		k_EButton_Axis4 = 36,

		// aliases for well known controllers
		k_EButton_SteamVR_Touchpad = k_EButton_Axis0,
		k_EButton_SteamVR_Trigger = k_EButton_Axis1,

		k_EButton_Dashboard_Back = k_EButton_Grip,

		k_EButton_Max = 64
	};

	inline std::uint64_t ButtonMaskFromId(EVRButtonId id) { return 1ull << id; }

	/** used for controller button events */
	struct VREvent_Controller_t
	{
		std::uint32_t button;  // EVRButtonId enum
	};

	/** used for simulated mouse events in overlay space */
	enum EVRMouseButton
	{
		VRMouseButton_Left = 0x0001,
		VRMouseButton_Right = 0x0002,
		VRMouseButton_Middle = 0x0004,
	};

	/** used for simulated mouse events in overlay space */
	struct VREvent_Mouse_t
	{
		float         x, y;    // co-ords are in GL space, bottom left of the texture is 0,0
		std::uint32_t button;  // EVRMouseButton enum
	};

	/** used for simulated mouse wheel scroll in overlay space */
	struct VREvent_Scroll_t
	{
		float         xdelta, ydelta;  // movement in fraction of the pad traversed since last delta, 1.0 for a full swipe
		std::uint32_t repeatCount;
	};

	/** when in mouse input mode you can receive data from the touchpad, these events are only sent if the users finger
	is on the touchpad (or just released from it). These events are sent to overlays with the VROverlayFlags_SendVRTouchpadEvents
	flag set.
	**/
	struct VREvent_TouchPadMove_t
	{
		// true if the users finger is detected on the touch pad
		bool bFingerDown;

		// How long the finger has been down in seconds
		float flSecondsFingerDown;

		// These values indicate the starting finger position (so you can do some basic swipe stuff)
		float fValueXFirst;
		float fValueYFirst;

		// This is the raw sampled coordinate without deadzoning
		float fValueXRaw;
		float fValueYRaw;
	};

	/** notification related events. Details will still change at this point */
	struct VREvent_Notification_t
	{
		std::uint64_t ulUserValue;
		std::uint32_t notificationId;
	};

	/** Used for events about processes */
	struct VREvent_Process_t
	{
		std::uint32_t pid;
		std::uint32_t oldPid;
		bool          bForced;
	};

	/** Used for a few events about overlays */
	struct VREvent_Overlay_t
	{
		std::uint64_t overlayHandle;
	};

	/** Used for a few events about overlays */
	struct VREvent_Status_t
	{
		std::uint32_t statusState;  // EVRState enum
	};

	/** Used for keyboard events **/
	struct VREvent_Keyboard_t
	{
		char          cNewInput[8];  // Up to 11 bytes of new input
		std::uint64_t uUserValue;    // Possible flags about the new input
	};

	struct VREvent_Ipd_t
	{
		float ipdMeters;
	};

	struct VREvent_Chaperone_t
	{
		std::uint64_t m_nPreviousUniverse;
		std::uint64_t m_nCurrentUniverse;
	};

	/** Not actually used for any events */
	struct VREvent_Reserved_t
	{
		std::uint64_t reserved0;
		std::uint64_t reserved1;
	};

	struct VREvent_PerformanceTest_t
	{
		std::uint32_t m_nFidelityLevel;
	};

	struct VREvent_SeatedZeroPoseReset_t
	{
		bool bResetBySystemMenu;
	};

	struct VREvent_Screenshot_t
	{
		std::uint32_t handle;
		std::uint32_t type;
	};

	struct VREvent_ScreenshotProgress_t
	{
		float progress;
	};

	struct VREvent_ApplicationLaunch_t
	{
		std::uint32_t pid;
		std::uint32_t unArgsHandle;
	};

	struct VREvent_EditingCameraSurface_t
	{
		std::uint64_t overlayHandle;
		std::uint32_t nVisualMode;
	};

	struct VREvent_MessageOverlay_t
	{
		std::uint32_t unVRMessageOverlayResponse;  // vr::VRMessageOverlayResponse enum
	};

	struct VREvent_Property_t
	{
		PropertyContainerHandle_t container;
		ETrackedDeviceProperty    prop;
	};

	enum EDualAnalogWhich
	{
		k_EDualAnalog_Left = 0,
		k_EDualAnalog_Right = 1,
	};

	struct VREvent_DualAnalog_t
	{
		float            x, y;                        // coordinates are -1..1 analog values
		float            transformedX, transformedY;  // transformed by the center and radius numbers provided by the overlay
		EDualAnalogWhich which;
	};

	struct VREvent_HapticVibration_t
	{
		std::uint64_t containerHandle;  // property container handle of the device with the haptic component
		std::uint64_t componentHandle;  // Which haptic component needs to vibrate
		float         fDurationSeconds;
		float         fFrequency;
		float         fAmplitude;
	};

	union VREvent_Data_t
	{
		VREvent_Reserved_t             reserved;
		VREvent_Controller_t           controller;
		VREvent_Mouse_t                mouse;
		VREvent_Scroll_t               scroll;
		VREvent_Process_t              process;
		VREvent_Notification_t         notification;
		VREvent_Overlay_t              overlay;
		VREvent_Status_t               status;
		VREvent_Keyboard_t             keyboard;
		VREvent_Ipd_t                  ipd;
		VREvent_Chaperone_t            chaperone;
		VREvent_PerformanceTest_t      performanceTest;
		VREvent_TouchPadMove_t         touchPadMove;
		VREvent_SeatedZeroPoseReset_t  seatedZeroPoseReset;
		VREvent_Screenshot_t           screenshot;
		VREvent_ScreenshotProgress_t   screenshotProgress;
		VREvent_ApplicationLaunch_t    applicationLaunch;
		VREvent_EditingCameraSurface_t cameraSurface;
		VREvent_MessageOverlay_t       messageOverlay;
		VREvent_Property_t             property;
		VREvent_DualAnalog_t           dualAnalog;
		VREvent_HapticVibration_t      hapticVibration;
	};

	/** An event posted by the server to all running applications */
	struct VREvent_t
	{
		std::uint32_t        eventType;  // EVREventType enum
		TrackedDeviceIndex_t trackedDeviceIndex;
		float                eventAgeSeconds;
		// event data must be the end of the struct as its size is variable
		VREvent_Data_t data;
	};
}
