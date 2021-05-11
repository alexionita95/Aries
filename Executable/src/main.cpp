#include<glad/gl.h>
#include<GLFW/glfw3.h>
#include <iostream>
int main(void)
{

	if (!glfwInit())
	{
		std::cerr << "Could not init GLFW";
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
	//glfwWindowHint(GLFW_MOUSE_PASSTHROUGH, GLFW_TRUE);
	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window)
	{
		std::cerr << "Could not create window";
		return -1;
	}
	glfwSetWindowPos(window, 100, 100);

	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColorMask(true, true, true, true);
	glClearColor(0, 0, 0, 1.0f);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == 1)
		{
			std::cout << "Click";
			glfwSetWindowAttrib(window, GLFW_MOUSE_PASSTHROUGH, GLFW_TRUE);
		}
	}

	return 0;
}
