#include<Renderer2D.h>
#include<Engine/App.h>
#include<stdio.h>
#include<memory>
#include<OrthoCamera.h>
#include<Color.h>
class MyApp : public aries::engine::App 
{
private:
	std::shared_ptr<aries::rendering::OrthoCamera> camera;
	std::shared_ptr<aries::rendering::Renderer2D> renderer;
public:
	MyApp(const uint32_t width, const uint32_t height, const char* title) : App(width, height, title),
		camera{std::make_shared<aries::rendering::OrthoCamera>(0,0,800,600,true)},
		renderer{ std::make_shared<aries::rendering::Renderer2D>(camera)}
	{
		renderer->Init();

	}
	// Inherited via App
	virtual void render(const float delta) override
	{
		renderer->Clear(aries::rendering::Color(255, 255, 255, 255));
		renderer->BeginScene();
		renderer->DrawCenterdQuad(100, 100, 100, 100, aries::rendering::Color(255, 0, 0, 255));
	}
};

int main()
{
	std::shared_ptr<aries::engine::App> app = std::make_shared<MyApp>(800, 600, "Fuck you");
	app->run();
}
