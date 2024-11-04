#include "RE/H/hkContainerAllocators.h"

namespace RE
{
	hkContainerHeapAllocator::Allocator* hkContainerHeapAllocator::GetSingleton()
	{
		REL::Relocation<hkContainerHeapAllocator::Allocator*> singleton{ STATIC_OFFSET(hkContainerHeapAllocator::Singleton) };
		return singleton.get();
	}
}
