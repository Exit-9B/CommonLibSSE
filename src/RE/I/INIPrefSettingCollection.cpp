#include "RE/I/INIPrefSettingCollection.h"

namespace RE
{
	INIPrefSettingCollection* INIPrefSettingCollection::GetSingleton()
	{
		REL::Relocation<INIPrefSettingCollection**> singleton{ STATIC_OFFSET(INIPrefSettingCollection::Singleton) };
		return *singleton;
	}
}
