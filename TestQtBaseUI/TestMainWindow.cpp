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
	qMsgBoxInfo(QStringLiteral("信息提示！"));
	qMsgBoxError(QStringLiteral("信息提示！"));
	qMsgBoxAlert(QStringLiteral("信息提示！"));
	qMsgBoxOk(QStringLiteral("信息提示！"));
	qMsgBoxQuestion(QStringLiteral("信息提示！"));
	qMsgBoxQuestionTwo(QStringLiteral("信息提示！"));
}
