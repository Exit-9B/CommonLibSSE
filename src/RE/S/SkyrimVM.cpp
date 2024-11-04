#include "RE/S/SkyrimVM.h"

namespace RE
{
	SkyrimVM* SkyrimVM::GetSingleton()
	{
		REL::Relocation<SkyrimVM**> singleton{ STATIC_OFFSET(SkyrimVM::Singleton) };
		return *singleton;
	}

	bool SkyrimVM::QueuePostRenderCall(const BSTSmartPointer<SkyrimScript::DelayFunctor>& a_functor)
	{
		using func_t = decltype(&SkyrimVM::QueuePostRenderCall);
		REL::Relocation<func_t> func{ STATIC_OFFSET(SkyrimVM::QueuePostRenderCall) };
		return func(this, a_functor);
	}
}
