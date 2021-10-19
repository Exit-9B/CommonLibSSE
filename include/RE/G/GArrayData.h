#pragma once

#include "RE/G/GArrayDataBase.h"

namespace RE
{
	template <class T, class Allocator, class SizePolicy>
	struct GArrayData : GArrayDataBase<T, Allocator, SizePolicy>
	{
	public:
		using BaseType = GArrayDataBase<T, Allocator, SizePolicy>;

		void Reserve(UPInt a_newCapacity)
		{
			BaseType::Reserve(this, a_newCapacity);
		}

		void Resize(UPInt a_newSize)
		{
			UPInt oldSize = this->size;
			BaseType::ResizeNoConstruct(this, a_newSize);
			if (a_newSize > oldSize) {
				Allocator::ConstructArray(this->data + oldSize, a_newSize - oldSize);
			}
		}
	};
}
