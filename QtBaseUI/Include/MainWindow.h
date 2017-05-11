#pragma once

#include <QWidget>

#include "AppGlobal.h"

namespace Ui { class MainWindow; };

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
