#pragma once

namespace RE
{
	class NiAVObject;

	class TaskQueueInterface
	{
	public:
		static TaskQueueInterface* GetSingleton();

		void Attach3D(NiAVObject* a_obj, NiAVObject* a_root, bool a_arg3 = true, bool a_arg4 = false);
	};
	//static_assert(sizeof(TaskQueueInterface) == 0x);
}
