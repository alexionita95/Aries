#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>
namespace aries {
namespace rendering {
struct Texture
{
    GLuint id;

    void Bind()
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, id);
    }

};
}
}

#endif // TEXTURE_H
