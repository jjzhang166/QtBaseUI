#pragma once
#include "AppGlobal.h"

UI_NAMESPACE_BEGIN
//==================================================================================================
enum MessageRet
{
	RET_YES = 1,
	RET_NO = -1,
	RET_CANCEL = -2,
};

enum ButtonType {
	BUTTON_MIN,
	BUTTON_MAX,
	BUTTON_CLOSE,
	BUTTON_SKIN,
	BUTTON_MORE
};

enum SkinStyle {
	Skin_BLACK,
	Skin_WHITE
};

enum Language
{
	LANG_EN,
	LANG_CH
};

//==================================================================================================
UI_NAMESPACE_END