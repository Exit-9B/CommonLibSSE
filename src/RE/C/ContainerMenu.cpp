#include "RE/C/ContainerMenu.h"

namespace RE
{
	ContainerMenu::ContainerMode ContainerMenu::GetContainerMode()
	{
		REL::Relocation<ContainerMode*> mode{ Offset::ContainerMenu::ContainerMode };
		return *mode;
	}

	RefHandle ContainerMenu::GetTargetRefHandle()
	{
		REL::Relocation<RefHandle*> handle{ Offset::ContainerMenu::TargetRefHandle };
		return *handle;
	}
}
