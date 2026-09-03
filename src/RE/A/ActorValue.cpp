#include "RE/A/ActorValueInfo.h"

namespace RE
{
	ActorValue* ActorValue::GetSingleton()
	{
		REL::Relocation<ActorValue**> singleton{ STATIC_OFFSET(ActorValue::Singleton) };
		return *singleton;
	}

	ActorValueInfo* ActorValue::GetActorValueInfo(Index a_index)
	{
		if (a_index <= kNone || a_index >= kTotal) {
			return nullptr;
		}

		ActorValue* actorValue = GetSingleton();
		return actorValue->actorValueInfos[a_index];
	}

	const char* ActorValue::GetActorValueName(Index a_index)
	{
		using func_t = decltype(&ActorValue::GetActorValueName);
		REL::Relocation<func_t> func{ STATIC_OFFSET(ActorValue::GetActorValueName) };
		return func(a_index);
	}
}
