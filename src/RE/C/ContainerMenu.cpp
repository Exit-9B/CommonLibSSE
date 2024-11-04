#include "RE/C/ContainerMenu.h"

namespace RE
{
	ContainerMenu::ContainerMode ContainerMenu::GetContainerMode()
	{
		REL::Relocation<ContainerMode*> mode{ STATIC_OFFSET(ContainerMenu::ContainerMode) };
		return *mode;
	}

	RefHandle ContainerMenu::GetTargetRefHandle()
	{
		REL::Relocation<RefHandle*> handle{ STATIC_OFFSET(ContainerMenu::TargetRefHandle) };
		return *handle;
	}
}
