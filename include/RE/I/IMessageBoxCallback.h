#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class IMessageBoxCallback : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMessageBoxCallback;

		virtual ~IMessageBoxCallback() = default;  // 00

		// add
		virtual void operator()(std::int8_t a_msg) = 0;  // 01

		// members
		std::uint32_t unk0C;  // 0C
	};
	static_assert(sizeof(IMessageBoxCallback) == 0x10);
}
