#pragma once

#include <QMainWindow>
#include "ui_TestMainWindow.h"
class QRecordModel;

class TestMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	TestMainWindow(QWidget *parent = Q_NULLPTR);
	~TestMainWindow();


protected slots:
	void on_pushButton_clicked();

private:
	Ui::TestMainWindow ui;
	QRecordModel * pModel;
};


#include <QAbstractItemModel>

class QRecordModel : public QAbstractItemModel
{
public:

	virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const
	{
		if (!hasIndex(row, column, parent))
			return QModelIndex();

		return createIndex(row, column, row);
	}

	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const
	{
		return 4;
	}

	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const
	{
		if (role == Qt::DisplayRole)
			return "234235434";

		return QVariant();
	}

	virtual QModelIndex parent(const QModelIndex &index) const
	{
		return QModelIndex();
	}

	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const
	{
		if (parent.column() > 0)
			return 0;

		if (parent == QModelIndex())
			return 30;

		return 0;
	}


};