#include "stdafx.h"
#include "AppFontIcon.h"

#include <QFile>
#include <QPainter>
#include <QFontDatabase>

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
	{ "iconfont",		":/fonts/iconfont.ttf"}
};

//----------------------------------------------------------------------------------------------------------------------------
void initIconFonts()
{
	for (unsigned i = 0; i < sizeof(iconFontArray) / sizeof(stFontMsg); ++i)
	{
		QFile res(iconFontArray[i].fontRes);
		if (!res.open(QIODevice::ReadOnly))
			continue;

		QByteArray fontData(res.readAll());
		res.close();

		QFontDatabase::addApplicationFontFromData(fontData);
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