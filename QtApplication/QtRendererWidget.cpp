#include<Renderer2D.h>
#include "QtRendererWidget.h"
#include <QtDebug>
#include<Physics/Particles/ForceGenerators/AnchoredSpringForceGenerator.h>
#include<Physics/Particles/ForceGenerators/BungeeForceGenerator.h>
#include<Physics/Particles/ForceGenerators/SpringForceGenerator.h>

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
    texture1 = loader.Load("circle.png");
    texture2 = loader.Load("red_circle.png");
    timer->start(16);
    gravityGenerator = std::make_shared<forcegenerators::GravityGenerator>(glm::vec3(0,-10,0));
    a = std::make_shared<Particle>(glm::vec3(200,200,0),20.0f);
    b = std::make_shared<Particle>(glm::vec3(350,400,0),20.0f);
    a->setDamping(0.9);
    b->setDamping(0.9);

    springGenerator = std::make_shared<forcegenerators::AnchoredSpringForceGenerator>(glm::vec3(200,400,0),20.0f,10.0f);
    springGenerator1 = std::make_shared<forcegenerators::BungeeForceGenerator>(a,20.0f,10.0f);
    springGenerator2 = std::make_shared<forcegenerators::BungeeForceGenerator>(b,20.0f,10.0f);
    //handler.add(springGenerator,a);
    handler.add(gravityGenerator,a);
    handler.add(gravityGenerator,b);
    handler.add(springGenerator,a);
    handler.add(springGenerator1,b);
    handler.add(springGenerator2,a);
     handler.add(springGenerator1,b);


    //handler.add(gravityGenerator,b);
    //generate();

}
void QtRendererWidget::paintGL()
{
    renderer->Clear(aries::rendering::Color(0x00,0x00,0x00));
    //renderer->DrawQuad(100,100,100,100,aries::rendering::Color(255,255,255));
    //renderer->DrawQuad(10,10,300,450,texture2);
    renderer->DrawCentredQuad(a->getPosition().x,a->getPosition().y,50,50,texture1);
    renderer->DrawCentredQuad(b->getPosition().x,b->getPosition().y,50,50,texture2);
    renderer->DrawCentredQuad(200,400,10,10,texture2);
    for(const auto& particle : particles)
    {
        glm::vec3 pos = particle->getPosition();
        renderer->DrawQuad(pos.x,pos.y,50,50,texture1);
    }

}

void QtRendererWidget::generate()
{
 ParticleHandle particle = std::make_shared<Particle>(glm::vec3(200,75,0),20.0f);
 particle->setDamping(0.1f);
 particles.push_back(particle);
 handler.add(gravityGenerator,particle);
}

void QtRendererWidget::timerTimeout()
{
    float dt =16.0f/1000.0f;
    handler.update(dt);
    a->integrate(dt);
    b->integrate(dt);
    for(const auto& particle : particles)
    {
        particle->integrate(dt);
    }
    repaint();
}
void QtRendererWidget::resizeGL(int w, int h)
{

}
