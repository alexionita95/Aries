#include<Renderer2D.h>
#include "QtRendererWidget.h"
#include <QtDebug>

#include<Color.h>
QtRendererWidget::QtRendererWidget(QWidget* parent):QOpenGLWidget(parent)
{
timer  = new QTimer(this);
connect(timer,&QTimer::timeout, this, &QtRendererWidget::timerTimeout);
camera = std::make_shared<aries::rendering::OrthoCamera>(0,0,800,600,true);
renderer = std::make_shared<aries::rendering::Renderer2D>(camera);
}
void QtRendererWidget::initializeGL()
{
    renderer->Init();
    texture1 = loader.Load("crate.png");
    texture2 = loader.Load("crate.png");
    timer->start(16);
    gravityGenerator = std::make_shared<forcegenerators::GravityGenerator>(glm::vec3(1000,-100,0));
    generate();

}
void QtRendererWidget::paintGL()
{
    renderer->Clear(aries::rendering::Color(0x00,0x00,0x00));
    //renderer->DrawQuad(100,100,100,100,aries::rendering::Color(255,255,255));
    renderer->DrawQuad(10,10,300,450,texture2);

    for(const auto& particle : particles)
    {
        glm::vec3 pos = particle->getPosition();
        renderer->DrawQuad(pos.x,pos.y,50,50,texture1);
    }

}

void QtRendererWidget::generate()
{
 ParticleHandle particle = std::make_shared<Particle>(glm::vec3(200,75,0),20.0f);
 particle->setDamping(0.99f);
 particles.push_back(particle);
 handler.add(gravityGenerator,particle);
}

void QtRendererWidget::timerTimeout()
{
    float dt =16.0f/1000.0f;
    handler.update(dt);
    for(const auto& particle : particles)
    {
        particle->integrate(dt);
    }
    repaint();
}
void QtRendererWidget::resizeGL(int w, int h)
{

}
