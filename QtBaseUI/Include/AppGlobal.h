#pragma once

#ifndef BUILD_USE_STATIC_UI
# if defined(QTBASEUI_LIB)
#  define QTBASEUI_EXPORT __declspec(dllexport)
# else
#  define QTBASEUI_EXPORT __declspec(dllimport)
# endif
#else
# define QTBASEUI_EXPORT
#endif

#ifndef QTBASEUI_LIB
#if defined QT_NO_DEBUG
#pragma comment(lib, "QtBaseUI")
#else
#pragma comment(lib, "QtBaseUId")
# endif
#endif

#define UI_NAMESPACE_BEGIN namespace BASEUI {
#define UI_NAMESPACE_END };

#define USE_UI_NAMESPACE using namespace BASEUI;