#include "stdafx.h"
#include "AppHelper.h"
#include "FrameHelper.h"
#include "AppFontIcon.h"

#include <QDir>
#include <QPointer>
#include <QResource>
#include <QSettings>
#include <QTextCodec>
#include <QTranslator>
#include <QApplication>
#include <QScopedPointer>

UI_NAMESPACE_BEGIN
//==================================================================================================
struct QSettingGroup
{
	QSettingGroup(QSettings & config, const QString & group) : settings(config)
	{
		settings.beginGroup(group);
	}

	~QSettingGroup() { settings.endGroup(); }

	template< typename T > T Value(const QString & Key, const QVariant & Def = QVariant())
	{
		return settings.value(Key, Def).value< T >();
	}

	QStringList stringList(const QString & Key) { return Value< QStringList >(Key); }

	QByteArray byteArray(const QString & Key, const QVariant & Def = QVariant())
	{
		return Value< QByteArray >(Key, Def);
	}

	QString string(const QString & Key, const QVariant & Def = QVariant())
	{
		return Value< QString >(Key, Def);
	}

	int number(const QString & Key, const QVariant & Def = QVariant())
	{
		return Value< int >(Key, Def);
	}

	QSettings & settings;
};

//==================================================================================================
QString dirExpand(const char * path)
{
	return dirExpand(QString(path));
}

QString dirExpand(const QString & path)
{
	static QString appDir, binary, config;
	if (appDir.isEmpty() || appDir.isNull())
	{
		binary = QCoreApplication::applicationDirPath();
		appDir = QDir(binary + "/..").canonicalPath();
		config = appDir + "/etc";
	}

	QString temp(path);

	temp.replace("$(AppDir)", appDir);
	temp.replace("$(Binary)", binary);
	temp.replace("$(Config)", config);

	return temp;
}

QStringList dirExpand(const QStringList & pathList)
{
	typedef QStringList::const_iterator QStringListItr;
	QStringListItr Begin = pathList.begin();
	QStringListItr End = pathList.end();
	QStringList pathExpands;

	for (QStringListItr itr = Begin; itr != End; itr++)
	{
		pathExpands.append(dirExpand(*itr));
	}

	return pathExpands;
}

//==================================================================================================
void regResource(const QString & Name, const QString & Root)
{
	QString name(Name), root(Root);
	if (root[0] == ':') { root[0] = '/'; }
	if (root[0] == '@') { root[0] = '/'; }
	if (root[0] != '/') { root.insert(0, '/'); }
	QResource::registerResource(dirExpand(name), root);
}

//==================================================================================================
void addTranslator(const QString & Name)
{
	QPointer<QTranslator> translator = new QTranslator(0);
	translator->load(QString("lang:") + Name);
	qApp->installTranslator(translator);
}

void setSkinStyles(const QString & Name)
{
	QFile skinFile(QString("skin:") + Name);
	if (skinFile.open(QFile::ReadOnly | QFile::Unbuffered))
		qApp->setStyleSheet(skinFile.readAll());
	skinFile.close();
}

void setStyleSheet(const SkinStyle & Style)
{
	QString strStyles;
	QString strSkinPath;

	switch (Style)
	{
	case BASEUI::Skin_BLACK:
		strSkinPath = ":/qss/black.css";
		break;
	case BASEUI::Skin_WHITE:
		break;
	default:
		break;
	}

	if (!strSkinPath.isEmpty())
	{
		QFile skinFile(strSkinPath);
		if (skinFile.open(QFile::ReadOnly | QFile::Unbuffered))
			qApp->setStyleSheet(skinFile.readAll());
		skinFile.close();
	}
}

void setStyleSheet(const QString & Path, bool Append)
{
	QFile skinFile(Path);
	if (skinFile.open(QFile::ReadOnly | QFile::Unbuffered))
	{
		if (Append)
		{
			QString styles = qApp->styleSheet() + QString(skinFile.readAll());
			qApp->setStyleSheet(styles);
		}
		else
		{
			qApp->setStyleSheet(skinFile.readAll());
		}
	}
	skinFile.close();
}

void setTranslator(Language Type)
{
	static QPointer<QTranslator> translator = 0;

	if (translator)
	{
		qApp->removeTranslator(translator);
		translator = 0;
	}

	switch (Type)
	{
	case BASEUI::LANG_EN:
		break;
	case BASEUI::LANG_CH:
	{
		translator = new QTranslator();
		translator->load(":/ts/qtbaseui_zh.qm");
		qApp->installTranslator(translator);
		break;
	}
	default:
		break;
	}
}

void changeTranslator(const QString & Path, bool Add)
{
	static QMap<QString, QTranslator *> mapTranslator;

	if (Add && !mapTranslator.contains(Path))
	{
		QPointer<QTranslator> translator = new QTranslator();
		translator->load(Path);
		qApp->installTranslator(translator);
		mapTranslator.insert(Path, translator);
	}
	else if(!Add && mapTranslator.contains(Path))
	{
		QPointer<QTranslator> translator = mapTranslator.value(Path);
		qApp->removeTranslator(translator);
		mapTranslator.remove(Path);
	}
}

QString getSkinStyles(const SkinStyle & Style)
{
	QString strStyles;
	QString strSkinPath;

	switch (Style)
	{
	case BASEUI::Skin_BLACK:
		strSkinPath = ":/qss/black.css";
		break;
	case BASEUI::Skin_WHITE:
		break;
	default:
		break;
	}

	if (!strSkinPath.isEmpty())
	{
		QFile skinFile(strSkinPath);
		if (skinFile.open(QFile::ReadOnly | QFile::Unbuffered))
			strStyles = skinFile.readAll();
		skinFile.close();
	}

	return strStyles;
}

//==================================================================================================
static void initResourceSearch(QSettings & settings)
{
	QSettingGroup config(settings, "Search");

	QStringList resDirs = settings.childKeys();
	foreach(const QString & resDir, resDirs)
	{
		QStringList resPaths = config.stringList(resDir);
		QDir::setSearchPaths(resDir, dirExpand(resPaths));
	}
}

static void initResourceFiles(QSettings & settings)
{
	QSettingGroup config(settings, "Resource");

	QStringList resPaths = settings.childKeys();
	foreach(const QString & resRoot, resPaths)
	{
		QString resFile = config.string(resRoot);
		regResource(resFile, resRoot);
	}
}

static void initPluginsPaths(QSettings & settings)
{
	QSettingGroup config(settings, "Plugins");

	QStringList libraryPaths;
	QStringList listPaths = settings.childKeys();
	foreach(const QString & dirPath, listPaths)
	{
		libraryPaths += config.stringList(dirPath);
	}

	libraryPaths = dirExpand(libraryPaths);
	libraryPaths += qApp->libraryPaths();
	qApp->setLibraryPaths(libraryPaths);
}

static void initAppSettings(QSettings & settings)
{
	QSettingGroup config(settings, "Application");
	QByteArray codec = config.byteArray("LocaleCodec", "GB18030");
	QTextCodec::setCodecForLocale(QTextCodec::codecForName(codec));
	addTranslator(config.string("Language", "zh_CN"));
	setSkinStyles(config.string("Theme", "Default"));
}


//==================================================================================================
void initAppResource()
{
	QDir::setCurrent(dirExpand("$(AppDir)"));

	QString appFile = QCoreApplication::applicationDirPath() + "/app.ini";
	QSettings config(appFile, QSettings::IniFormat);
	initResourceSearch(config);
	initResourceFiles(config);
	initPluginsPaths(config);
	initAppSettings(config);
}

void initApplication()
{
	//加载默认翻译文件
	setTranslator(LANG_CH);

	//初始化图标库
	initIconFonts();

	//加载默认皮肤文件
}

//==================================================================================================
void regWindowTitle(QWidget * widget, QAbstractButton * btnClose, QAbstractButton * btnMin, QAbstractButton * btnMaxRestore, QWidget * title)
{
	CHK_EXP_END(widget == NULL);

	while(widget->parent())
	{
		if (widget->parent()->inherits("QWidget"))
		{
			widget = qobject_cast<QWidget*>(widget->parent());
		}
		else
		{
			break;
		}
	}

	QPointer<FrameHelper> frameHelper = new FrameHelper(widget, title);

	frameHelper->addEdgeWidget(widget);
	frameHelper->addDragWidget(widget);
	frameHelper->setCloseButton(btnClose);
	frameHelper->setMinimizedButton(btnMin);
	frameHelper->setMaxRestoreButton(btnMaxRestore);

}

MainWindow * getMainWindow(QWidget * window)
{
	QPointer<MainWindow> widget = new MainWindow();
	widget->setWidget(window);
	return widget;
}

//==================================================================================================
void regButtonIcon(QAbstractButton * button, QWidget * parent)
{
	QPointer<ButtonFontIcon> fontBtn = new ButtonFontIcon(button, parent);
}


//==================================================================================================


//==================================================================================================
UI_NAMESPACE_END