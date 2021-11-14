#include "RE/M/MemoryManager.h"

namespace RE
{
	MemoryManager* MemoryManager::GetSingleton()
	{
		using func_t = decltype(&MemoryManager::GetSingleton);
		REL::Relocation<func_t> func{ Offset::MemoryManager::GetSingleton };
		return func();
	}

	void* MemoryManager::Allocate(std::size_t a_size, std::int32_t a_alignment, bool a_alignmentRequired)
	{
		using func_t = decltype(&MemoryManager::Allocate);
		REL::Relocation<func_t> func{ Offset::MemoryManager::Allocate };
		return func(this, a_size, a_alignment, a_alignmentRequired);
	}

	void MemoryManager::Deallocate(void* a_mem, bool a_alignmentRequired)
	{
		using func_t = decltype(&MemoryManager::Deallocate);
		REL::Relocation<func_t> func{ Offset::MemoryManager::Deallocate };
		return func(this, a_mem, a_alignmentRequired);
	}

	ScrapHeap* MemoryManager::GetThreadScrapHeap()
	{
		using func_t = decltype(&MemoryManager::GetThreadScrapHeap);
		REL::Relocation<func_t> func{ Offset::MemoryManager::GetThreadScrapHeap };
		return func(this);
	}

	void* MemoryManager::Reallocate(void* a_oldMem, std::size_t a_newSize, std::int32_t a_alignment, bool a_aligned)
	{
		using func_t = decltype(&MemoryManager::Reallocate);
		REL::Relocation<func_t> func{ Offset::MemoryManager::Reallocate };
		return func(this, a_oldMem, a_newSize, a_alignment, a_aligned);
	}

	void MemoryManager::RegisterMemoryManager()
	{
		using func_t = decltype(&MemoryManager::RegisterMemoryManager);
		REL::Relocation<func_t> func{ Offset::MemoryManager::RegisterMemoryManager };
		return func(this);
	}
}
