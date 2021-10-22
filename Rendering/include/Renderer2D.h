#ifndef RENDERER2D_H
#define RENDERER2D_H
#include<glm/glm.hpp>
#include<memory>


#include<OrthoCamera.h>
#include<Shader.h>
#include<Color.h>
#include<Texture.h>

namespace aries {
    namespace rendering {
class Renderer2D
{
public:
    Renderer2D(const std::shared_ptr<OrthoCamera>& camera_);
    void Init();
    void DrawQuad(const float& x, const float& y, const float& width, const float height, const Color& color);
    void DrawCenterdQuad(const float& x, const float& y, const float& width, const float height, const Color& color);
    void DrawRotatedQuad(const float& x, const float& y, const float& width, const float height, float degrees, const Color& color);
    void DrawQuad(const float& x, const float& y, const float& width, const float height, Texture& texture);
    void DrawCentredQuad(const float& x, const float& y, const float& width, const float height, Texture& texture);
    void DrawRotatedQuad(const float& x, const float& y, const float& width, const float height, float degrees, Texture& texture);
    void Clear(const Color& color);

private:
    void InitQuad();
    glm::mat4 calculateModelMatrix(const glm::vec3& position, const float& degrees, const glm::vec3& scale);

    std::shared_ptr<OrthoCamera> camera;
    std::shared_ptr<Shader> colorShader;
    std::shared_ptr<Shader> textureShader;
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
};
}
}
#endif // RENDERER2D_H
