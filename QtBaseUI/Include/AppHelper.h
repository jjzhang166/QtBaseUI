#pragma once

#include <QString>
#include <QStringList>

#include "AppGlobal.h"
#include "AppStruct.h"
#include "MainWindow.h"
#include "PushButton.h"

class QWidget;
class QAbstractButton;


UI_NAMESPACE_BEGIN
/************************************************************************/
/*	应用程序初始化
	程序默认的配置文件为app.ini
	配置文件格式如下：

	[Application]
	Language=zh_CN.lang
	LocaleCodec=UTF-8
	Theme=default.skin

	[Plugins]
	1=$(Binara)/plugins

	[Search]
	image=$(AppDir)/res/images
	lang=$(AppDir)/res
	plugins=$(Binara)/plugins
	res=$(AppDir)/res
	skin=$(AppDir)/res/themes
*/                                                                   
/************************************************************************/

//==================================================================================================
QTBASEUI_EXPORT void initAppResource();
QTBASEUI_EXPORT void initApplication();

//==================================================================================================
//程序目录读取[通过外部加载资源]	
QTBASEUI_EXPORT QString dirExpand(const char * path);
QTBASEUI_EXPORT QString dirExpand(const QString & path);
QTBASEUI_EXPORT QStringList dirExpand(const QStringList & pathList);


//==================================================================================================
//加载资源[通过外部加载资源]
QTBASEUI_EXPORT void regResource(const QString & Path, const QString & Root);


//==================================================================================================
//加载翻译、设置皮肤[通过外部加载资源]
QTBASEUI_EXPORT void addTranslator(const QString & Name);
QTBASEUI_EXPORT void setSkinStyles(const QString & Name);
QTBASEUI_EXPORT void setStyleSheet(const QString & Path, bool Append = false);

//本库中翻译文件的切换, 外部切换翻译文件时需要调用此函数
QTBASEUI_EXPORT void setTranslator(Language Type);

//通过路径加载或改变翻译文件， Add代表增加或删除
QTBASEUI_EXPORT void changeTranslator(const QString & Path, bool Add);


//==================================================================================================
//基础风格获取（提供几种基本的主题样式）, 方便外部程序切换皮肤时使用
QTBASEUI_EXPORT QString getSkinStyles(SkinStyle Style);

//==================================================================================================
//自绘标题栏、注册窗口函数
QTBASEUI_EXPORT void regWindowTitle(QWidget * widget, QAbstractButton * btnClose = NULL, 
	QAbstractButton * btnMin = NULL, QAbstractButton * btnMaxRestore = NULL, QWidget * title = NULL);

//注册MainWindow窗口, 
QTBASEUI_EXPORT MainWindow * getMainWindow(QWidget * window);


//==================================================================================================
//注册按钮， 使按钮可使用自定义图标字体（定义按钮图标使用ButtonFontIcon类
QTBASEUI_EXPORT void regButtonIcon(QAbstractButton * button, QWidget * parent);


//==================================================================================================

//==================================================================================================
UI_NAMESPACE_END