#include "RE/H/hkContainerAllocators.h"

namespace RE
{
	Allocator* hkContainerHeapAllocator::GetSingleton()
	{
		REL::Relocation<hkContainerHeapAllocator::Allocator*> singleton{ Offset::hkContainerHeapAllocator::Singleton };
		return singleton.get();
	}
}
