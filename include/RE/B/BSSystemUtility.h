#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class BSSystemEvent;
	struct BSGamepadEvent;

	class BSSystemUtility :
		public BSTEventSink<BSGamepadEvent>,  // 000
		public BSTEventSource<BSSystemEvent>  // 008
	{
	public:
		virtual ~BSSystemUtility();  // 00

		// override (BSTEventSink<BSGamepadEvent>)
		BSEventNotifyControl ProcessEvent(const BSGamepadEvent* a_event, BSTEventSource<BSGamepadEvent>* a_eventSource) override;  // 01

		// add
#if HAS_SKYRIMSE(1, 7, 99)
		virtual void Unk_02(void);  // 02
#endif
		virtual void GetAuthenticationInfo(char*& a_userAuthID, std::uint64_t& a_size);  // 03
		virtual void Unk_04(void);                                                       // 04
		virtual void DoInitialize();                                                     // 05
		virtual void Unk_06(void);                                                       // 06
		virtual void DoUpdate();                                                         // 07
		virtual void Unk_08(void);                                                       // 08
		virtual void DoGetUserName(char* a_buffer, std::uint64_t a_size);                // 09
		virtual void Unk_0A(void);                                                       // 0A
		virtual void Unk_0B(void);                                                       // 0B
		virtual void Unk_0C(void);                                                       // 0C
		virtual void Unk_0D(void);                                                       // 0D
		virtual void DoGetComputerName(char* a_buffer, std::uint64_t a_size);            // 0E
		virtual void Unk_0F(void);                                                       // 0F
		virtual void Unk_10(void);                                                       // 10
		virtual void DoAuthenticateUser();                                               // 11
		virtual void Unk_12(void);                                                       // 12
#if HAS_SKYRIMSE(1, 6, 1130)
		virtual bool Unk_13();  // 13
#endif

		[[nodiscard]] static BSSystemUtility* GetSingleton();

		// members
		std::uint64_t unk060[24];  // 060
#if HAS_SKYRIMSE(1, 6, 1130)
		std::uint8_t unk120;  // 120
		std::uint8_t unk121;  // 121
#endif
	};
#if HAS_SKYRIMSE(1, 6, 1130)
	static_assert(sizeof(BSSystemUtility) == 0x128);
#else
	static_assert(sizeof(BSSystemUtility) == 0x120);
#endif
}
