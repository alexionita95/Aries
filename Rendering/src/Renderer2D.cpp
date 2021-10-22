#include<glad/glad.h>
#include<glm/gtc/matrix_transform.hpp>

#include<Renderer2D.h>
#include<Vertex.h>
#include<Color.h>
namespace aries {
namespace rendering {
Renderer2D::Renderer2D(const std::shared_ptr<OrthoCamera>& camera_):
    camera {camera_},
    colorShader {std::make_shared<Shader>()},
    textureShader {std::make_shared<Shader>()}
{


}

void Renderer2D::Init()
{
    gladLoadGL();
    colorShader->Load("shaders/color2d.vs","shaders/color2d.fs");
    textureShader->Load("shaders/texture2d.vs","shaders/texture2d.fs");
    InitQuad();
}

void Renderer2D::DrawQuad(const float &x, const float &y, const float &width, const float height, const Color &color)
{
    glm::mat4 model = calculateModelMatrix(glm::vec3(x+width/2,y+height/2,0),0,glm::vec3(width,height,1));
    glBindVertexArray(VAO);
    colorShader->Use();
    colorShader->setMat4("projection",camera->getProjection());
    colorShader->setMat4("model",model);
    colorShader->setVec4("drawColor",color.get());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void Renderer2D::DrawCenterdQuad(const float &x, const float &y, const float &width, const float height, const Color &color)
{
    DrawQuad(x-width/2,y-height/2,width,height,color);
}

void Renderer2D::DrawRotatedQuad(const float &x, const float &y, const float &width, const float height, float degrees, const Color &color)
{
    glm::mat4 model = calculateModelMatrix(glm::vec3(x+width/2,y+height/2,0),degrees,glm::vec3(width,height,1));
    glBindVertexArray(VAO);
    colorShader->Use();
    colorShader->setMat4("projection",camera->getProjection());
    colorShader->setMat4("model",model);
    colorShader->setVec4("drawColor",color.get());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer2D::DrawQuad(const float &x, const float &y, const float &width, const float height, Texture &texture)
{
    glm::mat4 model = calculateModelMatrix(glm::vec3(x+width/2,y+height/2,0),0,glm::vec3(width,height,1));
    glBindVertexArray(VAO);
    textureShader->Use();
    texture.Bind();
    textureShader->setMat4("projection",camera->getProjection());
    textureShader->setMat4("model",model);
    textureShader->setInt("drawTexture",0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer2D::DrawCentredQuad(const float &x, const float &y, const float &width, const float height, Texture &texture)
{
    DrawQuad(x-width/2,y-height/2,width,height,texture);
}

void Renderer2D::DrawRotatedQuad(const float &x, const float &y, const float &width, const float height, float degrees, Texture &texture)
{
    glm::mat4 model = calculateModelMatrix(glm::vec3(x+width/2,y+height/2,0),degrees,glm::vec3(width,height,1));
    glBindVertexArray(VAO);
    textureShader->Use();
    texture.Bind();
    textureShader->setMat4("projection",camera->getProjection());
    textureShader->setMat4("model",model);
    textureShader->setInt("drawTexture",0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer2D::Clear(const Color &color)
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glm::vec4 colorValue = color.get();
    glClearColor(colorValue.r, colorValue.g, colorValue.b, colorValue.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer2D::InitQuad()
{
    Vertex2D vertices[] = {
         Vertex2D(0.5f,  0.5f, 0.0f,  1.0f, 1.0f), // top right
         Vertex2D(0.5f, -0.5f, 0.0f,  1.0f, 0.0f), // bottom right
        Vertex2D(-0.5f, -0.5f, 0.0f,  0.0f, 0.0f), // bottom left
        Vertex2D(-0.5f,  0.5f, 0.0f,  0.0f, 1.0f)  // top left
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
