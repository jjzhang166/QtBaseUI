#pragma once

#include <QObject>

#include <QTimer>
#include <QWidget>
#include <QPointer>
#include <QScopedPointer> 

#include "AppGlobal.h"

class QPainter;
class QRect;

class QTBASEUI_EXPORT AppFontIconAnimation : public QObject
{
Q_OBJECT

public:
    AppFontIconAnimation( QWidget* parentWidget, int interval=10, int step=1);

    void setup( QPainter& painter, const QRect& rect );

public slots:
    void update();

private:
    QPointer<QWidget> parentWidgetRef_;
	QScopedPointer<QTimer> timer_;
    int interval_;
    int step_;
    float angle_;
};
