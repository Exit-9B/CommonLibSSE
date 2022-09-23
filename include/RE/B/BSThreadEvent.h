#pragma once

namespace RE
{
	struct BSThreadEvent
	{
		static void InitSDM()
		{
			using func_t = decltype(&BSThreadEvent::InitSDM);
			REL::Relocation<func_t> func{ Offset::BSThreadEvent::InitSDM };
			return func();
		}
	};
}
