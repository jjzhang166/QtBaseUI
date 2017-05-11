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

void MainWindow::setWindowTitle(const QString strTitle)
{
	ui->title->setTitleText(strTitle);
}

//==================================================================================================
UI_NAMESPACE_END