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

				// HACK: Temporary workaround to support GOG version.
				auto p = &vm->impl;
#if !defined(SKYRIMVR)
				if (REL::Module::get().version() < SKSE::RUNTIME_1_7_99) {
					p = reinterpret_cast<BSTSmartPointer<BSScript::IVirtualMachine>*>(reinterpret_cast<std::byte*>(vm) + 0x200);
				}
#endif
				return static_cast<VirtualMachine*>(p->get());
			}
		}
	}
}
