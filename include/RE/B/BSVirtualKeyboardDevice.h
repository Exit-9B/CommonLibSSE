#pragma once

#include "RE/B/BSKeyboardDevice.h"

namespace RE
{
	class BSVirtualKeyboardDevice : public BSKeyboardDevice
	{
	public:
		struct kbInfo
		{
			using DoneCallback = void(void*, const char*);
			using CancelCallback = void();

			const char*     startingText;    // 00
			DoneCallback*   doneCallback;    // 08
			CancelCallback* cancelCallback;  // 10
			void*           userParam;       // 18
			std::uint32_t   maxChars;        // 20
		};

		inline static constexpr auto RTTI = RTTI_BSVirtualKeyboardDevice;

		~BSVirtualKeyboardDevice() override;  // 00

		// override (BSKeyboardDevice)
		void Unk_09(void) override;  // 09 - { return; }
		void Unk_0A(void) override;  // 0A - { return; }

		// add
		virtual void Start(const kbInfo* a_info) = 0;  // 0B
		virtual void Stop() = 0;                       // 0C
		virtual void UserCancelled() = 0;              // 0D
	};
	static_assert(sizeof(BSVirtualKeyboardDevice) == 0x70);
}
