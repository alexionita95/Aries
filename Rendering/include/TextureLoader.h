#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#include<Texture.h>
#include<string>
namespace aries {
namespace rendering {
class TextureLoader
{
public:
    TextureLoader();
    Texture Load(const std::string& path, const bool& flip=true);
    static Texture CreateFlat(uint32_t width, uint32_t height, uint32_t color);

};
}
}

#endif // TEXTURELOADER_H
