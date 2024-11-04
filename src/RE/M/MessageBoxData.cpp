#include "RE/M/MessageBoxData.h"

namespace RE
{
	void MessageBoxData::QueueMessage()
	{
		using func_t = decltype(&MessageBoxData::QueueMessage);
		REL::Relocation<func_t> func{ STATIC_OFFSET(MessageBoxData::QueueMessage) };
		return func(this);
	}
}
