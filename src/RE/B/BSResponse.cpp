#include "RE/B/BSResponse.h"

namespace RE
{
	ResponseDictionary* ResponseDictionary::GetSingleton()
	{
		REL::Relocation<ResponseDictionary**> singleton{ STATIC_OFFSET(ResponseDictionary::Singleton) };
		return *singleton;
	}
}
