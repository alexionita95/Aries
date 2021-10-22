#include "../include/Color.h"
namespace aries {
namespace rendering {
Color::Color(): r{0}, g{0},b{0},a{255}, normalized{glm::vec4(0,0,0,1)}
{

}

Color::Color(const uint8_t &r_, const uint8_t &g_, const uint8_t &b_, const uint8_t &a_):
    r{r_},g{g_},b{b_},a{a_},
    normalized {glm::vec4((float)(r_/255.0f),(float)(g_/255.0f),(float)(b_/255.0f),(float)(a_/255.0f))}
{

}

Color::Color(const uint8_t &r_, const uint8_t &g_, const uint8_t &b_):
    r{r_},g{g_},b{b_},a{255},
    normalized {glm::vec4((float)(r_/255.0f),(float)(g_/255.0f),(float)(b_/255.0f),1)}
{

}

glm::vec4 Color::get() const
{
    return normalized;
}

}
}
