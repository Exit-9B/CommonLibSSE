#pragma once

#include "RE/I/IVirtualMachine.h"
#include "RE/V/VirtualMachine.h"

#include "SKSE/Impl/Stubs.h"

namespace SKSE
{
	class PapyrusInterface
	{
	public:
		using RegFunction1 = bool(RE::BSScript::Internal::VirtualMachine* a_vm);
		using RegFunction2 = bool(RE::BSScript::IVirtualMachine* a_vm);

		enum
		{
			kVersion = 1
		};

		[[nodiscard]] std::uint32_t Version() const
		{
			return GetProxy()->interfaceVersion;
		}

		template <class Last>
		bool Register(Last a_last) const
		{
			return Register_Impl(a_last);
		}

		template <class First, class... Rest>
		bool Register(First a_first, Rest... a_rest) const
		{
			return Register_Impl(a_first) && Register(a_rest...);
		}

	protected:
		[[nodiscard]] const detail::SKSEPapyrusInterface* GetProxy() const
		{
			assert(this);
			return reinterpret_cast<const detail::SKSEPapyrusInterface*>(this);
		}

	private:
		bool Register_Impl(RegFunction1* a_fn) const;
		bool Register_Impl(RegFunction2* a_fn) const;
	};
}
