#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <TextureLoader.h>
#include <iostream>
namespace aries {
namespace rendering {
TextureLoader::TextureLoader()
{

}

Texture TextureLoader::Load(const std::string &path)
{
glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
glPixelStorei(GL_PACK_ALIGNMENT, 1);
Texture result;
int width, height, nrChannels;
stbi_set_flip_vertically_on_load(true);
unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
unsigned int texture;
glGenTextures(1, &texture);
glBindTexture(GL_TEXTURE_2D, texture);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
// set texture filtering parameters
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
if(data)
{
    if(nrChannels>3){
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    else
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }
    glGenerateMipmap(GL_TEXTURE_2D);
}
stbi_image_free(data);
result.id = texture;
return result;
}
}
}