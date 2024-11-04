#include "RE/M/Main.h"

namespace RE
{
	Main* Main::GetSingleton()
	{
		REL::Relocation<Main**> singleton{ STATIC_OFFSET(Main::Singleton) };
		return *singleton;
	}

	float Main::QFrameAnimTime()
	{
		REL::Relocation<float*> data{ STATIC_OFFSET(Main::QFrameAnimTime) };
		return *data;
	}
}
