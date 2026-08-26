#pragma once

#include "RE/B/BSSaveDataSystemUtility.h"

namespace RE
{
	class BSWin32SaveDataSystemUtility : public BSSaveDataSystemUtility
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSWin32SaveDataSystemUtility;

		~BSWin32SaveDataSystemUtility() override;

		// override (BSSaveDataSystemUtility)
		bool    CreateSaveDirectory(const char* a_pathName, bool a_ignoreINI) override;                               // 01
		errno_t PrepareFileSavePath(const char* a_fileName, char* a_dst, bool a_tmpSave, bool a_ignoreINI) override;  // 02
		void    Unk_0B(void) override;                                                                                // 05
		void    Unk_0C(void) override;                                                                                // 06
		void    Unk_0D(void) override;                                                                                // 07
		void    Unk_0E(void) override;                                                                                // 08 - { return; }
		void    Unk_0F(void) override;                                                                                // 09 - { return; }
		void    Unk_12(void) override;                                                                                // 0C
		void    Unk_17(void) override;                                                                                // 11 - { return; }

		static BSWin32SaveDataSystemUtility* GetSingleton();
	};
	static_assert(sizeof(BSWin32SaveDataSystemUtility) == 0x228);
}
