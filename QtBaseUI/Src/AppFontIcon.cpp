#include "stdafx.h"
#include "AppFontIcon.h"

#include <QFile>
#include <QFontDatabase>
#include <QScopedPointer>

//----------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------
bool AppFontIcon::initFontAwesome()
{
    static int fontAwesomeFontId = -1;
    if( fontAwesomeFontId < 0 ) 
	{
        QFile res(":/fonts/iconfont.ttf");
        if(!res.open(QIODevice::ReadOnly)) 
		{
            qDebug() << "Font awesome font could not be loaded!";
            return false;
        }
        QByteArray fontData( res.readAll() );
        res.close();

        fontAwesomeFontId = QFontDatabase::addApplicationFontFromData(fontData);
    }

    QStringList loadedFontFamilies = QFontDatabase::applicationFontFamilies(fontAwesomeFontId);
    if( !loadedFontFamilies.empty() ) 
	{
       loadedFontFamilies.at(0);
    } 
	else 
	{
        qDebug() << "Font awesome font is empty?!";
        fontAwesomeFontId = -1;
        return false;
    }
    return true;
}

//----------------------------------------------------------------------------------------------------------------------------