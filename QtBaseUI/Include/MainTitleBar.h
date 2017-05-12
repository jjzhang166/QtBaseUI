#pragma once

#include "AppGlobal.h"
#include "AppStruct.h"

#include <QWidget>

class QMenu;
namespace Ui { class MainTitleBar; };
//==================================================================================================

UI_NAMESPACE_BEGIN
//==================================================================================================
class QTBASEUI_EXPORT MainTitleBar : public QWidget
{
	Q_OBJECT

public:
	MainTitleBar(QWidget *parent = Q_NULLPTR);
	~MainTitleBar();

public:
	void setTitleIcon(const QPixmap & pximap);
	void setTitleText(const QString & title);
	void setBtnVisible(ButtonType Type, bool visible);

public:
	void setBtnSkinMenu(QMenu * menu);
	void setBtnMoreMenu(QMenu * menu);

private:
	Ui::MainTitleBar * ui;
};

//==================================================================================================
UI_NAMESPACE_END

USE_UI_NAMESPACE