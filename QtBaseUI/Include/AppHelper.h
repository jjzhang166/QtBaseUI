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
/*	Ӧ�ó����ʼ��
	����Ĭ�ϵ������ļ�Ϊapp.ini
	�����ļ���ʽ���£�

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
//����Ŀ¼��ȡ	
QTBASEUI_EXPORT QString dirExpand(const char * path);
QTBASEUI_EXPORT QString dirExpand(const QString & path);
QTBASEUI_EXPORT QStringList dirExpand(const QStringList & pathList);


//==================================================================================================
//������Դ
QTBASEUI_EXPORT void regResource(const QString & Path, const QString & Root);


//==================================================================================================
//���ط��롢����Ƥ��
QTBASEUI_EXPORT void addTranslator(const QString & Name);
QTBASEUI_EXPORT void setSkinStyles(const QString & Name);
QTBASEUI_EXPORT void setStyleSheet(const QString & Path, bool Append = false);



//==================================================================================================
//�Ի��������ע�ᴰ�ں���
QTBASEUI_EXPORT void regWindowTitle(QWidget * widget, QAbstractButton * btnClose = NULL, 
	QAbstractButton * btnMin = NULL, QAbstractButton * btnMaxRestore = NULL, QWidget * title = NULL);

//ע��MainWindow����, 
QTBASEUI_EXPORT MainWindow * getMainWindow(QWidget * window);



//==================================================================================================