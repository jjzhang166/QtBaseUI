#pragma once

#include <QMainWindow>
#include "ui_MainWindowTitle.h"

class MainWindowTitle : public QMainWindow
{
	Q_OBJECT

public:
	MainWindowTitle(QWidget *parent = Q_NULLPTR);
	~MainWindowTitle();

private:
	Ui::MainWindowTitle ui;
};
