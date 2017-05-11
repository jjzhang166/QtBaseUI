#ifndef LFFRAMEHELPER_H
#define LFFRAMEHELPER_H

#include <QObject>
#include <QMargins>

#include "AppGlobal.h"

class QWidget;
class QAbstractButton;
class FrameHelperPrivate;

class QTBASEUI_EXPORT FrameHelper : public QObject
{
    Q_OBJECT
public:
    explicit FrameHelper(QWidget *parent, QWidget * title = 0);
	~FrameHelper();


public:
    void setResizeMargins(int margin);
    void setResizeMargins(const QMargins &margins);

	void setCloseButton(QAbstractButton *button, bool edgeResize = true);
	void setMinimizedButton(QAbstractButton *button, bool edgeResize = true);
	void setMaxRestoreButton(QAbstractButton *button, bool edgeResize = true);

    void addEdgeWidget(QWidget *widget);
    void addDragWidget(QWidget *widget);

	void convertMaxAndRestore();

private:
    FrameHelperPrivate *d;
};

#endif // FRAMELESSHELPER_H