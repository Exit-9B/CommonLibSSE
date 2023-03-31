#pragma once

#include "RE/B/BSTSingleton.h"
#include "RE/B/ButtonEvent.h"
#include "RE/C/CharEvent.h"
#include "RE/D/DeviceConnectEvent.h"
#include "RE/K/KinectEvent.h"
#include "RE/M/MouseMoveEvent.h"
#include "RE/T/ThumbstickEvent.h"
#include "RE/V/VrWandTouchpadPositionEvent.h"
#include "RE/V/VrWandTouchpadSwipeEvent.h"

namespace RE
{
	class BSInputEventQueue : public BSTSingletonSDM<BSInputEventQueue>
	{
	public:
		inline static constexpr std::uint8_t MAX_BUTTON_EVENTS = 10;
		inline static constexpr std::uint8_t MAX_CHAR_EVENTS = 5;
		inline static constexpr std::uint8_t MAX_MOUSE_EVENTS = 1;
		inline static constexpr std::uint8_t MAX_THUMBSTICK_EVENTS = 2;
		inline static constexpr std::uint8_t MAX_CONNECT_EVENTS = 1;
		inline static constexpr std::uint8_t MAX_KINECT_EVENTS = 1;
#ifdef SKYRIMVR
		inline static constexpr std::uint8_t MAX_VR_TOUCHPAD_POSITION_EVENTS = 3;
		inline static constexpr std::uint8_t MAX_VR_TOUCHPAD_SWIPE_EVENTS = 3;
#endif

		static BSInputEventQueue* GetSingleton();

		void AddButtonEvent(INPUT_DEVICE a_device, std::int32_t a_id, float a_value, float a_duration);
		void AddCharEvent(std::uint32_t a_keyCode);
		void AddMouseMoveEvent(std::int32_t a_mouseInputX, std::int32_t a_mouseInputY);
		void AddThumbstickEvent(ThumbstickEvent::InputType a_id, float a_xValue, float a_yValue);
		void AddConnectEvent(INPUT_DEVICE a_device, bool a_connected);
		void AddKinectEvent(const BSFixedString& a_userEvent, const BSFixedString& a_heard);
#ifdef SKYRIMVR
		void AddButtonEvent(INPUT_DEVICE a_device, std::int32_t a_arg2, std::int32_t a_id, float a_value, float a_duration);
		void AddThumbstickEvent(ThumbstickEvent::InputType a_id, INPUT_DEVICE a_device, float a_xValue, float a_yValue);
#endif
		void PushOntoInputQueue(InputEvent* a_event);
		void ClearInputQueue();

		// members
		std::uint8_t  pad001;                // 001
		std::uint16_t pad002;                // 002
		std::uint32_t buttonEventCount;      // 004
		std::uint32_t charEventCount;        // 008
		std::uint32_t mouseEventCount;       // 00C
		std::uint32_t thumbstickEventCount;  // 010
		std::uint32_t connectEventCount;     // 014
		std::uint32_t kinectEventCount;      // 018
#ifndef SKYRIMVR
		std::uint32_t pad01C;  // 01C
#else
		std::uint32_t unkVR01C;
		std::uint32_t vrTouchpadPositionEventCount;
		std::uint32_t vrTouchpadSwipeEventCount;
#endif
		ButtonEvent        buttonEvents[MAX_BUTTON_EVENTS];          // 020
		CharEvent          charEvents[MAX_CHAR_EVENTS];              // 200
		MouseMoveEvent     mouseEvents[MAX_MOUSE_EVENTS];            // 2A0
		ThumbstickEvent    thumbstickEvents[MAX_THUMBSTICK_EVENTS];  // 2D0
		DeviceConnectEvent connectEvents[MAX_CONNECT_EVENTS];        // 330
		KinectEvent        kinectEvents[MAX_KINECT_EVENTS];          // 350
#ifdef SKYRIMVR
		VrWandTouchpadPositionEvent vrTouchpadPositionEvents[MAX_VR_TOUCHPAD_POSITION_EVENTS];
		VrWandTouchpadSwipeEvent    vrTouchpadSwipeEvents[MAX_VR_TOUCHPAD_SWIPE_EVENTS];
#endif
		InputEvent* queueHead;  // 380
		InputEvent* queueTail;  // 388
	};
#ifndef SKYRIMVR
	static_assert(sizeof(BSInputEventQueue) == 0x390);
#else
	static_assert(sizeof(BSInputEventQueue) == 0x580);
#endif
}
