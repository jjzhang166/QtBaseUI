#pragma once

#include "AppGlobal.h"
#include "MainWindow.h"
#include "ToolButton.h"
#include "FrameHelper.h"

#include <QString>
#include <QStringList>

class QWidget;
class QAbstractButton;

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
QTBASEUI_EXPORT void initApplication();


//==================================================================================================
//程序目录读取	
QTBASEUI_EXPORT QString dirExpand(const char * path);
QTBASEUI_EXPORT QString dirExpand(const QString & path);
QTBASEUI_EXPORT QStringList dirExpand(const QStringList & pathList);


//==================================================================================================
//加载资源
QTBASEUI_EXPORT void regResource(const QString & Path, const QString & Root);


//==================================================================================================
//加载翻译、设置皮肤
QTBASEUI_EXPORT void addTranslator(const QString & Name);
QTBASEUI_EXPORT void setSkinStyles(const QString & Name);
QTBASEUI_EXPORT void setStyleSheet(const QString & Path, bool Append = false);



//==================================================================================================
//自绘标题栏、注册窗口函数
QTBASEUI_EXPORT void regWindowTitle(QWidget * widget, QAbstractButton * btnClose = NULL, 
	QAbstractButton * btnMin = NULL, QAbstractButton * btnMaxRestore = NULL, QWidget * title = NULL);

//注册MainWindow窗口, 
QTBASEUI_EXPORT MainWindow * getMainWindow(QWidget * window);



//==================================================================================================