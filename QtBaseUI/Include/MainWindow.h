#pragma once
#include "AppGlobal.h"

#include <QWidget>

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
	void setWindowTitle(const QString strTitle);

private:
	Ui::MainWindow * ui;
};


//==================================================================================================
UI_NAMESPACE_END