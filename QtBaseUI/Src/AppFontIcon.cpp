#include "stdafx.h"
#include "AppFontIcon.h"

#include <QFile>
#include <QPainter>
#include <QFontDatabase>

#include <QtStaticInclude.h>

UI_NAMESPACE_BEGIN
//----------------------------------------------------------------------------------------------------------------------------
struct stFontMsg
{
	const char * fontName;	//图标库字体名称
	const char * fontRes;	//对应qrc中的文件
};

//新增字体库可在此处列出
static const stFontMsg iconFontArray[] =
{
	{ "FontAwesome",		":/fonts/fontawesome.ttf"},
	{ "iconfontsys",		":/fonts/iconfontsys.ttf"}
};

//----------------------------------------------------------------------------------------------------------------------------
void initIconFonts()
{
	for (unsigned i = 0; i < sizeof(iconFontArray) / sizeof(stFontMsg); ++i)
	{
		//QFile res(iconFontArray[i].fontRes);
		//if (!res.open(QIODevice::ReadOnly))
		//	continue;
		//
		//QByteArray fontData(res.readAll());
		//res.close();

		//QFontDatabase::addApplicationFontFromData(fontData);
		QFontDatabase::addApplicationFont(iconFontArray[i].fontRes);
	}
}

//----------------------------------------------------------------------------------------------------------------------------
QPixmap paintFontIcon(const QFont &font, const QString & text, const QColor &color, const QSize &iconSize)
{
	QPixmap pixmap(iconSize);
	pixmap.fill(Qt::transparent);
	QPainter painter(&pixmap);

	painter.setFont(font);
	painter.setPen(QPen(color));
	painter.drawText(0, 0, pixmap.width(), pixmap.height(), Qt::AlignCenter, text);
	painter.end();
	return pixmap;
}

//----------------------------------------------------------------------------------------------------------------------------
ButtonFontIcon::ButtonFontIcon(QAbstractButton * btnbutton, QWidget * parent):QWidget(parent)
{
	btnIconFont = btnbutton;

	if (btnIconFont)
	{
		this->setObjectName(btnIconFont->objectName());
	}

	fontIconSize.setWidth(16);
	fontIconSize.setHeight(16);
	
}

ButtonFontIcon::~ButtonFontIcon()
{

}

QFont ButtonFontIcon::iconFont()
{
	return fontIcon;
}

void ButtonFontIcon::setIconFont(const QFont & font)
{
	fontIcon = font;
	paintButtonIcon();
}

QSize ButtonFontIcon::iconSize()
{
	return fontIconSize;
}

void ButtonFontIcon::setIconSize(const QSize & size)
{
	fontIconSize = size;
	paintButtonIcon();
}

QString ButtonFontIcon::iconFontText()
{
	return fontIconText;
}

void ButtonFontIcon::setIconFontText(const QString & text)
{
	fontIconText = text;
	paintButtonIcon();
}

QColor ButtonFontIcon::iconFontColor()
{
	return fontIconColor;
}

void ButtonFontIcon::setIconFontColor(const QColor & color)
{
	fontIconColor = color;
	paintButtonIcon();
}

void ButtonFontIcon::paintButtonIcon()
{
	if (fontIconText.isEmpty() || !btnIconFont || fontIconSize.isEmpty())
		return;
	QSize ic = btnIconFont->iconSize();
	QPixmap img = paintFontIcon(fontIcon, fontIconText, fontIconColor, fontIconSize);
	btnIconFont->setIcon(img);

	deleteLater();
}

//------------------------------------------------------------------------------------------------------------------------------------------------
UI_NAMESPACE_END

