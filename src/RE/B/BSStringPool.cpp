#include "RE/B/BSStringPool.h"

namespace RE
{
	BucketTable* BucketTable::GetSingleton()
	{
		using func_t = decltype(&BucketTable::GetSingleton);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BucketTable::GetSingleton) };
		return func();
	}
}
