#include "SKSE/PapyrusInterface.h"

#include "SKSE/Logger.h"

namespace SKSE
{
	bool PapyrusInterface::Register_Impl(RegFunction1* a_fn) const
	{
		assert(a_fn);
		auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
		if (vm) {
			a_fn(vm);
			return true;
		} else {
			auto result = GetProxy()->Register(reinterpret_cast<void*>(a_fn));
			if (!result) {
				log::error("Failed to register for papyrus interface");
			}
			return result;
		}
	}

	bool PapyrusInterface::Register_Impl(RegFunction2* a_fn) const
	{
		assert(a_fn);
		auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
		if (vm) {
			a_fn(vm);
			return true;
		} else {
			auto result = GetProxy()->Register(reinterpret_cast<void*>(a_fn));
			if (!result) {
				log::error("Failed to register for papyrus interface");
			}
			return result;
		}
	}
}
