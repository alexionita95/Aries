#include <Rendering/OrthoCamera.h>
#include<glm/gtc/matrix_transform.hpp>
namespace aries {
	namespace rendering {
		OrthoCamera::OrthoCamera()
			:position{ glm::vec3(0) }
			,size{800,600}
			,zoom {1}
			,projection{ glm::ortho(0, 800, 600, 0) }
			, view{ glm::mat4(1)}
		{
			calculateViewMatrix();
		}
		OrthoCamera::OrthoCamera(const float left, const float right, const float bottom, const float top)
			:position{ glm::vec3(0) }
			, size{ glm::vec2(right,bottom) }
			, zoom { 1 }
			, projection{ glm::ortho(left, right, bottom, top,-1.0f,1.0f) }
			, view{ glm::mat4(1)}
		{
			calculateViewMatrix();
		}

		void OrthoCamera::calculateViewMatrix()
		{
			view = glm::translate(glm::mat4(1.0f), -position);
			view = glm::scale(view, glm::vec3(zoom, zoom, 1));
		}

	}
}
