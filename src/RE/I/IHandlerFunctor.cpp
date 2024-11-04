#include "RE/I/IHandlerFunctor.h"

namespace RE
{
	HandlerDictionary* HandlerDictionary::GetSingleton()
	{
		REL::Relocation<HandlerDictionary**> singleton{ STATIC_OFFSET(HandlerDictionary::Singleton) };
		return *singleton;
	}
}
