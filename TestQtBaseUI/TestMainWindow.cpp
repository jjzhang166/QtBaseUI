#include "stdafx.h"
#include "TestMainWindow.h"
#include "AppFunctions.h"
#include "AppHelper.h"

USE_UI_NAMESPACE

TestMainWindow::TestMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	regButtonIcon(ui.pushButton, this);
}

TestMainWindow::~TestMainWindow()
{
}

void TestMainWindow::on_pushButton_clicked()
{
	qMsgBoxInfo("123214 d df dfg efgd fgsdf d gd");
	qMsgBoxError("sdfsd sdf s");
	qMsgBoxAlert("sdf sdfsdfc");
	qMsgBoxOk("sedfsdfg s");
	qMsgBoxQuestion("sdfsadfs");
	qMsgBoxQuestionTwo("sdfgsdfsfs");
}
