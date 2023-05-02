#shader vertex
#version 330 core

layout(location = 0) in vec3 a_pos;

void main()
{
	gl_Position = vec4(a_pos, 1.0f);
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

void main()
{
	color = vec4(0.0f, 0.0f, 1.0f, 1.0f);
}