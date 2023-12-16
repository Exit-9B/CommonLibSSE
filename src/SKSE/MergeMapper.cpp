// SPDX-License-Identifier: Apache-2.0
#include "SKSE/MergeMapper.h"

#include "SKSE/API.h"

namespace SKSE
{
	// Fetches the interface to use from MergeMapper
	static IMergeMapperInterface001* RequestMergeMapperInterface001() noexcept
	{
		// Dispatch a message to get the plugin interface from MergeMapper
		MergeMapperMessage mergeMapperMessage;
		const auto         skseMessaging = GetMessagingInterface();
		skseMessaging->Dispatch(MergeMapperMessage::kMessage_GetInterface, &mergeMapperMessage, sizeof(MergeMapperMessage*), MergeMapperPluginName);
		if (!mergeMapperMessage.GetApiFunction) {
			return nullptr;
		}

		// Fetch the API for this version of the MergeMapper interface
		return static_cast<IMergeMapperInterface001*>(mergeMapperMessage.GetApiFunction(1));
	}

	IMergeMapperInterface001* GetMergeMapperInterface() noexcept
	{
		static IMergeMapperInterface001* intfc = RequestMergeMapperInterface001();
		return intfc;
	}
}
