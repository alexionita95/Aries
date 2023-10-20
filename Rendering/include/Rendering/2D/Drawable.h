#pragma once
#include<glm/glm.hpp>
#include<Rendering/Color.h>
#include<Rendering/Texture.h>
namespace aries {
	namespace rendering {
		class Drawable
		{
		public:
			Drawable();
			Drawable(const glm::vec3& position, const glm::vec2& size, const glm::vec2& scale = glm::vec2(1), const float rotation = 0);
			Drawable(const glm::vec3& position, const glm::vec2& size, const Color& color = Color(255,255,255,255), const glm::vec2& scale = glm::vec2(1), const float rotation = 0);
			Drawable(const glm::vec3& position, const glm::vec2& size, const TextureHandle& texture, const glm::vec2& scale = glm::vec2(1), const float rotation = 0);
			Drawable(const glm::vec3& position, const glm::vec2& size, const TextureHandle& texture, const Color& color, const glm::vec2& scale = glm::vec2(1), const float rotation = 0);
			const glm::mat4& getModel() const {return m_model;}
			const glm::vec3& getPosition() const { return m_position; }
			const glm::vec2& getSize() const { return m_size; }
			const glm::vec2& getScale() const { return m_scale; }
			const float& getRotation() const { return m_rotation; }
			const Color& getColor() const { return m_color; }
			const TextureHandle& getTexture() const { return m_texture; }
			const glm::vec4& getTextureRect() const { return m_textureRect; }
			void setPosition(const glm::vec3& value);
			void setSize(const glm::vec2& value);
			void setScale(const glm::vec2& value);
			void setRotation(const float value);
			void setColor(const Color& value);
			void setTexture(const TextureHandle& value);
			void setTextureRect(const glm::vec4& value);
			const bool hasTexture() const { return m_texture != nullptr; }

		private:
			void calculateModelMatrix();
			glm::vec3 m_position;
			glm::vec2 m_size;
			glm::vec2 m_scale;
			float m_rotation;
			Color m_color;
			TextureHandle m_texture;
			glm::vec4 m_textureRect;
			glm::mat4 m_model;
		};
	}
}