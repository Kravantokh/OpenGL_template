#version 410 core

out vec4 FragColor;
uniform vec4 Color;
uniform vec4 Color2;
uniform vec4 Color3;
uniform vec4 Color4;
uniform vec4 Color5;

void main()
{
	FragColor = Color + Color2 + Color3 + Color4 + Color5;
}
