#pragma once

#include "RE/TESBoundObject.h"  // TESBoundObject


namespace RE
{
	class TESBoundAnimObject : public TESBoundObject
	{
	public:
		virtual bool CanAnimate(void) override;	// 53 - { return true; }
	};
}