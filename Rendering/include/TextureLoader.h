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
    Texture Load(const std::string& path);

};
}
}

#endif // TEXTURELOADER_H
