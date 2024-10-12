#pragma once

#include "RE/I/INISettingCollection.h"

namespace RE
{
	class INIPrefSettingCollection : public INISettingCollection
	{
	public:
		inline static constexpr auto RTTI = RTTI_INIPrefSettingCollection;

		~INIPrefSettingCollection() override;  // 00

		// override (INISettingCollection)
		void Unk_07(void) override;  // 07 - { return 1; }
		void Unk_08(void) override;  // 08
		void Unk_09(void) override;  // 09

		static INIPrefSettingCollection* GetSingleton();
	};
	static_assert(sizeof(INIPrefSettingCollection) == 0x128);

	namespace literals
	{
		template <stl::nttp::zstring S>
		inline auto operator""_pref()
		{
			static RE::Setting* setting = nullptr;
			if (!setting) {
				if (auto collection = INIPrefSettingCollection::GetSingleton()) {
					setting = collection->GetSetting(S.data());
				}
			}

			if constexpr (S.front() == 'b') {
				return setting ? std::optional(setting->data.b) : std::nullopt;
			} else if constexpr (S.front() == 'f') {
				return setting ? std::optional(setting->data.f) : std::nullopt;
			} else if constexpr (S.front() == 'i') {
				return setting ? std::optional(setting->data.i) : std::nullopt;
			} else if constexpr (S.front() == 'r') {
				return setting ? std::optional(setting->data.r) : std::nullopt;
			} else if constexpr (S.front() == 's') {
				return setting ? std::optional(setting->data.s) : std::nullopt;
			} else if constexpr (S.front() == 'u') {
				return setting ? std::optional(setting->data.u) : std::nullopt;
			}
		}
	}
}
