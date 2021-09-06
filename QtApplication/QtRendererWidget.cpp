#include<Renderer.h>
#include "QtRendererWidget.h"
#include <QtDebug>
QtRendererWidget::QtRendererWidget(QWidget* parent):QOpenGLWidget(parent)
{

}
void QtRendererWidget::initializeGL()
{
    renderer.Init();
}
void QtRendererWidget::paintGL()
{
    renderer.Render();
}
void QtRendererWidget::resizeGL(int w, int h)
{

}
