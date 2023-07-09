#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "primitives/Triangle.h"
#include "primitives/Square.h"
#include "primitives/Circle.h"

class Window
{
private:

	unsigned width, height;

	GLFWwindow* glfwWindow = nullptr;

public:

	Window(unsigned width, unsigned height);
	~Window();

	void Open();

	static void onKey(GLFWwindow* window, int key, int scancode, int action, int mode);
};

