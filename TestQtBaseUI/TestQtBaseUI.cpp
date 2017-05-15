#include "stdafx.h"
#include "TestQtBaseUI.h"

#include "TestDialog.h"

#include "../QtBaseUI/Include/AppFunctions.h"
#include "../QtBaseUI/Include/AppHelper.h"

TestQtBaseUI::TestQtBaseUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	pTitle = new TitleBar(this);
	pTitle->setGeometry(0, 30, width(), 30);
}


#include <QMessageBox>
void TestQtBaseUI::on_btnAlert_clicked()
{
	TestDialog tt;
	tt.exec();
	//qMsgBoxAlert("Hello");
	//QMessageBox::about(this, "Hello", "Hi");
}