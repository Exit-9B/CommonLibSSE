#pragma once

using SteamAPICall_t = std::uint64_t;

namespace RE
{
	class CCallbackBase
	{
	public:
		enum
		{
			k_ECallbackFlagsRegistered = 0x01,
			k_ECallbackFlagsGameServer = 0x02
		};

		virtual void Run(void* vParam);                                               // 01
		virtual void Run(void* vParam, bool ioFailure, SteamAPICall_t steamAPICall);  // 00
		virtual int  GetCallbackSizeBytes();                                          // 02

		// members
		std::uint8_t  callbackFlags;  // 08
		std::uint8_t  pad09;          // 09
		std::uint16_t pad0A;          // 0A
		std::int32_t  iCallback;      // 0C
	};
	static_assert(sizeof(CCallbackBase) == 0x10);

	template <class T, class P>
	class CCallResult : public CCallbackBase
	{
	public:
		using func_t = void (T::*)(P*);

		// override (CCallbackBase)
		void Run(void* vParam) override;                                               // 01
		void Run(void* vParam, bool ioFailure, SteamAPICall_t steamAPICall) override;  // 00
		int  GetCallbackSizeBytes() override;                                          // 02

		SteamAPICall_t apiCall;  // 10
		T*             obj;      // 18
		func_t         func;     // 20
	};
	// size == 0x30

	template <class T, class P, bool bGameserver = false>
	class CCallback : public CCallbackBase
	{
	public:
		using func_t = void (T::*)(P*);

		// override (CCallbackBase)
		void Run(void* vParam) override;                                               // 01
		void Run(void* vParam, bool ioFailure, SteamAPICall_t steamAPICall) override;  // 00
		int  GetCallbackSizeBytes() override;                                          // 02

		// add
		virtual ~CCallback();  // 03

		// members
		T*     pObj;  // 10
		func_t func;  // 18
	};
	// size == 0x28
}
