#include<glad/glad.h>

#include <Renderer.h>
#include<iostream>
namespace aries {
namespace rendering {
void Renderer::Init()
{
    gladLoadGL();
}

void Renderer::Render()
		{
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);
            glClearColor(1, 0, 0, 0.5f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	}
}
