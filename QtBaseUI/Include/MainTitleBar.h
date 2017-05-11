#pragma once
#include <QWidget>

#include "AppGlobal.h"
#include "AppStruct.h"

namespace Ui { class MainTitleBar; };

UI_NAMESPACE_BEGIN
//==================================================================================================
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
	Ui::MainTitleBar * ui;
};

//==================================================================================================
UI_NAMESPACE_END

USE_UI_NAMESPACE