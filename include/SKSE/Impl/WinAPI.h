#pragma once

namespace SKSE::WinAPI
{
	inline constexpr auto CP_UTF8{ static_cast<unsigned int>(65001) };
	inline constexpr auto IMAGE_SCN_MEM_EXECUTE{ static_cast<std::uint32_t>(0x20000000) };
	inline constexpr auto IMAGE_SCN_MEM_WRITE{ static_cast<std::uint32_t>(0x80000000) };
	inline const auto     INVALID_HANDLE_VALUE{ reinterpret_cast<void*>(static_cast<std::intptr_t>(-1)) };
	inline constexpr auto MAX_PATH{ static_cast<std::uint32_t>(260) };
	inline constexpr auto MEM_RELEASE{ static_cast<std::uint32_t>(0x00008000) };
	inline constexpr auto PAGE_EXECUTE_READWRITE{ static_cast<std::uint32_t>(0x40) };

	struct CRITICAL_SECTION
	{
	public:
		// members
		void*          DebugInfo;       // 00
		std::int32_t   LockCount;       // 08
		std::int32_t   RecursionCount;  // 0C
		void*          OwningThread;    // 10
		void*          LockSemaphore;   // 18
		std::uint64_t* SpinCount;       // 20
	};
	static_assert(sizeof(CRITICAL_SECTION) == 0x28);

	struct _FILETIME
	{
	public:
		// members
		std::uint32_t dwLowDateTime;   // 00
		std::uint32_t dwHighDateTime;  // 04
	};
	static_assert(sizeof(_FILETIME) == 0x8);
	using FILETIME = _FILETIME;

	struct HWND__;
	using HWND = HWND__*;

	struct HINSTANCE__;
	using HINSTANCE = HINSTANCE__*;

	struct _WIN32_FIND_DATAA
	{
	public:
		// members
		std::uint32_t dwFileAttributes;
		FILETIME      ftCreationTime;
		FILETIME      ftLastAccessTime;
		FILETIME      ftLastWriteTime;
		std::uint32_t nFileSizeHigh;
		std::uint32_t nFileSizeLow;
		std::uint32_t dwReserved0;
		std::uint32_t dwReserved1;
		char          cFileName[MAX_PATH];
		char          cAlternateFileName[14];
	};
	static_assert(sizeof(_WIN32_FIND_DATAA) == 0x140);
	using WIN32_FIND_DATAA = _WIN32_FIND_DATAA;

	using WNDPROC = std::intptr_t (*)(HWND, std::uint32_t, std::uintptr_t, std::intptr_t);

	enum struct GetWindowLongIndex
	{
		EXSTYLE = -20,
		HINSTANCE = -6,
		HWNDPARENT = -8,
		ID = -12,
		STYLE = -16,
		USERDATA = -21,
		WNDPROC = -4,
	};
	using GWL = GetWindowLongIndex;

	struct SECURITY_ATTRIBUTES
	{
		std::uint32_t Length;              // 00
		void*         SecurityDescriptor;  // 08
		std::int32_t  InheritHandle;       // 10
	};
	static_assert(sizeof(SECURITY_ATTRIBUTES) == 0x18);

	struct HandleCloser
	{
		void operator()(void* a_handle) const noexcept;
	};

	using ScopedHandle = std::unique_ptr<void, HandleCloser>;

	struct _GUID
	{
		constexpr auto operator<=>(const _GUID&) const noexcept = default;

		// members
		std::uint32_t Data1;     // 00
		std::uint16_t Data2;     // 04
		std::uint16_t Data3;     // 06
		std::uint8_t  Data4[8];  // 08
	};
	static_assert(sizeof(_GUID) == 0x10);
	using GUID = _GUID;
	using IID = GUID;
	using REFIID = const IID&;
	using CLSID = GUID;
	using REFCLSID = const IID&;

	namespace DBT
	{
		enum DeviceChangeMessage : std::uintptr_t
		{
			DEVICEARRIVAL = 0x8000,
			DEVICEQUERYREMOVE = 0x8001,
			DEVICEQUERYREMOVEFAILED = 0x8002,
			DEVICEREMOVEPENDING = 0x8003,
			DEVICEREMOVECOMPLETE = 0x8004,
			DEVICETYPESPECIFIC = 0x8005,
		};

		enum struct DeviceType : std::uint32_t
		{
			OEM = 0x00000000,
			DEVNODE = 0x00000001,
			VOLUME = 0x00000002,
			PORT = 0x00000003,
			NET = 0x00000004,
			DEVICEINTERFACE = 0x00000005,
			HANDLE = 0x00000006,
		};
		using DEVTYP = DeviceType;
	};

	struct _DEV_BROADCAST_HDR
	{
		std::uint32_t   dbch_size;        // 0
		DBT::DeviceType dbch_devicetype;  // 4
		std::uint32_t   dbch_reserved;    // 8
	};
	static_assert(sizeof(_DEV_BROADCAST_HDR) == 0xC);
	using DEV_BROADCAST_HDR = _DEV_BROADCAST_HDR;

	struct _DEV_BROADCAST_DEVICEINTERFACE_A
	{
		std::uint32_t   dbcc_size;        // 00
		DBT::DeviceType dbcc_devicetype;  // 04
		std::uint32_t   dbcc_reserved;    // 08
		GUID            dbcc_classguid;   // 0C
		char            dbcc_name[1];     // 1C
	};
	static_assert(sizeof(_DEV_BROADCAST_DEVICEINTERFACE_A) == 0x20);
	using DEV_BROADCAST_DEVICEINTERFACE_A = _DEV_BROADCAST_DEVICEINTERFACE_A;
	using DEV_BROADCAST_DEVICEINTERFACE = DEV_BROADCAST_DEVICEINTERFACE_A;

	struct DEVICE_NOTIFY
	{
		enum Flags
		{
			WINDOW_HANDLE = 0x00000000,
			SERVICE_HANDLE = 0x00000001,

			ALL_INTERFACE_CLASSES = 0x00000004,
		};
	};

	struct DeviceNotifyCloser
	{
		void operator()(void* handle) const noexcept;
	};

	using ScopedDeviceNotify = std::unique_ptr<void, DeviceNotifyCloser>;

	[[nodiscard]] std::intptr_t CallWindowProc(
		WNDPROC        a_prevWndFunc,
		void*          a_wnd,
		std::uint32_t  a_msg,
		std::uintptr_t a_wParam,
		std::intptr_t  a_lParam);

	[[nodiscard]] ScopedHandle CreateEventEx(
		SECURITY_ATTRIBUTES* a_eventAttributes,
		char*                a_name,
		std::uint32_t        a_flags,
		std::uint32_t        a_desiredAccess);

	[[nodiscard]] ScopedHandle CreateEventEx(
		SECURITY_ATTRIBUTES* a_eventAttributes,
		wchar_t*             a_name,
		std::uint32_t        a_flags,
		std::uint32_t        a_desiredAccess);

	[[nodiscard]] void* GetCurrentModule() noexcept;

	[[nodiscard]] void* GetCurrentProcess() noexcept;

	[[nodiscard]] std::uint32_t GetCurrentThreadID() noexcept;

	[[nodiscard]] std::uint32_t GetEnvironmentVariable(
		const char*   a_name,
		char*         a_buffer,
		std::uint32_t a_size) noexcept;

	[[nodiscard]] std::uint32_t GetEnvironmentVariable(
		const wchar_t* a_name,
		wchar_t*       a_buffer,
		std::uint32_t  a_size) noexcept;

	[[nodiscard]] bool GetFileVersionInfo(
		const char*   a_filename,
		std::uint32_t a_handle,
		std::uint32_t a_len,
		void*         a_data) noexcept;

	[[nodiscard]] bool GetFileVersionInfo(
		const wchar_t* a_filename,
		std::uint32_t  a_handle,
		std::uint32_t  a_len,
		void*          a_data) noexcept;

	[[nodiscard]] std::uint32_t GetFileVersionInfoSize(
		const char*    a_filename,
		std::uint32_t* a_handle) noexcept;

	[[nodiscard]] std::uint32_t GetFileVersionInfoSize(
		const wchar_t* a_filename,
		std::uint32_t* a_handle) noexcept;

	[[nodiscard]] std::size_t GetMaxPath() noexcept;

	std::uint32_t GetModuleFileName(
		void*         a_module,
		char*         a_filename,
		std::uint32_t a_size) noexcept;

	std::uint32_t GetModuleFileName(
		void*         a_module,
		wchar_t*      a_filename,
		std::uint32_t a_size) noexcept;

	[[nodiscard]] void* GetModuleHandle(const char* a_moduleName) noexcept;

	[[nodiscard]] void* GetModuleHandle(const wchar_t* a_moduleName) noexcept;

	[[nodiscard]] void* GetProcAddress(
		void*       a_module,
		const char* a_procName) noexcept;

	std::intptr_t GetWindowLongPtr(
		HWND               a_wnd,
		GetWindowLongIndex a_index) noexcept;

	std::int32_t MessageBox(
		void*        a_wnd,
		const char*  a_text,
		const char*  a_caption,
		unsigned int a_type) noexcept;

	std::int32_t MessageBox(
		void*          a_wnd,
		const wchar_t* a_text,
		const wchar_t* a_caption,
		unsigned int   a_type) noexcept;

	int MultiByteToWideChar(
		unsigned int  a_codePage,
		std::uint32_t a_flags,
		const char*   a_multiByteStr,
		int           a_multiByte,
		wchar_t*      a_wideCharStr,
		int           a_wideChar);

	void OutputDebugString(
		const char* a_outputString) noexcept;

	void OutputDebugString(
		const wchar_t* a_outputString) noexcept;

	[[nodiscard]] ScopedDeviceNotify RegisterDeviceNotification(
		void*         a_recipient,
		void*         a_notificationFilter,
		std::uint32_t a_flags) noexcept;

	bool SetEvent(ScopedHandle& a_event) noexcept;

	std::intptr_t SetWindowLongPtr(
		HWND               a_wnd,
		GetWindowLongIndex a_index,
		std::intptr_t      a_newLong) noexcept;

	void* SetWindowLongPtr(
		HWND               a_wnd,
		GetWindowLongIndex a_index,
		void*              a_newLong) noexcept;

	[[noreturn]] void TerminateProcess(
		void*        a_process,
		unsigned int a_exitCode) noexcept;

	[[nodiscard]] void* TlsGetValue(std::uint32_t a_tlsIndex) noexcept;

	bool TlsSetValue(
		std::uint32_t a_tlsIndex,
		void*         a_tlsValue) noexcept;

	bool VirtualFree(
		void*         a_address,
		std::size_t   a_size,
		std::uint32_t a_freeType) noexcept;

	[[nodiscard]] bool VerQueryValue(
		const void*   a_block,
		const char*   a_subBlock,
		void**        a_buffer,
		unsigned int* a_len) noexcept;

	[[nodiscard]] bool VerQueryValue(
		const void*    a_block,
		const wchar_t* a_subBlock,
		void**         a_buffer,
		unsigned int*  a_len) noexcept;

	[[nodiscard]] bool VirtualProtect(
		void*          a_address,
		std::size_t    a_size,
		std::uint32_t  a_newProtect,
		std::uint32_t* a_oldProtect) noexcept;

	std::uint32_t WaitForMultipleObjectsEx(
		std::span<void* const> a_handles,
		bool                   a_waitAll,
		std::uint32_t          a_milliseconds,
		bool                   a_alertable);

	std::uint32_t WaitForSingleObjectEx(
		ScopedHandle& a_handle,
		std::uint32_t a_milliseconds,
		bool          a_alertable) noexcept;

	[[nodiscard]] int WideCharToMultiByte(
		unsigned int   a_codePage,
		std::uint32_t  a_flags,
		const wchar_t* a_wideCharStr,
		int            a_wideChar,
		char*          a_multiByteStr,
		int            a_multiByte,
		const char*    a_defaultChar,
		int*           a_usedDefaultChar);
}

namespace RE::DirectX
{
	struct XMFLOAT4X4
	{
	public:
		// members
		float m[4][4];
	};
	static_assert(sizeof(XMFLOAT4X4) == 0x40);
}

namespace RE::XInput
{
	struct XINPUT_GAMEPAD
	{
	public:
		std::uint16_t wButtons;       // 0
		std::uint8_t  bLeftTrigger;   // 2
		std::uint8_t  bRightTrigger;  // 3
		std::int16_t  sThumbLX;       // 4
		std::int16_t  sThumbLY;       // 6
		std::int16_t  sThumbRX;       // 8
		std::int16_t  sThumbRY;       // A
	};
	static_assert(sizeof(XINPUT_GAMEPAD) == 0xC);

	struct XINPUT_STATE
	{
	public:
		std::uint32_t  dwPacketNumber;  // 00
		XINPUT_GAMEPAD Gamepad;         // 04
	};
	static_assert(sizeof(XINPUT_STATE) == 0x10);

	struct XINPUT_VIBRATION
	{
		std::uint16_t wLeftMotorSpeed;   // 0
		std::uint16_t wRightMotorSpeed;  // 2
	};
	static_assert(sizeof(XINPUT_VIBRATION) == 0x4);
}
