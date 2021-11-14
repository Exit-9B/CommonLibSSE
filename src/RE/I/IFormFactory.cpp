#include "RE/I/IFormFactory.h"

namespace RE
{
	std::pair<IFormFactory**, bool> IFormFactory::GetFormFactories()
	{
		struct Factories
		{
			IFormFactory* data[stl::to_underlying(FormType::Max)];
		};

		REL::Relocation<Factories*> formFactories{ Offset::IFormFactory::FormFactories };
		REL::Relocation<bool*>      formFactoriesInitialized{ Offset::IFormFactory::FormFactoriesInitialized };
		return std::make_pair(formFactories->data, *formFactoriesInitialized);
	}

	IFormFactory* IFormFactory::GetFormFactoryByType(FormType a_formType)
	{
		auto formFactories = GetFormFactories();
		return formFactories.second ? formFactories.first[static_cast<std::uint32_t>(a_formType)] : nullptr;
	}

	TESForm* IFormFactory::Create()
	{
		return CreateImpl();
	}
}
