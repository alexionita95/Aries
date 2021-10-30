#include<Renderer2D.h>
#include "QtRendererWidget.h"
#include <QtDebug>
#include<Physics/Particles/ForceGenerators/AnchoredSpringForceGenerator.h>
#include<Physics/Particles/ForceGenerators/BungeeForceGenerator.h>
#include<Physics/Particles/ForceGenerators/SpringForceGenerator.h>
#include<iostream>

#include<Color.h>
float pixelsPerMeter = 100.0f;

QtRendererWidget::QtRendererWidget(QWidget* parent):QOpenGLWidget(parent)
{

    samples =0;
    fpsSamples=0;
    timer  = new QTimer(this);
    connect(timer,&QTimer::timeout, this, &QtRendererWidget::timerTimeout);
    camera = std::make_shared<aries::rendering::OrthoCamera>(0,0,800,600,true);
    renderer = std::make_shared<aries::rendering::Renderer2D>(camera);
}
void QtRendererWidget::generate()
{
    ParticleHandle particle = std::make_shared<Particle>(glm::vec3((rand() % 800 + 1)/pixelsPerMeter,(rand() % 600 + 1)/pixelsPerMeter,0),1.1f);
    ParticleHandle last = particles.back();
    auto springGenerator1 = std::make_shared<forcegenerators::BungeeForceGenerator>(last,10.0f,0.1f);
    auto springGenerator2 = std::make_shared<forcegenerators::BungeeForceGenerator>(particle,10.0f,0.1f);
    particle->addGenerator(springGenerator1);
    last->addGenerator(springGenerator2);
    particle->addGenerator(gravityGenerator);
    particle->addGenerator(dragForceGenerator);
    //handler.add(springGenerator1, particle);
   // handler.add(springGenerator2, last);
    particle->setDamping(0.3f);
    particles.push_back(particle);
    colors.push_back(aries::rendering::Color(rand() % 254 + 1,rand() % 254 + 1,rand() % 254 + 1,255));
    // handler.add(gravityGenerator,particle);
}

void QtRendererWidget::toggleDebug()
{
    debug=!debug;
}
void QtRendererWidget::initializeGL()
{
    debug=false;
    anchorPosition=glm::vec3(400/pixelsPerMeter,600/pixelsPerMeter,0);
    renderer->Init();
    texture1 = loader.Load("circle.png");
    lastTime = std::chrono::steady_clock::now();
    timer->start(16);
    gravityGenerator = std::make_shared<forcegenerators::GravityGenerator>(glm::vec3(0,-10,0));
    dragForceGenerator =  std::make_shared<forcegenerators::DragForceGenerator>(0.27f,0.27f);
    a = std::make_shared<Particle>(glm::vec3(200/pixelsPerMeter,200/pixelsPerMeter,0),1.0f);
    b = std::make_shared<Particle>(glm::vec3(350,400,0),40.0f);
    a->setDamping(0.5f);

    springGenerator = std::make_shared<forcegenerators::AnchoredSpringForceGenerator>(anchorPosition,10.0f,0.1f);
    a->addGenerator(gravityGenerator);
    a->addGenerator(springGenerator);
    a->addGenerator(dragForceGenerator);
   // handler.add(gravityGenerator,a);
    //handler.add(springGenerator,a);
    particles.push_back(a);
    colors.push_back(aries::rendering::Color(rand() % 254 + 1,rand() % 254 + 1,rand() % 254 + 1,255));
}
void QtRendererWidget::paintGL()
{
    float lineSize=2;
    renderer->Clear(aries::rendering::Color(0x00,0x00,0x00));
    renderer->BeginScene();
    renderer->DrawLine(anchorPosition.x*pixelsPerMeter,anchorPosition.y*pixelsPerMeter,particles[0]->getPosition().x*pixelsPerMeter,particles[0]->getPosition().y*pixelsPerMeter,aries::rendering::Color(255,255,255,255),lineSize);
    renderer->DrawCentredQuad(anchorPosition.x*pixelsPerMeter,anchorPosition.y*pixelsPerMeter,10,10,texture1, aries::rendering::Color(0xFF,0x00, 0x00, 0xFF));
    for(int index = 0; index<particles.size();++index)
    {
        glm::vec3 position = particles[index]->getPosition();
        if(index < particles.size()-1)
        {

            renderer->DrawLine(particles[index]->getPosition().x*pixelsPerMeter, particles[index]->getPosition().y*pixelsPerMeter,particles[index+1]->getPosition().x*pixelsPerMeter,particles[index+1]->getPosition().y*pixelsPerMeter,aries::rendering::Color(255,255,255,255),lineSize);

        }
        renderer->DrawCentredQuad(particles[index]->getPosition().x*pixelsPerMeter,particles[index]->getPosition().y*pixelsPerMeter,15,15,texture1, colors[index]);

        if(debug){
        for(const auto& force : particles[index]->debugForcesVector)
        {
            glm::vec3 normalized = glm::normalize(force);
            glm::vec3 end = position+normalized*glm::length(force);

            renderer->DrawLine(position.x*pixelsPerMeter,position.y*pixelsPerMeter,end.x*pixelsPerMeter,end.y*pixelsPerMeter,aries::rendering::Color(255,0,0,255));

        }

        glm::vec3 result = position+glm::normalize(glm::normalize(particles[index]->getForceAccumulator()))*glm::length(particles[index]->getForceAccumulator());
        renderer->DrawLine(position.x*pixelsPerMeter,position.y*pixelsPerMeter,result.x*pixelsPerMeter,result.y*pixelsPerMeter,aries::rendering::Color(0,0,255,255));
        glm::vec3 velocity = position+glm::normalize(glm::normalize(particles[index]->getVelocity()))*glm::length(particles[index]->getVelocity());
        renderer->DrawLine(position.x*pixelsPerMeter,position.y*pixelsPerMeter,velocity.x*pixelsPerMeter,velocity.y*pixelsPerMeter,aries::rendering::Color(0,255,0,255));
        }
    }



}



void QtRendererWidget::timerTimeout()
{
    int maxSamples =20;
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<float> ellapsed = now - lastTime;
    float dt = ellapsed.count();
    fpsSamples +=1.0f/dt;
    samples++;
    if(samples >= maxSamples)
    {
        emit updateFPS(fpsSamples/maxSamples);
        samples =0;
        fpsSamples=0;
    }
    lastTime=now;
    //handler.update(dt);
    for(const auto& particle:particles)
    {

        particle->update(dt);
    }

    repaint();
}
void QtRendererWidget::resizeGL(int w, int h)
{

}
