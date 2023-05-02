#include "GL/glew.h"
#include "Window.h"

#include <iostream>

Window::Window(int width, int heigth, const char* title)
	:	m_Width(width), m_Heigth(heigth), m_Title(title), m_Window(0)
{
	if (glfwInit() != GLFW_TRUE)
	{
		std::cout << "Failed to init GLFW" << std::endl;
	}

	m_Window = glfwCreateWindow(m_Width, m_Heigth, m_Title, NULL, NULL);
	if (!m_Window)
	{
		std::cout << "Failed to create a window!" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(m_Window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to init a glew!" << std::endl;
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}
}

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(m_Window);
}

Window::~Window()
{
	glfwTerminate();
}
