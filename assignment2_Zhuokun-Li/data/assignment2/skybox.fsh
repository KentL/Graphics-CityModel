#version 150

in vec3 TexCoord0;

out vec4 PixelColor;

uniform samplerCube sky_tex;

void main()
{
    PixelColor = texture(sky_tex,TexCoord0);
}
