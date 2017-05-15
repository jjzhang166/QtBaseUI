#include "stdafx.h"
#include "TestDialog.h"

#include "../QtBaseUI/Include/AppHelper.h"

TestDialog::TestDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//regWindowTitle(this, ui.btnClose, ui.btnMin, ui.btnMax);
	ui.title->setTitleText("Hello Word");
	ui.title->setStyleSheet("{background - color: rgba(45, 45, 48);}");
}

TestDialog::~TestDialog()
{
}
