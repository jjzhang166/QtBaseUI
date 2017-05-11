#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include "AppGlobal.h"
#include <QPushButton>

class QTBASEUI_EXPORT ToolButton : public QPushButton
{
	Q_OBJECT

	Q_PROPERTY(QString fontIconText READ text WRITE setFontIconText)

public:
	ToolButton(QWidget *parent = 0);
	~ToolButton();

public:
	void setMenu(QMenu *);

	//使用字体库来设置按钮图标
	QString fontIconText();
	void setFontIconText(const QString & text);

public slots:
	void recover();

private:
	QString strFontIconText;
};

#endif // TOOLBUTTON_H
