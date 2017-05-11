#pragma once

#include "AppGlobal.h"

#include <QFrame>
#include <QLabel>

UI_NAMESPACE_BEGIN
//==================================================================================================

QTBASEUI_EXPORT void qMsgBoxError(const QString & Text, QWidget * Parent = NULL);
QTBASEUI_EXPORT void qMsgBoxAlert(const QString & Text, QWidget * Parent = NULL);
QTBASEUI_EXPORT void qMsgBoxInfo(const QString & Text, QWidget * Parent = NULL);
QTBASEUI_EXPORT void qMsgBoxOk(const QString & Text, QWidget * Parent = NULL);
QTBASEUI_EXPORT int qMsgBoxQuestion(const QString & Text, QWidget * Parent = NULL);
QTBASEUI_EXPORT int qMsgBoxQuestionTwo(const QString & Text, QWidget * Parent = NULL);

//==================================================================================================
QTBASEUI_EXPORT void updateStyle(QWidget * widget, const char * propertyName, const QVariant & value);
QTBASEUI_EXPORT void updateStyle(QWidget * widget, const QString & objectName);
QTBASEUI_EXPORT void updateStyle(QWidget * widget);

//==================================================================================================
QTBASEUI_EXPORT QWidget * MainFrame(QWidget * mainFrame = NULL);

//==================================================================================================
QTBASEUI_EXPORT void appTitle(const QString & title);
QTBASEUI_EXPORT void appIcon(const QString & icon);
QTBASEUI_EXPORT QString appTitle(void);
QTBASEUI_EXPORT QIcon appIcon(void);

//==================================================================================================
enum E_HINT_TYPE { HT_NONE , HT_INFO , HT_ALERT , HT_ERROR , HT_ACCEPT , HT_REJECT };
QTBASEUI_EXPORT void Hint(QFrame * frame, QLabel * label, E_HINT_TYPE hintType, const QString & text);
QTBASEUI_EXPORT void Hint(QLabel * label, E_HINT_TYPE hintType, const QString & text);


//==================================================================================================
QTBASEUI_EXPORT QColor getRGBColor(int color);
QTBASEUI_EXPORT int getCustomColor(const QColor & color);
QTBASEUI_EXPORT QString getRGBColor(const QColor & color);


//==================================================================================================
UI_NAMESPACE_END
