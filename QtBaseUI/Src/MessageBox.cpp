﻿#include "stdafx.h"
#include "MessageBox.h"
#include "ui_MessageBox.h"

#include "FrameHelper.h"
#include "AppStruct.h"
#include "AppFontIcon.h"

/***********************************************************************************************************************************/
MessageBox::MessageBox(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::MessageBox();
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);

	initDialog();
	initIcon();
}

MessageBox::~MessageBox()
{
	//CHK_POINT_DESTORY(pFrameHelper);
	delete ui;
}

/***********************************************************************************************************************************/
void MessageBox::setContent(MessageType type, const QString & text)
{
	Type = type;
	ui->text->setText(text);
	initIcon();
}

/***********************************************************************************************************************************/
void MessageBox::initIcon()
{
	ui->btnNo->setVisible(false);
	ui->btnCancel->setVisible(false);
	switch (Type)
	{
	case MT_OK:
		ui->labTitle->setText(tr("Info Message"));
		ui->icon->setPixmap(QPixmap(":/images/system/messagebox/ok.png"));
		break;

	case MT_ERROR:
		ui->labTitle->setText(tr("Error Message"));
		ui->icon->setPixmap(QPixmap(":/images/system/messagebox/error.png"));
		break;

	case MT_WARNING:
		ui->labTitle->setText(tr("Warn Message"));
		ui->icon->setPixmap(QPixmap(":/images/system/messagebox/warning.png"));
		break;

	case MT_QUESTION:
		ui->btnYes->setText(tr("Yes"));
		ui->btnNo->setVisible(true);
		ui->btnCancel->setVisible(true);
		ui->labTitle->setText(tr("Question Message"));
		ui->icon->setPixmap(QPixmap(":/images/system/messagebox/question.png"));
		break;

	case MT_QUESTION2:
		ui->btnYes->setText(tr("Yes"));
		ui->btnNo->setVisible(true);
		ui->labTitle->setText(tr("Question Message"));
		ui->icon->setPixmap(QPixmap(":/images/system/messagebox/question.png"));
		break;

	case MT_INFO:
	default:
		ui->labTitle->setText(tr("Kindly Reminder"));
		ui->icon->setPixmap(QPixmap(":/Images/messagebox/info"));
		break;
	}

}

#include "AppHelper.h"
void MessageBox::initDialog()
{
	Type = MT_INFO;
	resize(QSize(200, 130));
	ui->text->setWordWrap(true);
	
	pFrameHelper = new FrameHelper(this);
	pFrameHelper->addEdgeWidget(this);
	pFrameHelper->addDragWidget(this);
	pFrameHelper->setCloseButton(ui->btnClose);
}

/***********************************************************************************************************************************/
void MessageBox::on_btnYes_clicked()
{
	done(RET_YES);
}

void MessageBox::on_btnNo_clicked()
{
	done(RET_NO);
}

void MessageBox::on_btnCancel_clicked()
{
	done(RET_CANCEL);
}
