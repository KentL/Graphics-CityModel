#version 150

// Scene info
uniform mat4 WorldViewProj;

// Attributes
in vec4 a_position;

// Varyings
out vec3 TexCoord0;

void main()
{
	vec4 WVP_POS = WorldViewProj * a_position;
    gl_Position = WVP_POS;
	TexCoord0=a_position;
}
