#include "stdafx.h"
#include "TestQtBaseUI.h"
#include <QtWidgets/QApplication>
#include "TestMainWindow.h"
#include "MainWindowTitle.h"
#include "../QtBaseUI/Include/AppHelper.h"

USE_UI_NAMESPACE

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	initApplication();
	setStyleSheet(":/qss/black.css");
	//TestQtBaseUI w;
	//w.show();
	//TestMainWindow tt;
	//tt.show();

	TestMainWindow window;
	window.show();
	MainWindow * w = getMainWindow(&window);
	w->setWindowTitle("1234");
	w->show();

	QDialog dlg;
	dlg.exec();
	//MainWindowTitle wt;
	//wt.show();
	return a.exec();
}
