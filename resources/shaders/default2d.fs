#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
uniform vec4 drawColor;
uniform vec2 texSize;
uniform vec4 region;
uniform int hasTexture;

uniform sampler2D drawTexture;

float map(float value, float min1, float max1, float min2, float max2)
{
    return min2 + (value - min1) * (max2 - min2) / (max1 - min1);
}

vec2 map(vec2 coords, vec2 size, vec4 region)
{
    float texMinX = region.x/size.x;
    float texMinY = (size.y - region.y)/size.y;
    float texMaxX = (region.x + region.z) / size.x;
    float texMaxY = (size.y - (region.y + region.w)) / size.y;
    float x= map(coords.x,0,1,texMinX, texMaxX);
    float y = map(coords.y, 0, 1, texMinY, texMaxY);
    return vec2(x,y);
}
void main()
{
    if(hasTexture == 1)
    {
        //FragColor = texture(drawTexture, map(TexCoord, texSize, region)) * drawColor;
        FragColor = texture(drawTexture, TexCoord) * drawColor;
    }
    else
    {
        FragColor = drawColor;
    }
}