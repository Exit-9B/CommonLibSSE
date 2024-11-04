#include "RE/E/EffectArchetypes.h"

namespace RE
{
	EffectArchetypes::ArchetypeDef& EffectArchetypes::GetArchetypeDef(ArchetypeID a_id)
	{
		REL::Relocation<ArchetypeDef*> archetypes{ STATIC_OFFSET(EffectArchetypes::Archetypes) };
		return archetypes.get()[stl::to_underlying(a_id)];
	}

	const char* EffectArchetypes::GetArchetypeName(ArchetypeID a_id)
	{
		return GetArchetypeDef(a_id).name;
	}

	FormType EffectArchetypes::GetAssociatedFormType(ArchetypeID a_id)
	{
		return GetArchetypeDef(a_id).associatedFormType;
	}

	ActorValue EffectArchetypes::GetFixedActorValue(ArchetypeID a_id)
	{
		return GetArchetypeDef(a_id).fixedActorValue;
	}

	bool EffectArchetypes::IsFlagSet(ArchetypeID a_id, Flags a_flag)
	{
		return GetArchetypeDef(a_id).flags.all(a_flag);
	}
}
