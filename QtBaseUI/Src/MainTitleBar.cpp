#include "stdafx.h"
#include "MainTitleBar.h"
#include "ui_MainTitleBar.h"
#include "AppHelper.h"


UI_NAMESPACE_BEGIN
//==================================================================================================
MainTitleBar::MainTitleBar(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::MainTitleBar();
	ui->setupUi(this);

	regWindowTitle(parent, ui->btnClose, ui->btnMin, ui->btnMax, this);
}

MainTitleBar::~MainTitleBar()
{
	delete ui;
}

//==================================================================================================
void MainTitleBar::setPixmap(const QPixmap & pximap)
{
	ui->labIcon->setPixmap(pximap);
}


void MainTitleBar::setTitleText(const QString & title)
{
	ui->labTitle->setText(title);
}

void MainTitleBar::setBtnVisible(ButtonType type, bool visible)
{
	switch (type)
	{
	case BUTTON_MIN:
		ui->btnMin->setVisible(visible);
		break;
	case BUTTON_MAX:
		ui->btnMax->setVisible(visible);
		break;
	case BUTTON_CLOSE:
		ui->btnClose->setVisible(visible);
		break;
	case BUTTON_SKIN:
		ui->btnSkin->setVisible(visible);
		break;
	case BUTTON_MORE:
		ui->btnMore->setVisible(visible);
		break;
	default:
		break;
	}
}


//==================================================================================================
UI_NAMESPACE_END
