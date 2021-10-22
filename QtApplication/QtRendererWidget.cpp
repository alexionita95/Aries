#include<Renderer2D.h>
#include "QtRendererWidget.h"
#include <QtDebug>

#include<Color.h>
QtRendererWidget::QtRendererWidget(QWidget* parent):QOpenGLWidget(parent)
{
timer  = new QTimer(this);
connect(timer,&QTimer::timeout, this, &QtRendererWidget::timerTimeout);
camera = std::make_shared<aries::rendering::OrthoCamera>(0,0,800,600);
renderer = std::make_shared<aries::rendering::Renderer2D>(camera);
}
void QtRendererWidget::initializeGL()
{
    renderer->Init();
    texture = loader.Load("crate.png");
    timer->start(16);
}
void QtRendererWidget::paintGL()
{
    renderer->Clear(aries::rendering::Color(0x00,0xEB,0x00));
    renderer->DrawQuad(100,100,100,100,aries::rendering::Color(255,255,255));
    renderer->DrawRotatedQuad(210,100,300,300,angle,texture);
}

void QtRendererWidget::timerTimeout()
{
    repaint();
}
void QtRendererWidget::resizeGL(int w, int h)
{

}
