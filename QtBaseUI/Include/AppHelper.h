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
QTBASEUI_EXPORT void initAppResource();
QTBASEUI_EXPORT void initApplication();

//==================================================================================================
//����Ŀ¼��ȡ[ͨ���ⲿ������Դ]	
QTBASEUI_EXPORT QString dirExpand(const char * path);
QTBASEUI_EXPORT QString dirExpand(const QString & path);
QTBASEUI_EXPORT QStringList dirExpand(const QStringList & pathList);


//==================================================================================================
//������Դ[ͨ���ⲿ������Դ]
QTBASEUI_EXPORT void regResource(const QString & Path, const QString & Root);


//==================================================================================================
//���ط��롢����Ƥ��[ͨ���ⲿ������Դ]
QTBASEUI_EXPORT void addTranslator(const QString & Name);
QTBASEUI_EXPORT void setSkinStyles(const QString & Name);
QTBASEUI_EXPORT void setStyleSheet(const QString & Path, bool Append = false);

//�����з����ļ����л�, �ⲿ�л������ļ�ʱ��Ҫ���ô˺���
QTBASEUI_EXPORT void setTranslator(Language Type);

//ͨ��·�����ػ�ı䷭���ļ��� Add�������ӻ�ɾ��
QTBASEUI_EXPORT void changeTranslator(const QString & Path, bool Add);


//==================================================================================================
//��������ȡ���ṩ���ֻ�����������ʽ��, �����ⲿ�����л�Ƥ��ʱʹ��
QTBASEUI_EXPORT QString getSkinStyles(SkinStyle Style);

//==================================================================================================
//�Ի��������ע�ᴰ�ں���
QTBASEUI_EXPORT void regWindowTitle(QWidget * widget, QAbstractButton * btnClose = NULL, 
	QAbstractButton * btnMin = NULL, QAbstractButton * btnMaxRestore = NULL, QWidget * title = NULL);

//ע��MainWindow����, 
QTBASEUI_EXPORT MainWindow * getMainWindow(QWidget * window);


//==================================================================================================
//ע�ᰴť�� ʹ��ť��ʹ���Զ���ͼ�����壨���尴ťͼ��ʹ��ButtonFontIcon��
QTBASEUI_EXPORT void regButtonIcon(QAbstractButton * button, QWidget * parent);


//==================================================================================================

//==================================================================================================
UI_NAMESPACE_END