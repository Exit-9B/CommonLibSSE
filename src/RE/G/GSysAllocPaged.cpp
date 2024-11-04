#include "RE/G/GSysAllocPaged.h"

namespace RE
{
	bool GSysAllocPaged::InitHeapEngine(const void* a_heapDesc)
	{
		using func_t = decltype(&GSysAllocPaged::InitHeapEngine);
		REL::Relocation<func_t> func{ STATIC_OFFSET(GSysAllocPaged::InitHeapEngine) };
		return func(this, a_heapDesc);
	}

	void GSysAllocPaged::ShutdownHeapEngine()
	{
		using func_t = decltype(&GSysAllocPaged::ShutdownHeapEngine);
		REL::Relocation<func_t> func{ STATIC_OFFSET(GSysAllocPaged::ShutdownHeapEngine) };
		return func(this);
	}
}
