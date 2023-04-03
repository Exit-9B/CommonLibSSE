#include "RE/B/BSInputEventQueue.h"

namespace RE
{
	BSInputEventQueue* BSInputEventQueue::GetSingleton()
	{
		REL::Relocation<BSInputEventQueue**> singleton{ Offset::BSInputEventQueue::Singleton };
		return *singleton;
	}

	void BSInputEventQueue::PushOntoInputQueue(InputEvent* a_event)
	{
		if (!queueHead) {
			queueHead = a_event;
		}

		if (queueTail) {
			queueTail->next = a_event;
		}

		queueTail = a_event;
		queueTail->next = nullptr;
	}

	void BSInputEventQueue::ClearInputQueue()
	{
		kinectEventCount = 0;
		connectEventCount = 0;
		thumbstickEventCount = 0;
		mouseEventCount = 0;
		charEventCount = 0;
		buttonEventCount = 0;
#ifdef SKYRIMVR
		vrTouchpadSwipeEventCount = 0;
		vrTouchpadPositionEventCount = 0;
		unkVR01C = 0;
#endif
		queueTail = nullptr;
		queueHead = nullptr;
	}
}
