#include "RE/M/MemoryManager.h"

namespace RE
{
	MemoryManager* MemoryManager::GetSingleton()
	{
		using func_t = decltype(&MemoryManager::GetSingleton);
		REL::Relocation<func_t> func{ STATIC_OFFSET(MemoryManager::GetSingleton) };
		return func();
	}

	void* MemoryManager::Allocate(std::size_t a_size, std::int32_t a_alignment, bool a_alignmentRequired)
	{
		using func_t = decltype(&MemoryManager::Allocate);
		REL::Relocation<func_t> func{ STATIC_OFFSET(MemoryManager::Allocate) };
		return func(this, a_size, a_alignment, a_alignmentRequired);
	}

	void MemoryManager::Deallocate(void* a_mem, bool a_alignmentRequired)
	{
		using func_t = decltype(&MemoryManager::Deallocate);
		REL::Relocation<func_t> func{ STATIC_OFFSET(MemoryManager::Deallocate) };
		return func(this, a_mem, a_alignmentRequired);
	}

	ScrapHeap* MemoryManager::GetThreadScrapHeap()
	{
		using func_t = decltype(&MemoryManager::GetThreadScrapHeap);
		REL::Relocation<func_t> func{ STATIC_OFFSET(MemoryManager::GetThreadScrapHeap) };
		return func(this);
	}

	void* MemoryManager::Reallocate(void* a_oldMem, std::size_t a_newSize, std::int32_t a_alignment, bool a_aligned)
	{
		using func_t = decltype(&MemoryManager::Reallocate);
		REL::Relocation<func_t> func{ STATIC_OFFSET(MemoryManager::Reallocate) };
		return func(this, a_oldMem, a_newSize, a_alignment, a_aligned);
	}

	void MemoryManager::RegisterMemoryManager()
	{
		using func_t = decltype(&MemoryManager::RegisterMemoryManager);
		REL::Relocation<func_t> func{ STATIC_OFFSET(MemoryManager::RegisterMemoryManager) };
		return func(this);
	}

	void* malloc(std::size_t a_size)
	{
		auto heap = MemoryManager::GetSingleton();
		return heap ?
		           heap->Allocate(a_size, 0, false) :
		           nullptr;
	}

	void* aligned_alloc(std::size_t a_alignment, std::size_t a_size)
	{
		auto heap = MemoryManager::GetSingleton();
		return heap ?
		           heap->Allocate(a_size, static_cast<std::int32_t>(a_alignment), true) :
		           nullptr;
	}

	void* calloc(std::size_t a_num, std::size_t a_size)
	{
		return malloc(a_num * a_size);
	}

	void* realloc(void* a_ptr, std::size_t a_newSize)
	{
		auto heap = MemoryManager::GetSingleton();
		return heap ?
		           heap->Reallocate(a_ptr, a_newSize, 0, false) :
		           nullptr;
	}

	void* aligned_realloc(void* a_ptr, std::size_t a_newSize, std::size_t a_alignment)
	{
		auto heap = MemoryManager::GetSingleton();
		return heap ?
		           heap->Reallocate(a_ptr, a_newSize, static_cast<std::int32_t>(a_alignment), true) :
		           nullptr;
	}

	void free(void* a_ptr)
	{
		auto heap = MemoryManager::GetSingleton();
		if (heap) {
			heap->Deallocate(a_ptr, false);
		}
	}

	void aligned_free(void* a_ptr)
	{
		auto heap = MemoryManager::GetSingleton();
		if (heap) {
			heap->Deallocate(a_ptr, true);
		}
	}
}
