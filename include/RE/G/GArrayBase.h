#pragma once

namespace RE
{
	template <class T>
	class GArrayBase
	{
	public:
		using ValueType = T::ValueType;
		using AllocatorType = T::AllocatorType;
		using SizePolicyType = T::SizePolicyType;

		void Reserve(UPInt a_newCapacity)
		{
			if (a_newCapacity > data.GetCapacity()) {
				data.Reserve(a_newCapacity);
			}
		}

		ValueType& operator[](UPInt a_index)
		{
			assert(a_index < data.size);
			return data.data[a_index];
		}

		const ValueType& operator[](UPInt a_index) const
		{
			assert(a_index < data.size);
			return data.data[a_index];
		}

		void InsertMultipleAt(UPInt a_index, UPInt a_num, const ValueType& a_val = ValueType())
		{
			assert(a_index <= data.size);

			data.Resize(data.size + a_num);
			if (a_index < data.size - a_num) {
				AllocatorType::CopyArrayBackward(
					data.data + a_index + a_num,
					data.data + a_index,
					data.size - a_num - a_index);
			}

			for (UPInt i = 0; i < a_num; ++i) {
				AllocatorType::Construct(data.data + a_index + i, a_val);
			}
		}

		// members
		T data;  // 00
	};
}
