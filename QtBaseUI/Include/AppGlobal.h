#pragma once

# if defined(QTBASEUI_LIB)
#  define QTBASEUI_EXPORT __declspec(dllexport)
# else
#  define QTBASEUI_EXPORT __declspec(dllimport)
#ifndef QT_NO_DEBUG
#pragma comment(lib, "QtBaseUId")
#else
#pragma comment(lib, "QtBaseUI")
# endif
# endif

#define UI_NAMESPACE_BEGIN namespace BASEUI {
#define UI_NAMESPACE_END };

#define USE_UI_NAMESPACE using namespace BASEUI;