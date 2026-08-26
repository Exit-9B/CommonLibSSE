#pragma once

namespace RE
{
	class ButtonEvent;
	class InputEvent;
	class MotionGestureEvent;
	class MouseMoveEvent;
	class PlayerControlsData;
	class SixaxisEvent;
	class ThumbstickEvent;

	class PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_PlayerInputHandler;

		virtual ~PlayerInputHandler();  // 00

		virtual bool CanProcess(InputEvent* a_event) = 0;                                // 01
		virtual void HandleEvent(ButtonEvent* a_event, PlayerControlsData* a_data);      // 06
		virtual void HandleEvent(MouseMoveEvent* a_event, PlayerControlsData* a_data);   // 05
		virtual void HandleEvent(ThumbstickEvent* a_event, PlayerControlsData* a_data);  // 04
#if HAS_SKYRIMSE(1, 7, 99)
		virtual void HandleEvent(SixaxisEvent* a_event, PlayerControlsData* a_data);        // 03
		virtual void HandleEvent(MotionGestureEvent* a_event, PlayerControlsData* a_data);  // 02
#endif

		[[nodiscard]] bool IsInputEventHandlingEnabled() const;
		void               SetInputEventHandlingEnabled(bool a_enabled);

		// members
		bool          inputEventHandlingEnabled;  // 08
		std::uint8_t  pad09;                      // 09
		std::uint16_t pad0A;                      // 0A
		std::uint32_t pad0C;                      // 0C
	};
	static_assert(sizeof(PlayerInputHandler) == 0x10);
}
