#include "RE/B/BSResponse.h"

namespace RE
{
	ResponseDictionary* ResponseDictionary::GetSingleton()
	{
		REL::Relocation<ResponseDictionary**> singleton{ Offset::ResponseDictionary::Singleton };
		return *singleton;
	}
}
