#pragma once

#ifndef BUILD_STATIC
# if defined(QTBASEUI_LIB)
#  define QTBASEUI_EXPORT __declspec(dllexport)
# else
#  define QTBASEUI_EXPORT __declspec(dllimport)
# endif
#else
# define QTBASEUI_EXPORT
#endif
