﻿#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include "AppGlobal.h"
#include <QDialog>


namespace Ui { class MessageBox; };

//UI_NAMESPACE_BEGIN
namespace BASEUI {
//==================================================================================================
enum MessageType
{
	MT_INFO = 0,
	MT_OK,
	MT_ERROR,
	MT_WARNING,
	MT_QUESTION,
	MT_QUESTION2
};

class FrameHelper;
class MessageBox : public QDialog
{
	Q_OBJECT

public:
	MessageBox(QWidget *parent = NULL);
	~MessageBox();


public:
	void setContent(MessageType type, const QString & text);

protected:
	void initIcon();
	void initDialog();

protected slots:
	void on_btnYes_clicked();
	void on_btnNo_clicked();
	void on_btnCancel_clicked();

private:
	MessageType Type;
	Ui::MessageBox *ui;
	FrameHelper * pFrameHelper;
};


//==================================================================================================
};
//UI_NAMESPACE_END

#endif // MESSAGEBOX_H
