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
	qMsgBoxInfo(QStringLiteral("��Ϣ��ʾ��"));
	qMsgBoxError(QStringLiteral("��Ϣ��ʾ��"));
	qMsgBoxAlert(QStringLiteral("��Ϣ��ʾ��"));
	qMsgBoxOk(QStringLiteral("��Ϣ��ʾ��"));
	qMsgBoxQuestion(QStringLiteral("��Ϣ��ʾ��"));
	qMsgBoxQuestionTwo(QStringLiteral("��Ϣ��ʾ��"));
}
