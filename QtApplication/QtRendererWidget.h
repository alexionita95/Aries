#ifndef QT_RENDERER_WIDGET_H
#define QT_RENDERER_WIDGET_H
#include<Renderer.h>
#include<QOpenGLWidget>
#include <QTimer>

class QtRendererWidget: public QOpenGLWidget
{
    Q_OBJECT
public:
    QtRendererWidget(QWidget* parent=nullptr);

    // QOpenGLWidget interface
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    aries::rendering::Renderer renderer;
    QTimer *timer;
protected slots:
    void timerTimeout();
};

#endif // QT_RENDERER_WIDGET_H
