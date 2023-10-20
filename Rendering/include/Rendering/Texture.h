#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>
#include<glm/glm.hpp>
#include<memory>
namespace aries {
	namespace rendering {
		class Texture
		{
		public:
			Texture()
				:m_id{ 0 }
				, m_width{ 0 }
				, m_height{ 0 }
				, m_size{ 0 }
				, m_bounds{ 0 }
			{
			}
			Texture(GLuint id, float width, float height)
				:m_id{ id }
				, m_width{ width }
				, m_height{ height }
				, m_size{ width,height }
				, m_bounds{ 0,0,width,height }
			{
			}
			void Bind()
			{
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, m_id);
			}
			const float getWidth() const { return m_width; }
			const float getHeight() const { return m_height; }
			const glm::vec2& getSize() const { return m_size; }
			const glm::vec4& getBounds() const { return m_bounds; }
		private:
			GLuint m_id;
			float m_width;
			float m_height;
			glm::vec2 m_size;
			glm::vec4 m_bounds;

		};
		using TextureHandle = std::shared_ptr<Texture>;
	}
}

#endif // TEXTURE_H
