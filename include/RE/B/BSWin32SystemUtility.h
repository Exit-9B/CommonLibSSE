#pragma once

#include "RE/B/BSSystemUtility.h"
#include "RE/B/BSVirtualKeyboardDevice.h"
#include "RE/C/CCallback.h"

class ISteamClient;
class ISteamUtils;
struct EncryptedAppTicketResponse_t;
struct FloatingGamepadTextInputDismissed_t;
struct GameOverlayActivated_t;
struct GamepadTextInputDismissed_t;

using HSteamPipe = std::int32_t;

namespace RE
{
	using BSWin32SystemUtility = BSSystemUtility;

	class BSWin32SystemUtility_Steam : public BSWin32SystemUtility
	{
	public:
		template <class P>
		using SteamCallback = CCallback<BSWin32SystemUtility_Steam, P, false>;
		template <class P>
		using SteamCallResult = CCallResult<BSWin32SystemUtility_Steam, P>;

		using VirtualKeyboardDoneCallback = void(void*, const char*);
		using VirtualKeyboardCancelCallback = void();

		virtual ~BSWin32SystemUtility_Steam();  // 00

		// override (BSSystemUtility)
		void GetAuthenticationInfo(char*& a_userAuthID, std::uint64_t& a_size) override;  // 03
		void DoInitialize() override;                                                     // 05
		void Unk_06(void) override;                                                       // 06
		void DoUpdate() override;                                                         // 07
		void DoGetUserName(char* a_buffer, std::uint64_t a_size) override;                // 09
		void DoGetComputerName(char* a_buffer, std::uint64_t a_size) override;            // 0E
		void DoAuthenticateUser() override;                                               // 11
#if HAS_SKYRIMSE(1, 6, 1130)
		bool Unk_13() override;  // 13
#endif

		// members
#if HAS_SKYRIMSE(1, 6, 1130)
		SteamCallback<GameOverlayActivated_t>              steamcallback_GameOverlayActivated;               // 128
		SteamCallback<FloatingGamepadTextInputDismissed_t> steamcallback_FloatingGamepadTextInputDismissed;  // 150
		SteamCallback<GamepadTextInputDismissed_t>         steamcallback_GamepadTextInputDismissed;          // 178
		SteamCallResult<EncryptedAppTicketResponse_t>      steamcallresult_EncryptedAppTicketResponse;       // 1A0
		VirtualKeyboardDoneCallback*                       virtualKeyboardDone;                              // 1D0
		VirtualKeyboardCancelCallback*                     virtualKeyboardCancel;                            // 1D8
		void*                                              virtualKeyboardUserParam;                         // 1E0
		bool                                               steamAPIInitialized;                              // 1E8
		std::byte                                          pad1E9[7];                                        // 1E9
		ISteamClient*                                      steamClient;                                      // 1F0
		HSteamPipe                                         steamPipe;                                        // 1F8
		std::uint32_t                                      pad1FC;                                           // 1FC
		ISteamUtils*                                       steamUtils;                                       // 200
		bool                                               isRunningOnSteamDeck;                             // 208
#else
		SteamCallback<GameOverlayActivated_t>         steamcallback_GameOverlayActivated;          // 120
		bool                                          steamAPIInitialized;                         // 148
		std::byte                                     pad149[7];                                   // 149
		SteamCallResult<EncryptedAppTicketResponse_t> steamcallresult_EncryptedAppTicketResponse;  // 150
#endif
	};
#if HAS_SKYRIMSE(1, 6, 1130)
	static_assert(sizeof(BSWin32SystemUtility_Steam) == 0x210);
#else
	static_assert(sizeof(BSWin32SystemUtility_Steam) == 0x180);
#endif

	class BSWin32SystemUtility_GOG : public BSWin32SystemUtility
	{
	public:
		virtual ~BSWin32SystemUtility_GOG();  // 00

		// override (BSSystemUtility)
		void DoInitialize() override;                                           // 05
		void Unk_06(void) override;                                             // 06
		void DoUpdate() override;                                               // 07
		void DoGetUserName(char* a_buffer, std::uint64_t a_size) override;      // 09
		void DoGetComputerName(char* a_buffer, std::uint64_t a_size) override;  // 0E
		void DoAuthenticateUser() override;                                     // 11
#if HAS_SKYRIMSE(1, 6, 1130)
		bool Unk_13() override;  // 13
#endif

		// members
		bool      galaxyAPIInitialized;       // 128
		bool      isAnniversaryEditionOwned;  // 129
		std::byte pad12A[6];                  // 12A
		void*     authListener;               // 130
		void*     recvStatsListener;          // 138
		void*     sendStatsListener;          // 140
	};
#if HAS_SKYRIMSE(1, 6, 1130)
	static_assert(sizeof(BSWin32SystemUtility_GOG) == 0x148);
#endif
}
