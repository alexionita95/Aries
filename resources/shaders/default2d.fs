#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
uniform vec4 drawColor;

uniform sampler2D drawTexture;

void main()
{
    FragColor = texture(drawTexture, TexCoord) * drawColor;
}