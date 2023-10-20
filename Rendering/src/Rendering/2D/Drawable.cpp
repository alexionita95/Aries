#include<Rendering/2D/Drawable.h>
#include<glm/gtc/matrix_transform.hpp>
namespace aries {
	namespace rendering {
		Drawable::Drawable()
			: m_position{ 0 }
			, m_size{ 1 }
			, m_scale{ glm::vec2(1) }
			, m_rotation{ 0 }
			, m_color{ 255,255,255,255 }
			, m_texture{ nullptr }
			, m_textureRect {0}
			, m_model { glm::mat4(1)}
		{
			calculateModelMatrix();
		}
		Drawable::Drawable(const glm::vec3& position, const glm::vec2& size, const glm::vec2& scale, const float rotation)
			: m_position{ position }
			, m_size{ size }
			, m_scale{ scale }
			, m_rotation{ rotation }
			, m_color{ 255,255,255,255 }
			, m_texture{ nullptr }
			, m_textureRect{ 0 }
			, m_model{ glm::mat4(1) }
		{
			calculateModelMatrix();
		}
		Drawable::Drawable(const glm::vec3& position, const glm::vec2& size, const Color& color, const glm::vec2& scale, const float rotation)
			:m_position{ position }
			, m_size{ size }
			, m_scale{ scale }
			, m_rotation{ rotation }
			, m_color{ color }
			, m_texture{ nullptr }
			, m_textureRect{ 0 }
			, m_model{ glm::mat4(1) }
		{
			calculateModelMatrix();
		}
		Drawable::Drawable(const glm::vec3& position, const glm::vec2& size, const TextureHandle& texture, const glm::vec2& scale, const float rotation)
			:m_position{ position }
			, m_size{ size }
			, m_scale{ scale }
			, m_rotation{ rotation }
			, m_color{ 255,255,255,255 }
			, m_texture{ texture }
			, m_textureRect{ 0 }
			, m_model{ glm::mat4(1) }
		{
			calculateModelMatrix();
			if (m_texture != nullptr)
			{
				setTextureRect(m_texture->getBounds());
			}
		}
		Drawable::Drawable(const glm::vec3& position, const glm::vec2& size, const TextureHandle& texture, const Color& color, const glm::vec2& scale, const float rotation)
			:m_position{ position }
			, m_size{ size }
			, m_scale{ scale }
			, m_rotation{ rotation }
			, m_color{ color }
			, m_texture{ texture }
			, m_textureRect{ 0 }
			, m_model{ glm::mat4(1) }
		{
			calculateModelMatrix();
			if (m_texture != nullptr)
			{
				setTextureRect(m_texture->getBounds());
			}
		}
		void Drawable::setPosition(const glm::vec3& value)
		{
			m_position = value;
			calculateModelMatrix();
		}
		void Drawable::setScale(const glm::vec2& value)
		{
			m_scale = value;
			calculateModelMatrix();
		}
		void Drawable::setRotation(const float value)
		{
			m_rotation = value;
			calculateModelMatrix();
		}
		void Drawable::setColor(const Color& value)
		{
			m_color = value;
		}
		void Drawable::setTexture(const TextureHandle& value)
		{
			if (value == nullptr)
			{
				return;
			}
			m_texture = value;
			setTextureRect(m_texture->getBounds());
		}
		void Drawable::setTextureRect(const glm::vec4& value)
		{
			m_textureRect = value;
		}
		void Drawable::calculateModelMatrix()
		{
			m_model = glm::mat4(1.0f);
			m_model = glm::translate(m_model, m_position);
			m_model = glm::rotate(m_model, glm::radians(m_rotation), glm::vec3(0, 0, 1));
			m_model = glm::scale(m_model, glm::vec3(m_scale * m_size, 1));
		}
	}
}