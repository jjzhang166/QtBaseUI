#include "stdafx.h"

#include <QTimer>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QApplication>
#include <QAbstractButton>

#include "AppFunctions.h"
#include "FrameHelperPrivate.h"

#if defined Q_OS_WIN
#include <windowsx.h>
#include <windows.h>
#endif

FrameHelperPrivate::FrameHelperPrivate(QWidget *parent, QWidget * title)
    : QObject(parent)
{
    this->parent = parent;
	this->title = title;

    btnClose = NULL;
    btnMinimized = NULL;
    btnMaxRestore = NULL;
    isMaximized = false;
    direction = None;
    isMousePressed = false;
	margins = QMargins(5, 5, 5, 5);

	//根据不同操作系统来区分
#ifndef Q_OS_WIN
    parent->setWindowFlags(parent->windowFlags() | (Qt::FramelessWindowHint));
    
#else
	parent->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);

	HWND hwnd = (HWND)parent->winId();
	DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
	::SetWindowLong(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION);
	qApp->installNativeEventFilter(this);
#endif

	parent->installEventFilter(this);

    timer.reset(new QTimer(this));
    timer->setInterval(400);
    connect(timer.data(), SIGNAL(timeout()), this, SLOT(checkPos()));
    timer->start();
}

FrameHelperPrivate::~FrameHelperPrivate()
{

}

void FrameHelperPrivate::addEdgeWidget(QWidget *widget)
{
    if(!edgeWidgets.contains(widget)) 
	{
        edgeWidgets.append(widget);

        if(!dragWidgets.contains(widget)) 
		{
            widget->installEventFilter(this);
        }
    }
}

void FrameHelperPrivate::addDragWidget(QWidget *widget)
{
    if(!dragWidgets.contains(widget)) 
	{
        dragWidgets.append(widget);

        if(!edgeWidgets.contains(widget)) 
		{
            widget->installEventFilter(this);
        }
    }
}

void FrameHelperPrivate::checkPos()
{
    QRect rectMustIn = parent->frameGeometry();
    QRect rectMustNotIn = rectMustIn.marginsRemoved(margins);

    QPoint cursorPos = QCursor::pos();

    if(isMaximized ||
            !parent->isActiveWindow() ||
            !rectMustIn.contains(cursorPos) ||
            rectMustNotIn.contains(cursorPos)) 
	{
        direction = None;
        parent->unsetCursor();
        return;
    }

    int baseLeftCoord, baseTopCoord, baseRightCoord, baseBottomCoord;

    rectMustNotIn.getCoords(&baseLeftCoord, &baseTopCoord, &baseRightCoord, &baseBottomCoord);

    int x, y;
    x = cursorPos.x();
    y = cursorPos.y();

    direction = None;

    if(x < baseLeftCoord) 
	{
        if(y < baseTopCoord) 
		{
            direction = LeftTop;
        } 
		else if(y > baseBottomCoord) 
		{
            direction = LeftBottom;
        } 
		else 
		{
            direction = Left;
        }
    } 
	else if(x > baseRightCoord) 
	{
        if(y < baseTopCoord) 
		{
            direction = RightTop;
        } 
		else if(y > baseBottomCoord) 
		{
            direction = RightBottom;
        } 
		else 
		{
            direction = Right;
        }
    }

    if(direction == None) {
        if(y < baseTopCoord) 
		{
            direction = Top;
        } 
		else 
		{
            direction = Bottom;
        }
    }

    switch (direction) 
	{
	case Left:
	case Right:
		parent->setCursor(Qt::SizeHorCursor);
		break;

	case Top:
	case None:
	case Bottom:
		parent->setCursor(Qt::SizeVerCursor);
		break;

	case LeftTop:
	case RightBottom:
		parent->setCursor(Qt::SizeFDiagCursor);
		break;

	case LeftBottom:
	case RightTop:
		parent->setCursor(Qt::SizeBDiagCursor);
		break;

    }
}

void FrameHelperPrivate::resize(const QPoint &cursorPos)
{
    QSize oldSize = parent->size();

    int x, y, width = 0, height = 0;

    switch (direction) 
	{
    case Left: // left
        width = oldSize.width() - cursorPos.x();
        height = oldSize.height();

        x = parent->pos().x() - (width - oldSize.width());
        y = parent->pos().y();
        break;

    case Right: //right
        width = cursorPos.x();
        height = oldSize.height();

        x = parent->pos().x();
        y = parent->pos().y();
        break;

    case LeftTop: //left top
        width = oldSize.width() - cursorPos.x();
        height = oldSize.height() - cursorPos.y();

        x = parent->pos().x() - (width - oldSize.width());
        y = parent->pos().y() - (height - oldSize.height());
        break;

    case RightTop: //right top
        width = cursorPos.x();
        height = oldSize.height() - cursorPos.y();

        x = parent->pos().x();
        y = parent->pos().y() - (height - oldSize.height());

        break;

    case LeftBottom: //left bottom
        width = oldSize.width() - cursorPos.x();
        height = cursorPos.y();

        x = parent->pos().x() - (width - oldSize.width());
        y = parent->pos().y();

        break;

    case RightBottom: //right bottom
        width = cursorPos.x();
        height = cursorPos.y();

        x = parent->pos().x();
        y = parent->pos().y();
        break;

    case Top: //top
        width = oldSize.width();
        height =  oldSize.height() - cursorPos.y();

        x = parent->pos().x();
        y = parent->pos().y() - (height - oldSize.height());
        break;

    case Bottom: //bottom
        width = oldSize.width();
        height = cursorPos.y();

        x = parent->pos().x();
        y = parent->pos().y();
        break;

    default:
        width = cursorPos.x();
        height = cursorPos.y();

        x = parent->pos().x();
        y = parent->pos().y();
        break;
    }

    if(width > (margins.left() + margins.right()) && height > (margins.top() + margins.bottom())) 
	{
        parent->move(x, y);
        parent->resize(width, height);
    }
}

void FrameHelperPrivate::refreshMaximizedButton()
{
	if (parent->isMaximized())
	{
		btnMaxRestore->setObjectName(QStringLiteral("btnMax"));
		btnMaxRestore->setToolTip(tr("Max"));
		parent->showNormal();
		isMaximized = false;
	}
	else
	{
		btnMaxRestore->setObjectName(QStringLiteral("btnRestore"));
		btnMaxRestore->setToolTip(tr("Restore"));
		parent->showMaximized();
		isMaximized = true;
	}

	updateStyle(btnMaxRestore);

}

bool FrameHelperPrivate::eventFilter(QObject *obj, QEvent *event)
{
	do 
	{
        if(event->type() == QEvent::MouseButtonPress) 
		{
            QMouseEvent *e = (QMouseEvent *)event;

            // no move, no drag
            if(e->button() != Qt::LeftButton  || isMaximized) 
			{
                break;
            }

            checkPos();

            if((obj == parent || edgeWidgets.contains(qobject_cast<QWidget *>(obj))) && direction != None) 
			{
                isMousePressed = true;
                operation = MoveResize;
                timer->stop();
                return true;
            }

            if(dragWidgets.contains(qobject_cast<QWidget *>(obj)) && direction == None) 
			{
                isMousePressed = true;
                operation = MoveDrag;
                dragBasePoint =  e->globalPos() - parent->pos();
                timer->stop();
                return true;
            }

            break;
        }

        if(event->type() == QEvent::MouseMove && isMousePressed) 
		{
            QMouseEvent *e = (QMouseEvent *)event;

            if(operation == MoveDrag) 
			{
                parent->move(e->globalPos() - dragBasePoint);
                return true;
            }

            if(operation == MoveResize) 
			{
                if(obj != parent) 
				{
                    QWidget *w = qobject_cast<QWidget *>(obj);
                    resize(w->mapTo(parent, e->pos()));
                } else 
				{
                    resize(e->pos());
                }
                return true;
            }
            break;
        }

        if(event->type() == QEvent::MouseButtonRelease) 
		{
            QMouseEvent *e = (QMouseEvent *)event;
            if(e->button() == Qt::LeftButton && isMousePressed) 
			{
                isMousePressed = false;
                operation = MoveNone;
                timer->start();
                return true;
            }
            break;
        }

		if (event->type() == QEvent::MouseButtonDblClick)
		{
			QMouseEvent *e = (QMouseEvent *)event;
			if (e->button() == Qt::LeftButton)
			{
				const QPoint & pt = e->pos();
				if (!title.isNull() && title->rect().contains(pt))
				{
					refreshMaximizedButton();
					return true;
				}
			}
			break;
		}

	} while (false);

    return QObject::eventFilter(obj, event);
}

bool FrameHelperPrivate::checkTitleButton(int x, int y)
{
	if (title && title->rect().contains(x, y))
	{
		QWidget * child = title->childAt(x, y);
		if (child->inherits("QAbstractButton"))
		{
			return false;
		}
		return true;
	}
	return false;
}

bool FrameHelperPrivate::nativeEventFilter(const QByteArray &eventType, void *message, long *result)
{
#if defined Q_OS_WIN

	MSG* msg = (MSG*)message;
	switch (msg->message) 
	{
	case WM_NCHITTEST:
	{
		int xPos = GET_X_LPARAM(msg->lParam) - parent->frameGeometry().x();
		int yPos = GET_Y_LPARAM(msg->lParam) - parent->frameGeometry().y();

		if(checkTitleButton(xPos, yPos))
		{
			*result = HTCAPTION;
			return true;
		}
	}
	break;

	case WM_NCCALCSIZE:
		return true;

	case WM_GETMINMAXINFO:
	{
		if (::IsZoomed(msg->hwnd)) 
		{
			// 最大化时会超出屏幕，所以填充边框间距
			RECT frame = { 0, 0, 0, 0 };
			AdjustWindowRectEx(&frame, WS_OVERLAPPEDWINDOW, FALSE, 0);
			frame.left = abs(frame.left);
			frame.top = abs(frame.bottom);
			parent->setContentsMargins(frame.left, frame.top, frame.right, frame.bottom);
		}
		else 
		{
			parent->setContentsMargins(0, 0, 0, 0);
		}

		*result = ::DefWindowProc(msg->hwnd, msg->message, msg->wParam, msg->lParam);
		return true;
	}
	break;
	}

#endif

	return false;
}

