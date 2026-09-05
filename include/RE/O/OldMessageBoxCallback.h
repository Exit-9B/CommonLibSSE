#pragma once

#include "RE/I/IMessageBoxCallback.h"

namespace RE
{
	class OldMessageBoxCallback : public IMessageBoxCallback
	{
	public:
		inline static constexpr auto RTTI = RTTI___OldMessageBoxCallback;

		using Callback = void(std::int8_t);

		~OldMessageBoxCallback() override;  // 00

		// override (IMessageBoxCallback)
		void operator()(std::int8_t a_msg) override;  // 01

		// members
		Callback* callback;  // 10
	};
	static_assert(sizeof(OldMessageBoxCallback) == 0x18);
}
