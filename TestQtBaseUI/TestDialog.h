#pragma once

#include <QDialog>
#include "ui_TestDialog.h"

class TestDialog : public QDialog
{
	Q_OBJECT

public:
	TestDialog(QWidget *parent = Q_NULLPTR);
	~TestDialog();

private:
	Ui::TestDialog ui;
};
