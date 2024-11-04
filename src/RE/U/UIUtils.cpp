#include "RE/U/UIUtils.h"

namespace RE::UIUtils
{
	void PlayMenuSound(const BGSSoundDescriptorForm* a_descriptor)
	{
		using func_t = decltype(&PlayMenuSound);
		REL::Relocation<func_t> func{ STATIC_OFFSET(UIUtils::PlayMenuSound) };
		return func(a_descriptor);
	}
}
