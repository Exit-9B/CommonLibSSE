#pragma once

namespace vr
{
	/** Used to return the post-distortion UVs for each color channel. 
	* UVs range from 0 to 1 with 0,0 in the upper left corner of the 
	* source render target. The 0,0 to 1,1 range covers a single eye. */
	struct DistortionCoordinates_t
	{
		float rfRed[2];
		float rfGreen[2];
		float rfBlue[2];
	};

	enum EVREye
	{
		Eye_Left = 0,
		Eye_Right = 1
	};

	enum ETextureType
	{
		TextureType_DirectX = 0,    // Handle is an ID3D11Texture
		TextureType_OpenGL = 1,     // Handle is an OpenGL texture name or an OpenGL render buffer name, depending on submit flags
		TextureType_Vulkan = 2,     // Handle is a pointer to a VRVulkanTextureData_t structure
		TextureType_IOSurface = 3,  // Handle is a macOS cross-process-sharable IOSurfaceRef
		TextureType_DirectX12 = 4,  // Handle is a pointer to a D3D12TextureData_t structure
	};

	enum EColorSpace
	{
		ColorSpace_Auto = 0,    // Assumes 'gamma' for 8-bit per component formats, otherwise 'linear'.  This mirrors the DXGI formats which have _SRGB variants.
		ColorSpace_Gamma = 1,   // Texture data can be displayed directly on the display without any conversion (a.k.a. display native format).
		ColorSpace_Linear = 2,  // Same as gamma but has been converted to a linear representation using DXGI's sRGB conversion algorithm.
	};

	struct Texture_t
	{
		void*        handle;  // See ETextureType definition above
		ETextureType eType;
		EColorSpace  eColorSpace;
	};

	/** Used to pass device IDs to API calls */
	using TrackedDeviceIndex_t = std::uint32_t;

	/** used to refer to a single VR overlay */
	using VROverlayHandle_t = std::uint64_t;

	/** Identifies which style of tracking origin the application wants to use
	* for the poses it is requesting */
	enum ETrackingUniverseOrigin
	{
		TrackingUniverseSeated = 0,              // Poses are provided relative to the seated zero pose
		TrackingUniverseStanding = 1,            // Poses are provided relative to the safe bounds configured by the user
		TrackingUniverseRawAndUncalibrated = 2,  // Poses are provided in the coordinate system defined by the driver.  It has Y up and is unified for devices of the same driver. You usually don't want this one.
	};

	/** Errors that can occur around VR overlays */
	enum EVROverlayError
	{
		VROverlayError_None = 0,

		VROverlayError_UnknownOverlay = 10,
		VROverlayError_InvalidHandle = 11,
		VROverlayError_PermissionDenied = 12,
		VROverlayError_OverlayLimitExceeded = 13,  // No more overlays could be created because the maximum number already exist
		VROverlayError_WrongVisibilityType = 14,
		VROverlayError_KeyTooLong = 15,
		VROverlayError_NameTooLong = 16,
		VROverlayError_KeyInUse = 17,
		VROverlayError_WrongTransformType = 18,
		VROverlayError_InvalidTrackedDevice = 19,
		VROverlayError_InvalidParameter = 20,
		VROverlayError_ThumbnailCantBeDestroyed = 21,
		VROverlayError_ArrayTooSmall = 22,
		VROverlayError_RequestFailed = 23,
		VROverlayError_InvalidTexture = 24,
		VROverlayError_UnableToLoadFile = 25,
		VROverlayError_KeyboardAlreadyInUse = 26,
		VROverlayError_NoNeighbor = 27,
		VROverlayError_TooManyMaskPrimitives = 29,
		VROverlayError_BadMaskPrimitive = 30,
		VROverlayError_TextureAlreadyLocked = 31,
		VROverlayError_TextureLockCapacityReached = 32,
		VROverlayError_TextureNotLocked = 33,
	};

	/** Allows the application to control what part of the provided texture will be used in the
	* frame buffer. */
	struct VRTextureBounds_t
	{
		float uMin, vMin;
		float uMax, vMax;
	};
}
