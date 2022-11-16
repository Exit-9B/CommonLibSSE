#pragma once

namespace RE
{
	struct Effect;

	class MagicItemTraversalFunctor
	{
	public:
		inline static constexpr auto RTTI = RTTI_MagicItemTraversalFunctor;

		enum class Result
		{
			kStop = 0,
			kContinue = 1,
		};

		virtual ~MagicItemTraversalFunctor();  // 00

		// add
		virtual Result operator()(Effect* a_effect) = 0;  // 01

		// members
		std::uint32_t index;  // 08
		std::uint32_t pad0C;  // 0C
	};
	static_assert(sizeof(MagicItemTraversalFunctor) == 0x10);
}
