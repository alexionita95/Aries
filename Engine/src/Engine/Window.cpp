#include<GLFW/glfw3.h>
#include<Engine/Window.h>
namespace aries {
	namespace engine
	{
		Window::Window(const uint32_t width, const uint32_t height, const char* title):
			window{nullptr}
		{
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

			if (!glfwInit())
				return;

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

			window = glfwCreateWindow(width,height,title, NULL, NULL);
			if (!window)
			{
				glfwTerminate();
				return;
			}
			glfwMakeContextCurrent(window);
		}
		bool Window::shouldBeClosed()
		{
			return glfwWindowShouldClose(window);
		}
		void Window::swapBuffers()
		{
			glfwSwapBuffers(window);
		}
		void Window::poolEvents()
		{
			glfwPollEvents();
		}
	}
}