#pragma once

namespace RE
{
	template <class T, class Allocator, class SizePolicy>
	struct GArrayDataBase
	{
	public:
		using ValueType = T;
		using AllocatorType = Allocator;
		using SizePolicyType = SizePolicy;

		UPInt GetCapacity() const
		{
			return policy.GetCapacity();
		}

		void Reserve([[maybe_unused]] const void* a_heapAddr, UPInt a_newCapacity)
		{
			if (policy.NeverShrinking() && a_newCapacity < GetCapacity())
				return;

			if (a_newCapacity == 0) {
				if (data) {
					Allocator::Free(data);
				}
				policy.SetCapacity(0);
			} else {
				UPInt gran = policy.GetGranularity();
				UPInt newCapacity = (a_newCapacity + gran - 1) / gran * gran;
				if (data) {
					if (Allocator::IsMovable()) {
						data = (T*)Allocator::Realloc(data, sizeof(T) * newCapacity);
					} else {
						T* newData = (T*)Allocator::Alloc(sizeof(T) * newCapacity);
						for (UPInt i = 0; i < size; ++i) {
							Allocator::Construct(&newData[i], data[i]);
							Allocator::Destruct(&data[i]);
						}
						Allocator::Free(data);
						data = newData;
					}
				} else {
					data = (T*)Allocator::Alloc(sizeof(T) * newCapacity);
				}
				policy.SetCapacity(newCapacity);
			}
		}

		void ResizeNoConstruct(const void* a_heapAddr, UPInt a_newSize)
		{
			UPInt oldSize = size;

			if (a_newSize < oldSize) {
				Allocator::DestructArray(data + a_newSize, oldSize - a_newSize);
				if (a_newSize < (policy.GetCapacity() >> 1)) {
					Reserve(a_heapAddr, a_newSize);
				} else if (a_newSize >= policy.GetCapacity()) {
					Reserve(a_heapAddr, a_newSize + (a_newSize >> 2));
				}
				size = a_newSize;
			}
		}

		// members
		T*         data;    // 00
		UPInt      size;    // 08
		SizePolicy policy;  // 10
	};
}
