#include "RE/B/BGSEntryPointFunction.h"

namespace RE
{
	std::uint32_t BGSEntryPointFunction::GetArgumentCount(ENTRY_POINT_FUNCTION_TYPE a_entryPointFunctionType)
	{
		if (a_entryPointFunctionType < ENTRY_POINT_FUNCTION_TYPE::kTotal) {
			REL::Relocation<std::uint32_t*> entryPointFunctionTypeArgumentCount{ STATIC_OFFSET(BGSEntryPointFunction::EntryPointFunctionTypeArgumentCount) };
			return entryPointFunctionTypeArgumentCount.get()[a_entryPointFunctionType];
		}

		return 0;
	}

	BGSEntryPointFunction::EntryPointFunction* BGSEntryPointFunction::GetEntryPointFunction(ENTRY_POINT_FUNCTION a_entryPointFunction)
	{
		if (a_entryPointFunction < ENTRY_POINT_FUNCTION::kTotal) {
			REL::Relocation<EntryPointFunction*> entryPointFunctions{ STATIC_OFFSET(BGSEntryPointFunction::EntryPointFunctions) };
			return &entryPointFunctions.get()[a_entryPointFunction];
		}

		return nullptr;
	}
}
