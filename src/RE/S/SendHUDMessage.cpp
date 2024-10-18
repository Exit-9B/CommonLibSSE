#include "RE/S/SendHUDMessage.h"
#include "RE/G/GameSettingCollection.h"
#include "RE/H/HUDData.h"
#include "RE/H/HUDMenu.h"
#include "RE/I/InterfaceStrings.h"
#include "RE/P/PlayerCharacter.h"
#include "RE/U/UIMessageQueue.h"

namespace RE
{
	using namespace literals;

	void SendHUDMessage::ShowHUDMessage(const char* a_notification, const char* a_soundToPlay, bool a_cancelIfAlreadyQueued)
	{
		using func_t = decltype(&SendHUDMessage::ShowHUDMessage);
		REL::Relocation<func_t> func{ Offset::SendHUDMessage::ShowHUDMessage };
		return func(a_notification, a_soundToPlay, a_cancelIfAlreadyQueued);
	}

	void SendHUDMessage::ShowInventoryChangeMessage(TESBoundObject* a_object, std::int32_t a_count, bool a_added, bool a_playSound, const char* a_objectName)
	{
		if (!a_object || !a_count) {
			return;
		}

		const auto objectName = (a_objectName && a_objectName[0]) ? a_objectName : a_object->GetName();
		const auto phrase = a_added ? *"sAddItemtoInventory"_gs : *"sRemoveItemfromInventory"_gs;
		const std::string message = a_count >= 1 ? fmt::format("{} {}", objectName, phrase) : fmt::format("{} ({}) {}", objectName, a_count, phrase);

		ShowHUDMessage(message.c_str());

		if (a_playSound) {
			PlayerCharacter::GetSingleton()->PlayPickUpSound(a_object, a_added, false);
		}
	}

	void SendHUDMessage::SetHUDMode(const char* a_mode, bool a_push)
	{
		const auto uiMessageQueue = UIMessageQueue::GetSingleton();
		const auto interfaceStrings = InterfaceStrings::GetSingleton();
		if (const auto data = static_cast<HUDData*>(uiMessageQueue->CreateUIMessageData(interfaceStrings->hudData))) {
			data->unk40 = a_push;
			data->text = a_mode;
			data->type = HUDData::Type::kSetMode;
			uiMessageQueue->AddMessage(HUDMenu::MENU_NAME, UI_MESSAGE_TYPE::kUpdate, data);
		}
	}

	void SendHUDMessage::PushHudMode(const char* a_mode)
	{
		SetHUDMode(a_mode, true);
	}

	void SendHUDMessage::PopHudMode(const char* a_mode)
	{
		SetHUDMode(a_mode, false);
	}
}
