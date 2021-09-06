#ifndef QT_RENDERER_WIDGET_H
#define QT_RENDERER_WIDGET_H
#include<Renderer.h>
#include<QOpenGLWidget>

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
};

#endif // QT_RENDERER_WIDGET_H
