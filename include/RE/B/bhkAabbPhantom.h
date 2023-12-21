#pragma once

#include "RE/B/bhkPhantom.h"

namespace RE
{
	class bhkAabbPhantom : public bhkPhantom
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkAabbPhantom;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkAabbPhantom;

		// override (bhkPhantom)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		void          Unk_2B(void) override;                              // 2B
		void          Unk_2C(void) override;                              // 2C
		void          Unk_2E(void) override;                              // 2E
		void          Unk_2F(void) override;                              // 2F
	};
	static_assert(sizeof(bhkAabbPhantom) == 0x30);
}
