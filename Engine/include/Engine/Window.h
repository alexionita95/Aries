#ifndef ENGINEWINDOW_H
#define ENGINEWINDOW_H
#include <GLFW/glfw3.h>
#include<cstdint>
namespace aries {
	namespace engine
	{
		class Window
		{
		public:
			Window(const uint32_t width, const uint32_t height, const char* title);
			bool shouldBeClosed();
			void swapBuffers();
			void poolEvents();
			~Window()
			{
				if (window)
				{
					glfwDestroyWindow(window);
				}

				glfwTerminate();
			}
		private:
			GLFWwindow* window;
		};
	}

}

#endif // !ENGINEWINDOW_H
