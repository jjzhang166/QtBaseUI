#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include "AppGlobal.h"
#include <QPushButton>


UI_NAMESPACE_BEGIN
//==================================================================================================
class QTBASEUI_EXPORT PushButton : public QPushButton
{
	Q_OBJECT

	Q_PROPERTY(QFont fontIcon READ iconFont WRITE setIconFont)
	Q_PROPERTY(QString fontIconText READ iconFontText WRITE setIconFontText)
	Q_PROPERTY(QColor fontIconColor READ iconFontColor WRITE setIconFontColor)

public:
	PushButton(QWidget *parent = 0);
	~PushButton();

public:
	void setMenu(QMenu *);

	//使用字体库来设置按钮图标
	QFont iconFont();
	void setIconFont(const QFont & font);

	QString iconFontText();
	void setIconFontText(const QString & text);

	QColor iconFontColor();
	void setIconFontColor(const QColor & color);

public slots:
	void recover();

protected:
	void paintButtonIcon();

private:
	QFont fontIcon;
	QColor fontIconColor;
	QString fontIconText;
};


//==================================================================================================
UI_NAMESPACE_END

USE_UI_NAMESPACE
#endif // TOOLBUTTON_H
