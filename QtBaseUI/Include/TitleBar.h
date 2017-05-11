#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QAbstractButton>

#include "AppGlobal.h"
#include "AppStruct.h"

namespace Ui{ class TitleBar; }

class QTBASEUI_EXPORT TitleBar : public QWidget
{
	Q_OBJECT

public:
	TitleBar(QWidget *parent = 0);
	~TitleBar();

public:
	void setPixmap(const QPixmap & pximap);
	void setTitleText(const QString & title);
	void setBtnVisible(ButtonType Type, bool visible);

private:
	Ui::TitleBar * ui;
};

#endif // TITLEBAR_H
