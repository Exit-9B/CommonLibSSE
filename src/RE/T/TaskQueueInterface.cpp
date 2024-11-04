#include "RE/T/TaskQueueInterface.h"

namespace RE
{
	TaskQueueInterface* TaskQueueInterface::GetSingleton()
	{
		REL::Relocation<TaskQueueInterface**> singleton{ STATIC_OFFSET(TaskQueueInterface::Singleton) };
		return *singleton;
	}

	void TaskQueueInterface::Attach3D(NiAVObject* a_obj, NiAVObject* a_root, bool a_arg3, bool a_arg4)
	{
		using func_t = decltype(&TaskQueueInterface::Attach3D);
		REL::Relocation<func_t> func{ STATIC_OFFSET(TaskQueueInterface::Attach3D) };
		return func(this, a_obj, a_root, a_arg3, a_arg4);
	}
}
