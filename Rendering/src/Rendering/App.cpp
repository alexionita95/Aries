#include<Rendering/App.h>
namespace aries {
	namespace rendering
	{
		App::App(const uint32_t width, const uint32_t height, const char* title)
		{
			lastTime = std::chrono::steady_clock::now();
			window = std::make_shared<Window>(width, height, title);

		}
		void App::run()
		{
			
			while (!window->shouldBeClosed())
			{
				auto now = std::chrono::steady_clock::now();
				float delta = std::chrono::duration<float>(now - lastTime).count();
				lastTime = now;
				update(delta);
				render(delta);
				window->swapBuffers();
				window->poolEvents();
			}
		}
	}
}