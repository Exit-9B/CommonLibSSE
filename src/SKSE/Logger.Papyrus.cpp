#include "SKSE/Logger.h"

#include "SKSE/API.h"

#include "RE/V/VirtualMachine.h"

namespace SKSE
{
	void add_papyrus_sink(std::regex a_filter)
	{
		auto handler = Impl::LogEventHandler::GetSingleton();
		handler->SetFilter(std::move(a_filter));

		SKSE::RegisterForAPIInitEvent([]() {
			auto papyrus = SKSE::GetPapyrusInterface();
			if (papyrus) {
				papyrus->Register([](RE::BSScript::IVirtualMachine* a_vm) {
					auto handler = Impl::LogEventHandler::GetSingleton();
					a_vm->RegisterForLogEvent(handler);
					return true;
				});
			}
		});
	}

	void remove_papyrus_sink()
	{
		SKSE::RegisterForAPIInitEvent([]() {
			auto papyrus = SKSE::GetPapyrusInterface();
			if (papyrus) {
				papyrus->Register([](RE::BSScript::IVirtualMachine* a_vm) {
					auto handler = Impl::LogEventHandler::GetSingleton();
					a_vm->UnregisterForLogEvent(handler);
					return true;
				});
			}
		});
	}
}
