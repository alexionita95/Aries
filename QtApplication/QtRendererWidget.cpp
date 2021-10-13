#include<Renderer.h>
#include "QtRendererWidget.h"
#include <QtDebug>
QtRendererWidget::QtRendererWidget(QWidget* parent):QOpenGLWidget(parent)
{
timer  = new QTimer(this);
connect(timer,&QTimer::timeout, this, &QtRendererWidget::timerTimeout);
}
void QtRendererWidget::initializeGL()
{
    renderer.Init();
    timer->start(16);
}
void QtRendererWidget::paintGL()
{
    renderer.Render();
}

void QtRendererWidget::timerTimeout()
{
    repaint();
}
void QtRendererWidget::resizeGL(int w, int h)
{

}
