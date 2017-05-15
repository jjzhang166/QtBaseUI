#pragma once

#include <QMainWindow>
#include "ui_TestMainWindow.h"

class TestMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	TestMainWindow(QWidget *parent = Q_NULLPTR);
	~TestMainWindow();


protected slots:
	void on_pushButton_clicked();

private:
	Ui::TestMainWindow ui;
};
