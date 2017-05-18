#pragma once

#include "AppGlobal.h"
#include <QToolButton>

UI_NAMESPACE_BEGIN
//==================================================================================================
class ToolButton : public QToolButton
{
	Q_OBJECT
	Q_PROPERTY(QFont fontIcon READ iconFont WRITE setIconFont)
	Q_PROPERTY(QString fontIconText READ iconFontText WRITE setIconFontText)
	Q_PROPERTY(QColor fontIconColor READ iconFontColor WRITE setIconFontColor)

public:
	ToolButton(QWidget *parent);
	~ToolButton();

public:
	//ʹ������������ð�ťͼ��
	QFont iconFont();
	void setIconFont(const QFont & font);



	QString iconFontText();
	void setIconFontText(const QString & text);

	QColor iconFontColor();
	void setIconFontColor(const QColor & color);

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
