#include "RE/B/BSThreadEvent.h"

namespace RE
{
	void BSThreadEvent::InitSDM()
	{
		using func_t = decltype(&BSThreadEvent::InitSDM);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSThreadEvent::InitSDM) };
		return func();
	}
}
