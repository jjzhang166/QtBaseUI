#pragma once
#include "AppGlobal.h"
#include "AppStruct.h"

#include <QWidget>

class QMenu;
namespace Ui { class MainWindow; };

UI_NAMESPACE_BEGIN
//==================================================================================================
class QTBASEUI_EXPORT MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

public:
	void setWidget(QWidget * pWdiget);
	void setTitleIcon(const QPixmap & pximap);
	void setTitleText(const QString & title);
	void setBtnVisible(ButtonType Type, bool visible);

public:
	void setBtnSkinMenu(QMenu * menu);
	void setBtnMoreMenu(QMenu * menu);

private:
	Ui::MainWindow * ui;
};


//==================================================================================================
UI_NAMESPACE_END