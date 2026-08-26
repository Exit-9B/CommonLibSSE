#include "RE/M/MenuEventHandler.h"

namespace RE
{
	bool MenuEventHandler::HandleEvent(const ButtonEvent*)
	{
		return false;
	}

	bool MenuEventHandler::HandleEvent(const MouseMoveEvent*)
	{
		return false;
	}

	bool MenuEventHandler::HandleEvent(const ThumbstickEvent*)
	{
		return false;
	}

	bool MenuEventHandler::HandleEvent(const KinectEvent*)
	{
		return false;
	}

#if HAS_SKYRIMSE(1, 7, 99)
	bool MenuEventHandler::HandleEvent(const SixaxisEvent*)
	{
		return false;
	}

	bool MenuEventHandler::HandleEvent(const MotionGestureEvent*)
	{
		return false;
	}
#endif

#if defined(SKYRIMVR)
	bool MenuEventHandler::HandleEvent(const VRWandEvent*)
	{
		return false;
	}

	bool MenuEventHandler::HandleEvent(const VrWandTouchpadPositionEvent*)
	{
		return false;
	}

	bool MenuEventHandler::HandleEvent(const VrWandTouchpadSwipeEvent*)
	{
		return false;
	}
#endif
}
