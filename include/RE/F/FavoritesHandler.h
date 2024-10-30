#pragma once

#include "RE/M/MenuEventHandler.h"

namespace RE
{
	struct FavoritesHandler : public MenuEventHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_FavoritesHandler;

		~FavoritesHandler() override;  // 00

		// add
		bool ShouldHandleEvent(const InputEvent* a_event) override;  // 01
		bool HandleEvent(const ButtonEvent* a_event) override;       // 05
		bool HandleEvent(const KinectEvent* a_event) override;       // 02
	};
	static_assert(sizeof(FavoritesHandler) == 0x10);
}
