#include "RE/IMenu.h"

#include "skse64/GameMenus.h"  // IMenu


namespace RE
{
	IMenu::IMenu() :
		view(0),
		menuDepth(3),
		flags(Flag::kNone),
		context(Context::kInvalid),
		unk18(0)
	{}


	IMenu::~IMenu()
	{
		typedef void _IMenu_dtor_t(IMenu* a_this);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::IMenu*>(this)->_dtor_GetPtr());
		_IMenu_dtor_t* _IMenu_dtor = reinterpret_cast<_IMenu_dtor_t*>(*ptr);
		_IMenu_dtor(this);
	}


	void IMenu::Accept(CallbackProcessor* a_processor)
	{}


	void IMenu::OnOpen()
	{}


	void IMenu::Unk_03(void)
	{}


	IMenu::Result IMenu::ProcessMessage(UIMessage* a_message)
	{
		typedef IMenu::Result _ProcessMessage_t(IMenu* a_this, UIMessage* a_message);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::IMenu*>(this)->_ProcessMessage_internal_GetPtr());
		_ProcessMessage_t* _ProcessMessage = reinterpret_cast<_ProcessMessage_t*>(*ptr);
		return _ProcessMessage(this, a_message);
	}


	void IMenu::NextFrame(UInt32 a_arg1, UInt32 a_arg2)
	{
		typedef void _NextFrame_t(IMenu* a_this, UInt32 a_arg1, UInt32 a_arg2);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::IMenu*>(this)->_NextFrame_internal_GetPtr());
		_NextFrame_t* _NextFrame = reinterpret_cast<_NextFrame_t*>(*ptr);
		_NextFrame(this, a_arg1, a_arg2);
	}


	void IMenu::Render()
	{
		if (view) {
			view->Display();
		}
	}


	void IMenu::Unk_07(void)
	{}


	void IMenu::InitMovie()
	{
		typedef void _InitMovie_t(IMenu* a_this, GFxMovieView* a_view);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::IMenu*>(this)->_InitMovie_internal_GetPtr());
		_InitMovie_t* _InitMovie = reinterpret_cast<_InitMovie_t*>(*ptr);
		_InitMovie(this, view);
	}


	bool IMenu::PausesGame()
	{
		return (flags & Flag::kPauseGame) != Flag::kNone;
	}


	bool IMenu::DeletesOnClose()
	{
		return (flags & Flag::kDoNotDeleteOnClose) == Flag::kNone;
	}


	bool IMenu::ShowsCursor()
	{
		return (flags & Flag::kShowCursor) != Flag::kNone;
	}


	bool IMenu::HasFlag0008()
	{
		return (flags & Flag::kUnk0008) != Flag::kNone;
	}


	bool IMenu::IsModal()
	{
		return (flags & Flag::kModal) != Flag::kNone;
	}


	bool IMenu::StopsDrawingWorld()
	{
		return (flags & Flag::kStopDrawingWorld) != Flag::kNone;
	}


	bool IMenu::IsOpen()
	{
		return (flags & Flag::kOpen) != Flag::kNone;
	}


	bool IMenu::PreventsGameLoad()
	{
		return (flags & Flag::kPreventGameLoad) != Flag::kNone;
	}


	bool IMenu::HasFlag0100()
	{
		return (flags & Flag::kUnk0100) != Flag::kNone;
	}


	bool IMenu::HidesOtherMenus()
	{
		return (flags & Flag::kHideOther) != Flag::kNone;
	}


	bool IMenu::HasFlag0400()
	{
		return (flags & Flag::kUnk0400) != Flag::kNone;
	}


	bool IMenu::PreventsGameSave()
	{
		return (flags & Flag::kDoNotPreventGameSave) == Flag::kNone;
	}


	bool IMenu::HasFlag1000()
	{
		return (flags & Flag::kUnk1000) != Flag::kNone;
	}


	bool IMenu::IsItemMenu()
	{
		return (flags & Flag::kItemMenu) != Flag::kNone;
	}


	bool IMenu::StopsCrosshairUpdates()
	{
		return (flags & Flag::kStopCrosshairUpdate) != Flag::kNone;
	}


	bool IMenu::HasFlag8000()
	{
		return (flags & Flag::kUnk8000) != Flag::kNone;
	}


	bool IMenu::HasFlag10000()
	{
		return (flags & Flag::kUnk10000) != Flag::kNone;
	}
}