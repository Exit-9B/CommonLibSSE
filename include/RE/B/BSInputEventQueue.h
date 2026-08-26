#pragma once

#include "RE/A/AmiiboEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/ButtonEvent.h"
#include "RE/C/CharEvent.h"
#include "RE/D/DeviceConnectEvent.h"
#include "RE/K/KinectEvent.h"
#include "RE/M/MotionGestureEvent.h"
#include "RE/M/MouseMoveEvent.h"
#include "RE/S/SixaxisEvent.h"
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
#if HAS_SKYRIMSE(1, 7, 99)
		inline static constexpr std::uint8_t MAX_SIXAXIS_EVENTS = 2;
		inline static constexpr std::uint8_t MAX_GESTURE_EVENTS = 2;
		inline static constexpr std::uint8_t MAX_AMIIBO_EVENTS = 1;
#endif
#if defined(SKYRIMVR)
		inline static constexpr std::uint8_t MAX_VR_TOUCHPAD_POSITION_EVENTS = 3;
		inline static constexpr std::uint8_t MAX_VR_TOUCHPAD_SWIPE_EVENTS = 3;
#endif

		static BSInputEventQueue* GetSingleton();

		template <class T>
		T* GetCachedEvent();

		template <class T>
		void AdvanceCount();

		template <class T, class... Args>
		void AddEvent(Args&&... args)
		{
			if (auto cachedEvent = GetCachedEvent<T>()) {
				cachedEvent->Init(std::forward<Args>(args)...);
				PushOntoInputQueue(cachedEvent);
				AdvanceCount<T>();
			}
		}

		template <class... Args>
		void AddButtonEvent(Args&&... args)
		{
			AddEvent<ButtonEvent>(std::forward<Args>(args)...);
		}

		template <class... Args>
		void AddCharEvent(Args&&... args)
		{
			AddEvent<CharEvent>(std::forward<Args>(args)...);
		}

		template <class... Args>
		void AddMouseMoveEvent(Args&&... args)
		{
			AddEvent<MouseMoveEvent>(std::forward<Args>(args)...);
		}

		template <class... Args>
		void AddThumbstickEvent(Args&&... args)
		{
			AddEvent<ThumbstickEvent>(std::forward<Args>(args)...);
		}

		template <class... Args>
		void AddConnectEvent(Args&&... args)
		{
			AddEvent<DeviceConnectEvent>(std::forward<Args>(args)...);
		}

		template <class... Args>
		void AddKinectEvent(Args&&... args)
		{
			AddEvent<KinectEvent>(std::forward<Args>(args)...);
		}

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
#if HAS_SKYRIMSE(1, 7, 99)
		std::uint32_t sixaxisEventCount;  // 01C
		std::uint32_t gestureEventCount;  // 020
		std::uint32_t amiiboEventCount;   // 024
#endif
#if defined(SKYRIMVR)
		std::uint32_t unkVR01C;
		std::uint32_t vrTouchpadPositionEventCount;
		std::uint32_t vrTouchpadSwipeEventCount;
#endif
		ButtonEvent        buttonEvents[MAX_BUTTON_EVENTS];          // 028
		CharEvent          charEvents[MAX_CHAR_EVENTS];              // 208
		MouseMoveEvent     mouseEvents[MAX_MOUSE_EVENTS];            // 2A8
		ThumbstickEvent    thumbstickEvents[MAX_THUMBSTICK_EVENTS];  // 2D8
		DeviceConnectEvent connectEvents[MAX_CONNECT_EVENTS];        // 338
		KinectEvent        kinectEvents[MAX_KINECT_EVENTS];          // 358
#if HAS_SKYRIMSE(1, 7, 99)
		SixaxisEvent       sixaxisEvents[MAX_SIXAXIS_EVENTS];  // 388
		MotionGestureEvent gestureEvents[MAX_GESTURE_EVENTS];  // 4A8
		AmiiboEvent        amiiboEvents[MAX_AMIIBO_EVENTS];    // 518
#endif
#if defined(SKYRIMVR)
		VrWandTouchpadPositionEvent vrTouchpadPositionEvents[MAX_VR_TOUCHPAD_POSITION_EVENTS];
		VrWandTouchpadSwipeEvent    vrTouchpadSwipeEvents[MAX_VR_TOUCHPAD_SWIPE_EVENTS];
#endif
		InputEvent* queueHead;  // 558
		InputEvent* queueTail;  // 560
	};
#if HAS_SKYRIMSE(1, 7, 99)
	static_assert(sizeof(BSInputEventQueue) == 0x568);
#elif !defined(SKYRIMVR)
	static_assert(sizeof(BSInputEventQueue) == 0x390);
#else
	static_assert(sizeof(BSInputEventQueue) == 0x580);
#endif
}
