#include "GL/glew.h"
#include "Shader/Shader.h"
#include "Window/Window.h"
#include "VertexBuffer/VertexBuffer.h"
#include <iostream>

int main()
{
	float points[] = 
	{
		-0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f
	};

	Window win = Window(1280, 720, "SajkTechNC");

	VertexBuffer vbo = VertexBuffer(points);

	Shader shader = Shader("res/Shaders/basic.shader");

	while(!win.ShouldClose())
	{

		glClearColor(0.12f, 0.12f, 0.12f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		vbo.Bind();
		shader.Bind();

		glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(win.GetWindow());
		glfwPollEvents();
	}
}