#include "stdafx.h"
#include "MainWindow.h"

#include "ui_MainWindow.h"

UI_NAMESPACE_BEGIN
//==================================================================================================
MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent),ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::setWidget(QWidget * pWdiget)
{
	ui->mainLayout->addWidget(pWdiget);
	ui->mainLayout->setContentsMargins(0, 0, 0, 0);
	connect(pWdiget, SIGNAL(closeWidget()), this, SLOT(close()));
}

void MainWindow::setTitleIcon(const QPixmap & pximap)
{
	ui->title->setTitleIcon(pximap);
}

void MainWindow::setTitleText(const QString & title)
{
	ui->title->setTitleText(title);
}

void MainWindow::setBtnVisible(ButtonType Type, bool visible)
{
	ui->title->setBtnVisible(Type, visible);
}

//==================================================================================================
void MainWindow::setBtnSkinMenu(QMenu * menu)
{
	ui->title->setBtnSkinMenu(menu);
}

void MainWindow::setBtnMoreMenu(QMenu * menu)
{
	ui->title->setBtnMoreMenu(menu);
}



//==================================================================================================
UI_NAMESPACE_END