#pragma once

namespace vr
{
	class IVRApplications;
	class IVRChaperone;
	class IVRChaperoneSetup;
	class IVRCompositor;
	class IVRDriverManager;
	class IVRExtendedDisplay;
	class IVROverlay;
	class IVRRenderModels;
	class IVRResources;
	class IVRScreenshots;
	class IVRSettings;
	class IVRSystem;
	class IVRTrackedCamera;

	class COpenVRContext
	{
	public:
		IVRSystem*          m_pVRSystem;           // 00
		IVRChaperone*       m_pVRChaperone;        // 08
		IVRChaperoneSetup*  m_pVRChaperoneSetup;   // 10
		IVRCompositor*      m_pVRCompositor;       // 18
		IVROverlay*         m_pVROverlay;          // 20
		IVRResources*       m_pVRResources;        // 28
		IVRRenderModels*    m_pVRRenderModels;     // 30
		IVRExtendedDisplay* m_pVRExtendedDisplay;  // 38
		IVRSettings*        m_pVRSettings;         // 40
		IVRApplications*    m_pVRApplications;     // 48
		IVRTrackedCamera*   m_pVRTrackedCamera;    // 50
		IVRScreenshots*     m_pVRScreenshots;      // 58
		IVRDriverManager*   m_pVRDriverManager;    // 60
	};
	static_assert(sizeof(COpenVRContext) == 0x68);
}
