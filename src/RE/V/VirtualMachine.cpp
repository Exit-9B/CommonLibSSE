#include "RE/V/VirtualMachine.h"

#include "RE/S/SkyrimVM.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			VirtualMachine* VirtualMachine::GetSingleton()
			{
				auto vm = SkyrimVM::GetSingleton();
				if (!vm) {
					return nullptr;
				}

				const auto data = vm->SkyrimVMData();
				return static_cast<VirtualMachine*>(data->impl.get());
			}
		}
	}
}
