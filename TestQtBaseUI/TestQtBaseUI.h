#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestQtBaseUI.h"

#include "TitleBar.h"

class TestQtBaseUI : public QMainWindow
{
	Q_OBJECT

public:
	TestQtBaseUI(QWidget *parent = Q_NULLPTR);


protected slots:
	void on_btnAlert_clicked();

private:
	Ui::TestQtBaseUIClass ui;

	TitleBar * pTitle;
};
