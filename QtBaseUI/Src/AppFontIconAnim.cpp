#include "stdafx.h"
#include "AppFontIconAnim.h"

#include <cmath>
#include <QPainter>
#include <QRect>

AppFontIconAnimation::AppFontIconAnimation(QWidget *parentWidget, int interval, int step)
    : parentWidgetRef_( parentWidget )
    , timer_( 0 )
    , interval_( interval )
    , step_( step )
    , angle_( 0.0f )
{

}

void AppFontIconAnimation::setup( QPainter &painter, const QRect &rect)
{
    if( !timer_ )
    {
        timer_.reset(new QTimer());
        connect(timer_.data(),SIGNAL(timeout()), this, SLOT(update()) );
        timer_->start(interval_);
    }
    else
    {
        float x_center = rect.width() * 0.5;
        float y_center = rect.height() * 0.5;
        painter.translate(x_center, y_center);
        painter.rotate(angle_);
        painter.translate(-x_center, -y_center);
    }
}


void AppFontIconAnimation::update()
{
    angle_ += step_;
    angle_ = std::fmod( angle_, 360);
    parentWidgetRef_->update();
}
