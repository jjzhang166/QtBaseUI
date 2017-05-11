#pragma once

#include "AppGlobal.h"
#include "AppStruct.h"

#include <QWidget>

namespace Ui { class MainTitleBar; };

class QTBASEUI_EXPORT MainTitleBar : public QWidget
{
	Q_OBJECT

public:
	MainTitleBar(QWidget *parent = Q_NULLPTR);
	~MainTitleBar();

public:
	void setPixmap(const QPixmap & pximap);
	void setTitleText(const QString & title);
	void setBtnVisible(ButtonType Type, bool visible);

private:
	Ui::MainTitleBar *ui;
};
