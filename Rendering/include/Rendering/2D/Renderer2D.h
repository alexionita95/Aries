#ifndef RENDERER2D_H
#define RENDERER2D_H
#include<glm/glm.hpp>
#include<memory>


#include<Rendering/OrthoCamera.h>
#include<Rendering/Shader.h>
#include<Rendering/Color.h>
#include<Rendering/Texture.h>

namespace aries {
    namespace rendering {
class Renderer2D
{
public:
    Renderer2D(const std::shared_ptr<OrthoCamera>& camera_);
    void Init();
    void BeginScene();
    void DrawQuad(const float& x, const float& y, const float& width, const float height, const Color& color);
    void DrawLine(const float& x1, const float& y1, const float& x2, const float y2, const Color& color, const float& size=1.0f);
    void DrawCenterdQuad(const float& x, const float& y, const float& width, const float height, const Color& color);
    void DrawRotatedQuad(const float& x, const float& y, const float& width, const float height, float degrees, const Color& color);
    void DrawQuad(const float& x, const float& y, const float& width, const float height, Texture& texture, const Color& color=Color(255,255,255,255));
    void DrawCentredQuad(const float& x, const float& y, const float& width, const float height, Texture& texture, const Color& color=Color(255,255,255,255));
    void DrawRotatedQuad(const float& x, const float& y, const float& width, const float height, float degrees, Texture& texture, const Color& color=Color(255,255,255,255));
    void Clear(const Color& color);

private:
    void InitQuad();
    glm::mat4 calculateModelMatrix(const glm::vec3& position, const float& degrees, const glm::vec3& scale);

    std::shared_ptr<OrthoCamera> camera;
    std::shared_ptr<Shader> shader;
    Texture defaultTexture;
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
};
}
}
#endif // RENDERER2D_H
