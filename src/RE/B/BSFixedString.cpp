#include "RE/B/BSFixedString.h"

namespace RE
{
	namespace detail
	{
		template <class CharT>
		BSFixedString<CharT>::BSFixedString(const BSFixedString& a_rhs) :
			_data(a_rhs._data)
		{
			try_acquire();
		}

		template <class CharT>
		BSFixedString<CharT>::BSFixedString(BSFixedString&& a_rhs) noexcept :
			_data(a_rhs._data)
		{
			a_rhs._data = nullptr;
		}

		template <class CharT>
		BSFixedString<CharT>::BSFixedString(const_pointer a_string)
		{
			if (a_string) {
				ctor(a_string);
			}
		}

		template <class CharT>
		BSFixedString<CharT>::BSFixedString(std::basic_string_view<value_type> a_view)
		{
			if (!a_view.empty()) {
				ctor(a_view.data());
			}
		}

		template <class CharT>
		BSFixedString<CharT>::~BSFixedString()
		{
			try_release();
		}

		template <class CharT>
		BSFixedString<CharT>& BSFixedString<CharT>::operator=(const BSFixedString<CharT>& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				try_release();
				_data = a_rhs._data;
				try_acquire();
			}
			return *this;
		}

		template <class CharT>
		BSFixedString<CharT>& BSFixedString<CharT>::operator=(BSFixedString&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				try_release();
				_data = a_rhs._data;
				a_rhs._data = nullptr;
			}
			return *this;
		}

		template <class CharT>
		BSFixedString<CharT>& BSFixedString<CharT>::operator=(const_pointer a_string)
		{
			try_release();
			if (a_string) {
				ctor(a_string);
			}
			return *this;
		}

		template <class CharT>
		BSFixedString<CharT>& BSFixedString<CharT>::operator=(std::basic_string_view<value_type> a_view)
		{
			try_release();
			if (!a_view.empty()) {
				ctor(a_view.data());
			}
			return *this;
		}

		template <class CharT>
		BSFixedString<CharT>* BSFixedString<CharT>::ctor(const char* a_data)
		{
			return ctor8(a_data);
		}

		template <class CharT>
		BSFixedString<CharT>* BSFixedString<CharT>::ctor(const wchar_t* a_data)
		{
			return ctor16(a_data);
		}

		template <class CharT>
		BSFixedString<CharT>* BSFixedString<CharT>::ctor8(const char* a_data)
		{
			using func_t = decltype(&BSFixedString::ctor8);
			REL::Relocation<func_t> func{ STATIC_OFFSET(BSFixedString::Ctor8) };
			return func(this, a_data);
		}

		template <class CharT>
		BSFixedString<CharT>* BSFixedString<CharT>::ctor16(const wchar_t* a_data)
		{
			using func_t = decltype(&BSFixedString::ctor16);
			REL::Relocation<func_t> func{ STATIC_OFFSET(BSFixedString::Ctor16) };
			return func(this, a_data);
		}

		template <class CharT>
		void BSFixedString<CharT>::try_acquire()
		{
			const auto proxy = get_proxy();
			if (proxy) {
				proxy->acquire();
			}
		}

		template <class CharT>
		void BSFixedString<CharT>::try_release()
		{
			BSStringPool::Entry::release(_data);
		}

		template class BSFixedString<char>;
		static_assert(sizeof(BSFixedString<char>) == 0x8);

		template class BSFixedString<wchar_t>;
		static_assert(sizeof(BSFixedString<wchar_t>) == 0x8);
	}
}
