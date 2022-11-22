#version 410 core

layout (location = 0) in vec3 position;
uniform float VerticalOffset;

void main()
{
	gl_Position = vec4(position.x, position.y + VerticalOffset, position.z, 1.0);
}

