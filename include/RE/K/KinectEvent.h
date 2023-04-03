#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/I/IDEvent.h"

namespace RE
{
	class KinectEvent : public IDEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_KinectEvent;

		~KinectEvent() override;  // 00

		void Init(const BSFixedString& a_userEvent, const BSFixedString& a_heard)
		{
			userEvent = a_userEvent;
			heard = a_heard;
		}

		// members
		BSFixedString heard;  // 28
	};
	static_assert(sizeof(KinectEvent) == 0x30);
}
