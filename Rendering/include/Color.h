#ifndef COLOR_H
#define COLOR_H
#include<inttypes.h>
#include<glm/glm.hpp>
namespace aries {
namespace rendering {
class Color
{
public:
    Color();
    Color(const uint8_t& r_, const uint8_t& g_, const uint8_t& b_, const uint8_t& a_);
    Color(const uint8_t& r_, const uint8_t& g_, const uint8_t& b_);
    glm::vec4 get() const;

private:
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    glm::vec4 normalized;
};
}
}
#endif // COLOR_H
