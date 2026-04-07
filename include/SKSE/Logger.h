#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/L/LogEvent.h"

#define SKSE_MAKE_SOURCE_LOGGER(a_func, a_type)                           \
                                                                          \
	template <class... Args>                                              \
	struct [[maybe_unused]] a_func                                        \
	{                                                                     \
		a_func() = delete;                                                \
                                                                          \
		explicit a_func(                                                  \
			fmt::format_string<Args...> a_fmt,                            \
			Args&&... a_args,                                             \
			std::source_location a_loc = std::source_location::current()) \
		{                                                                 \
			spdlog::log(                                                  \
				spdlog::source_loc{                                       \
					a_loc.file_name(),                                    \
					static_cast<int>(a_loc.line()),                       \
					a_loc.function_name() },                              \
				spdlog::level::a_type,                                    \
				a_fmt,                                                    \
				std::forward<Args>(a_args)...);                           \
		}                                                                 \
	};                                                                    \
                                                                          \
	template <class... Args>                                              \
	a_func(fmt::format_string<Args...>, Args&&...) -> a_func<Args...>;

namespace SKSE::log
{
	SKSE_MAKE_SOURCE_LOGGER(trace, trace);
	SKSE_MAKE_SOURCE_LOGGER(debug, debug);
	SKSE_MAKE_SOURCE_LOGGER(info, info);
	SKSE_MAKE_SOURCE_LOGGER(warn, warn);
	SKSE_MAKE_SOURCE_LOGGER(error, err);
	SKSE_MAKE_SOURCE_LOGGER(critical, critical);

	[[nodiscard]] std::optional<std::filesystem::path> log_directory();

	void add_papyrus_sink(std::regex a_filter);
	void remove_papyrus_sink();
}

#undef SKSE_MAKE_SOURCE_LOGGER

namespace SKSE
{
	namespace Impl
	{
		class LogEventHandler : public RE::BSTEventSink<RE::BSScript::LogEvent>
		{
		public:
			using EventResult = RE::BSEventNotifyControl;

			[[nodiscard]] static inline LogEventHandler* GetSingleton()
			{
				static LogEventHandler singleton;
				return std::addressof(singleton);
			}

			inline void SetFilter(std::regex a_filter) { _filter = std::move(a_filter); }

			EventResult ProcessEvent(const RE::BSScript::LogEvent* a_event, RE::BSTEventSource<RE::BSScript::LogEvent>*) override
			{
				using Severity = RE::BSScript::ErrorLogger::Severity;

				if (a_event && a_event->errorMsg && std::regex_search(a_event->errorMsg, _filter)) {
					switch (a_event->severity) {
					case Severity::kInfo:
						log::info("{}"sv, a_event->errorMsg);
						break;
					case Severity::kWarning:
						log::warn("{}"sv, a_event->errorMsg);
						break;
					case Severity::kError:
						log::error("{}"sv, a_event->errorMsg);
						break;
					case Severity::kFatal:
						log::critical("{}"sv, a_event->errorMsg);
						break;
					}
				}

				return EventResult::kContinue;
			}

		private:
			LogEventHandler() = default;
			LogEventHandler(const LogEventHandler&) = delete;
			LogEventHandler(LogEventHandler&&) = delete;
			~LogEventHandler() override = default;

			LogEventHandler& operator=(const LogEventHandler&) = delete;
			LogEventHandler& operator=(LogEventHandler&&) = delete;

			std::regex _filter;
		};
	}
}
