#include "RE/B/BSStringPool.h"

namespace RE
{
	void BSStringPool::Entry::release(const char*& a_entry) { release8(a_entry); }

	void BSStringPool::Entry::release(const wchar_t*& a_entry) { release16(a_entry); }

	void BSStringPool::Entry::release8(const char*& a_entry)
	{
		using func_t = decltype(&Entry::release8);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSStringPool::Release8) };
		return func(a_entry);
	}

	void BSStringPool::Entry::release16(const wchar_t*& a_entry)
	{
		using func_t = decltype(&Entry::release16);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSStringPool::Release16) };
		return func(a_entry);
	}

	void BSStringPool::Entry::acquire()
	{
		stl::atomic_ref flags{ _flags };
		std::uint16_t   expected{ 0 };
		do {
			expected = flags;
			if ((expected & kRefCountMask) >= kRefCountMask) {
				break;
			}
		} while (!flags.compare_exchange_weak(expected, static_cast<std::uint16_t>(expected + 1)));
	}

	BucketTable* BucketTable::GetSingleton()
	{
		using func_t = decltype(&BucketTable::GetSingleton);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BucketTable::GetSingleton) };
		return func();
	}
}
