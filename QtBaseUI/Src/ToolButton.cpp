#include "stdafx.h"
#include "ToolButton.h"
#include <QMenu>
#include <QLabel>

ToolButton::ToolButton(QWidget *parent)
	: QPushButton(parent)
{
	setFlat(true);
}

ToolButton::~ToolButton()
{

}

/***********************************************************************************************************************************/
void ToolButton::setMenu(QMenu* menu)
{
#ifdef Q_OS_LINUX
    connect(menu, SIGNAL(aboutToHide()), this, SLOT(recover()));
#endif

	QPushButton::setMenu(menu);
}

QString ToolButton::fontIconText()
{
	return strFontIconText;
}

void ToolButton::setFontIconText(const QString & text)
{
	strFontIconText = text;
	const QFont & btnFont = this->font();
	btnFont.set
	QLabel labIcon;
	labIcon.setFont(btnFont);
	QRect labRect(0, 0, iconSize().width(), iconSize().height());
	labIcon.setGeometry(labRect);
	labIcon.setText(text);
	labIcon.setAlignment(Qt::AlignCenter);
	QPixmap pixmap = labIcon.grab(labRect);
	setIcon(pixmap);
}

/***********************************************************************************************************************************/
void ToolButton::recover()
{
#ifdef Q_OS_LINUX
	bool flag = this->rect().contains(this->mapFromGlobal(QCursor::pos()));
	this->setAttribute(Qt::WA_UnderMouse, flag);
	this->update();
#endif
}
