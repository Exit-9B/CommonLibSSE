#pragma once

#include "RE/B/BSString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IUIMessageData.h"

namespace RE
{
	class IMessageBoxCallback;

	class MessageBoxData : public IUIMessageData
	{
	public:
		inline static constexpr auto             RTTI = RTTI_MessageBoxData;
		inline static constexpr std::string_view CLASS_NAME = "MessageBoxData";

		MessageBoxData() = default;

		~MessageBoxData() override = default;  // 00

		void QueueMessage();

		template <typename F>
		void SetCallback(F&& a_callback)
		{
			class Callback : public IMessageBoxCallback
			{
			public:
				Callback(F&& callback) :
					_callback(std::forward<F>(callback))
				{}

				~Callback() override = default;

				void operator()(std::int8_t a_msg) override
				{
					_callback(a_msg);
				}

			private:
				std::decay_t<F> _callback;
			};

			callback = make_smart<Callback>(std::forward<F>(a_callback));
		}

		// members
		BSString                             bodyText;     // 10
		BSTArray<BSString>                   buttonText;   // 20
		std::uint32_t                        unk38{ 0 };   // 38
		std::int32_t                         unk3C{ -1 };  // 3C
		BSTSmartPointer<IMessageBoxCallback> callback;     // 40
		std::uint32_t                        unk48{ 10 };  // 48
		std::uint8_t                         unk4C{ 0 };   // 4C
		std::uint8_t                         unk4D{ 0 };   // 4D
		std::uint8_t                         unk4E{ 0 };   // 4E
		std::uint8_t                         unk4F{ 0 };   // 4F
	};
	static_assert(sizeof(MessageBoxData) == 0x50);
}
