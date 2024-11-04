#include "RE/A/ActorValueInfo.h"

namespace RE
{
	const char* ActorValueInfo::GetActorValueName(ActorValue a_actorValue)
	{
		using func_t = decltype(&ActorValueInfo::GetActorValueName);
		REL::Relocation<func_t> func{ STATIC_OFFSET(ActorValueInfo::GetActorValueName) };
		return func(a_actorValue);
	}
}
