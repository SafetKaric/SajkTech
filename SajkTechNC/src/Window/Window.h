#pragma once

#include "GLFW/glfw3.h"

class Window
{
private:
	int m_Width;
	int m_Heigth;
	const char* m_Title;
	GLFWwindow* m_Window;
public:
	Window(int width, int heigth, const char* title);
	~Window();

	bool ShouldClose();
	GLFWwindow* GetWindow() const { return m_Window; }
};

