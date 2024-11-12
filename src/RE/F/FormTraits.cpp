#include "RE/F/FormTraits.h"

namespace RE
{
	template const TESBoundObject*     TESForm::As() const noexcept;
	template const TESContainer*       TESForm::As() const noexcept;
	template const TESEnchantableForm* TESForm::As() const noexcept;
	template const TESFullName*        TESForm::As() const noexcept;
	template const TESLeveledList*     TESForm::As() const noexcept;
	template const TESModel*           TESForm::As() const noexcept;
	template const TESWeightForm*      TESForm::As() const noexcept;
}
