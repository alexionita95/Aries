#ifndef QT_RENDERER_WIDGET_H
#define QT_RENDERER_WIDGET_H
#include<Renderer2D.h>
#include<OrthoCamera.h>
#include<QOpenGLWidget>
#include <QTimer>
#include<memory>
#include<TextureLoader.h>
#include<Texture.h>
#include<Physics/Particles/Particle.h>
#include<Physics/Particles/ForceHandler.h>
#include<Physics/Particles/ForceGenerators/ForceGenerator.h>
#include<Physics/Particles/ForceGenerators/GravityGenerator.h>
#include<glm/glm.hpp>

using namespace aries::physics::particles;
class QtRendererWidget: public QOpenGLWidget
{
    Q_OBJECT
public:
    QtRendererWidget(QWidget* parent=nullptr);
    void generate();

    // QOpenGLWidget interface
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    std::shared_ptr<aries::rendering::Renderer2D> renderer;
    std::shared_ptr<aries::rendering::OrthoCamera> camera;
    QTimer *timer;
    aries::rendering::TextureLoader loader;
    aries::rendering::Texture texture1;
    aries::rendering::Texture texture2;
    std::vector<ParticleHandle> particles;
    forcegenerators::ParticleForceGeneratorHandle gravityGenerator;
    forcegenerators::ParticleForceGeneratorHandle springGenerator;
    forcegenerators::ParticleForceGeneratorHandle springGenerator1;
    forcegenerators::ParticleForceGeneratorHandle springGenerator2;
    ParticleHandle a,b;
    ForceHandler handler;

protected slots:
    void timerTimeout();

};

#endif // QT_RENDERER_WIDGET_H
