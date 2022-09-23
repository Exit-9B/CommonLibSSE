#include "RE/I/IHandlerFunctor.h"

namespace RE
{
	HandlerDictionary* HandlerDictionary::GetSingleton()
	{
		REL::Relocation<HandlerDictionary**> singleton{ Offset::HandlerDictionary::Singleton };
		return *singleton;
	}
}
