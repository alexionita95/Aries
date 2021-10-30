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
#include<Physics/Particles/ForceGenerators/DragForceGenerator.h>
#include<Color.h>
#include<glm/glm.hpp>
#include<chrono>
using namespace aries::physics::particles;
class QtRendererWidget: public QOpenGLWidget
{
    Q_OBJECT
public:
    QtRendererWidget(QWidget* parent=nullptr);
    void generate();
    void toggleDebug();
signals:
    void updateFPS(float fps);
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
    std::vector<ParticleHandle> particles;
    std::vector<aries::rendering::Color> colors;
    forcegenerators::ParticleForceGeneratorHandle gravityGenerator;
    forcegenerators::ParticleForceGeneratorHandle springGenerator;
    forcegenerators::ParticleForceGeneratorHandle dragForceGenerator;
    ParticleHandle a,b;
  //  ForceHandler handler;
    std::chrono::time_point<std::chrono::steady_clock> lastTime;
    int samples;
    float fpsSamples;
    glm::vec3 anchorPosition;
    bool debug;
protected slots:
    void timerTimeout();

};

#endif // QT_RENDERER_WIDGET_H
