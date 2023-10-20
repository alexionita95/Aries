#include<Rendering/2D/Renderer2D.h>
#include<Rendering/App.h>
#include<stdio.h>
#include<memory>
#include<Rendering/OrthoCamera.h>
#include<Rendering/Color.h>
#include<Rendering/TextureLoader.h>
class MyApp : public aries::rendering::App 
{
private:
	std::shared_ptr<aries::rendering::OrthoCamera> camera;
	std::shared_ptr<aries::rendering::Renderer2D> renderer;
	aries::rendering::TextureHandle texture;
	aries::rendering::Drawable drawable;
	int index;
public:
	MyApp(const uint32_t width, const uint32_t height, const char* title) : App(width, height, title),
		camera{std::make_shared<aries::rendering::OrthoCamera>(0,800, 600, 0)},
		renderer{ std::make_shared<aries::rendering::Renderer2D>(camera)}
	{
		renderer->Init();
		aries::rendering::TextureLoader loader;
		texture = loader.LoadHandle("resources/crate.png");
		drawable = aries::rendering::Drawable(glm::vec3(64, 64, 0), glm::vec2(64, 64), texture);
		index = 0;
		camera->setZoom(1);

	}
	// Inherited via App
	virtual void render(const float delta) override
	{
		int tileSize = 64;
		glm::vec3 pos(0);
		renderer->Clear(aries::rendering::Color(0, 0,0, 255));
		renderer->BeginScene();
		renderer->Draw(drawable);
		int gridW = 800 / tileSize;
		int gridH = 600 / tileSize;
		for (int i = 0; i < gridW + 1; ++i)
		{
			for (int j = 0; j < gridH + 1; ++j)
			{
				drawable.setPosition(glm::vec3(i * tileSize, j * tileSize, 0));
				renderer->Draw(drawable);
			}
		}
	}
	virtual void update(const float delta) override
	{
		glm::vec3 cameraPos = camera->getPosition();
		//cameraPos.x += 0.5f;
		//camera->setPosition(cameraPos);
	}
};

int main()
{
	std::shared_ptr<aries::rendering::App> app = std::make_shared<MyApp>(800, 600, "Fuck you");
	app->run();
}
