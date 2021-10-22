#ifndef QT_RENDERER_WIDGET_H
#define QT_RENDERER_WIDGET_H
#include<Renderer2D.h>
#include<OrthoCamera.h>
#include<QOpenGLWidget>
#include <QTimer>
#include<memory>
#include<TextureLoader.h>
#include<Texture.h>

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
    std::shared_ptr<aries::rendering::Renderer2D> renderer;
    std::shared_ptr<aries::rendering::OrthoCamera> camera;
    QTimer *timer;
    aries::rendering::TextureLoader loader;
    aries::rendering::Texture texture;
protected slots:
    void timerTimeout();

};

#endif // QT_RENDERER_WIDGET_H
