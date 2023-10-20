#ifndef ENGINEAPP_H
#define ENGINEAPP_H
#include<Rendering/Window.h>
#include<chrono>
#include<memory>
namespace aries {
	namespace rendering
	{
		class App
		{
		public:
			App(const uint32_t width, const uint32_t height, const char* title);
			void run();
			virtual void update(const float delta) = 0;
			virtual void render(const float delta) = 0;
			virtual ~App()
			{
			}

		private:
			std::shared_ptr<Window> window;
			std::chrono::time_point<std::chrono::steady_clock> lastTime;

		};
	}
}
#endif // ENGINEAPP_H