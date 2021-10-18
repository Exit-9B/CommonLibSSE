#pragma once

namespace RE
{
	class GFileConstants
	{
	public:
		struct OpenFlags
		{
			enum
			{
				kRead = 0x1,
				kWrite = 0x2,
				kReadWrite = 0x3,
				kTruncate = 0x4,
				kCreate = 0x8,
				kCreateOnly = 0x18,
				kBuffered = 0x20,
			};
		};

		struct Modes
		{
			enum
			{
				kRead = 0444,
				kWrite = 0222,
				kExecute = 0111,
				kReadWrite = 0666,
			};
		};
	};
}
