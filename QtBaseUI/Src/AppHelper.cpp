#include "stdafx.h"
#include "AppHelper.h"

#include <QDir>
#include <QPointer>
#include <QResource>
#include <QSettings>
#include <QTextCodec>
#include <QTranslator>
#include <QApplication>
#include <QScopedPointer>

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
	QTranslator * translator = new QTranslator(0);
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
void initApplication()
{
	QDir::setCurrent(dirExpand("$(AppDir)"));

	QString appFile = QCoreApplication::applicationDirPath() + "/app.ini";
	QSettings config(appFile, QSettings::IniFormat);
	initResourceSearch(config);
	initResourceFiles(config);
	initPluginsPaths(config);
	initAppSettings(config);
}


//==================================================================================================
void regWindowTitle(QWidget * widget, QAbstractButton * btnClose, QAbstractButton * btnMin, QAbstractButton * btnMaxRestore, QWidget * title)
{
	CHK_EXP_END(widget == NULL);

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