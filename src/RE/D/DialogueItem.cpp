#include "RE/D/DialogueItem.h"

namespace RE
{
	DialogueItem::DialogueItem(TESQuest* a_quest, TESTopic* a_topic, TESTopicInfo* a_topicInfo, Actor* a_speaker)
	{
		Ctor(a_quest, a_topic, a_topicInfo, a_speaker);
	}

	DialogueItem* DialogueItem::Ctor(TESQuest* a_quest, TESTopic* a_topic, TESTopicInfo* a_topicInfo, Actor* a_speaker)
	{
		using func_t = decltype(&DialogueItem::Ctor);
		REL::Relocation<func_t> func{ STATIC_OFFSET(DialogueItem::Ctor) };
		return func(this, a_quest, a_topic, a_topicInfo, a_speaker);
	}
}
