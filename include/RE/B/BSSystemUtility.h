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
		BSEventNotifyControl ProcessEvent(const BSGamepadEvent* a_event, BSTEventSource<BSGamepadEvent>* a_eventSource);  // 01

		// add
		virtual void GetAuthenticationInfo(char*& userAuthID, std::uint64_t& size);  // 02
		virtual void Func03(void);                                                   // 03
		virtual void DoInitialize();                                                 // 04
		virtual void Func05(void);                                                   // 05
		virtual void DoUpdate();                                                     // 06
		virtual void Func07(void);                                                   // 07
		virtual void DoGetUserName(char* buffer, std::uint64_t size);                // 08
		virtual void Func09(void);                                                   // 09
		virtual void Func0A(void);                                                   // 0A
		virtual void Func0B(void);                                                   // 0B
		virtual void Func0C(void);                                                   // 0C
		virtual void DoGetComputerName(char* buffer, std::uint64_t size);            // 0D
		virtual void Func0E(void);                                                   // 0E
		virtual void Func0F(void);                                                   // 0F
		virtual void DoAuthenticateUser();                                           // 10
		virtual void Func11(void);                                                   // 11
		virtual bool Func12();                                                       // 12 - added in 1.6.1130

		// members
		std::uint64_t unk060[24];  // 060
		std::uint8_t  unk120;      // 120 - added in 1.6.1130
		std::uint8_t  unk121;      // 121 - added in 1.6.1130
		std::uint16_t pad122;      // 122
		std::uint32_t pad124;      // 124
	};
	static_assert(sizeof(BSSystemUtility) == 0x128);
}
