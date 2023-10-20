#include<glad/glad.h>
#include<glm/gtc/matrix_transform.hpp>

#include<Rendering/2D/Renderer2D.h>
#include<Rendering/Vertex2D.h>
#include<Rendering/Color.h>
#include<Rendering/TextureLoader.h>
#include<iostream>
namespace aries {
namespace rendering {
Renderer2D::Renderer2D(const std::shared_ptr<OrthoCamera>& camera_): VBO{0},VAO{0}, EBO{0},defaultTexture{},
    camera {camera_},
    shader {std::make_shared<Shader>()}
{


}

void Renderer2D::Init()
{
    gladLoadGL();
    shader->Load("resources/shaders/default2d.vs","resources/shaders/default2d.fs");

    defaultTexture = TextureLoader::CreateFlat(1,1,0xffffffff);
    InitQuad();
}

void Renderer2D::BeginScene()
{
    shader->Use();
    shader->setMat4("projection",camera->getProjection());
    shader->setMat4("view", camera->getView());
    shader->setVec4("drawColor",glm::vec4(1));
    shader->setInt("drawTexture",0);
    shader->setInt("hasTexture", 0);
}

void Renderer2D::Draw(const Drawable& drawable)
{
    glBindVertexArray(VAO);
    shader->setMat4("model", drawable.getModel());
    shader->setVec4("drawColor", drawable.getColor().get());
    if (drawable.hasTexture())
    {
        shader->setInt("hasTexture", 1);
        drawable.getTexture()->Bind();
        shader->setVec4("region", drawable.getTextureRect());
        shader->setVec2("texSize", drawable.getTexture()->getSize());
    }
    else
    {
        shader->setInt("hasTexture", 0);
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer2D::DrawQuad(const float &x, const float &y, const float &width, const float height, const Color &color)
{
    glm::mat4 model = calculateModelMatrix(glm::vec3(x+width/2,y+height/2,0),0,glm::vec3(width,height,1));
    glBindVertexArray(VAO);
    shader->setMat4("model",model);
    shader->setVec4("drawColor",color.get());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void Renderer2D::DrawLine(const float &x1, const float &y1, const float &x2, const float y2, const Color &color, const float &size)
{
    glm::vec3 firstPoint(x1,y1,0);
    glm::vec3 secondPoint(x2,y2,0);
    glm::vec3 dir = secondPoint-firstPoint;
    float width = glm::length(dir);
    dir = glm::normalize(dir);
    glm::vec3 center = firstPoint + dir*width/2.0f;
    glm::vec3 axis(1,0,0);
    float dot = glm::dot(axis,dir);
    float det = axis.x*dir.y - dir.x* axis.y;
    float angle =glm::degrees(atan2(det,dot));
    DrawRotatedQuad(center.x,center.y,width,size,angle, color);
}

void Renderer2D::DrawCenterdQuad(const float &x, const float &y, const float &width, const float height, const Color &color)
{
    DrawQuad(x-width/2,y-height/2,width,height,color);
}

void Renderer2D::DrawRotatedQuad(const float &x, const float &y, const float &width, const float height, float degrees, const Color &color)
{
    glm::mat4 model = calculateModelMatrix(glm::vec3(x,y,0),degrees,glm::vec3(width,height,1));
    glBindVertexArray(VAO);
    shader->setInt("hasTexture", 0);
    shader->setMat4("model",model);
    shader->setVec4("drawColor",color.get());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer2D::DrawQuad(const float &x, const float &y, const float &width, const float height, Texture &texture, const Color& color)
{
    glm::mat4 model = calculateModelMatrix(glm::vec3(x+width/2,y+height/2,0),0,glm::vec3(width,height,1));
    glBindVertexArray(VAO);
    texture.Bind();
    shader->setInt("hasTexture", 1);
    shader->setMat4("model",model);
    shader->setVec4("drawColor",color.get());
    shader->setVec4("region", glm::vec4(0, 0, 64, 64));
    shader->setVec2("texSize", texture.getSize());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer2D::DrawCentredQuad(const float &x, const float &y, const float &width, const float height, Texture &texture, const Color& color)
{
    DrawQuad(x-width/2,y-height/2,width,height,texture,color);
}

void Renderer2D::DrawRotatedQuad(const float &x, const float &y, const float &width, const float height, float degrees, Texture &texture,const Color& color)
{
    glm::mat4 model = calculateModelMatrix(glm::vec3(x,y,0),degrees,glm::vec3(width,height,1));
    glBindVertexArray(VAO);
    texture.Bind();
    shader->setInt("hasTexture", 1);
    shader->setMat4("model",model);
    shader->setVec4("drawColor",color.get());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer2D::Clear(const Color &color)
{
    //glEnable( GL_DEPTH_TEST );
   // glDepthFunc(GL_LESS);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    //glBlendEquation(GL_FUNC_ADD);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glm::vec4 colorValue = color.get();
    glClearColor(colorValue.r, colorValue.g, colorValue.b, colorValue.a);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void Renderer2D::InitQuad()
{
   /* Vertex2D vertices[] = {
         Vertex2D(0.5f,  0.5f, 0.0f,  1.0f, 1.0f), // top right
         Vertex2D(0.5f, -0.5f, 0.0f,  1.0f, 0.0f), // bottom right
        Vertex2D(-0.5f, -0.5f, 0.0f,  0.0f, 0.0f), // bottom left
        Vertex2D(-0.5f,  0.5f, 0.0f,  0.0f, 1.0f)  // top left
    };
    */
        Vertex2D vertices[] = {
        Vertex2D(1.0f, 1.0f, 0.0f,  1.0f, 1.0f), // top right
        Vertex2D(1.0f, 0.0f, 0.0f,  1.0f, 0.0f), // bottom right
        Vertex2D(0.0f, 0.0f, 0.0f,  0.0f, 0.0f), // bottom left
        Vertex2D(0.0f, 1.0f, 0.0f,  0.0f, 1.0f)  // top left
    };

    unsigned int indices[] = {
         0, 1, 3,
         3, 1, 2
     };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)(offsetof(Vertex2D, Position)));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)(offsetof(Vertex2D, TexCoords)));
    glEnableVertexAttribArray(1);
}

glm::mat4 Renderer2D::calculateModelMatrix(const glm::vec3 &position, const float &degrees, const glm::vec3 &scale)
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model,position);
    model = glm::rotate(model,glm::radians(degrees),glm::vec3(0,0,1));
    model = glm::scale(model,scale);
return model;
}
}
}
