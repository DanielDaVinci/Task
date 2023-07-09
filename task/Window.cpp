#include "Window.h"

Window::Window(unsigned width, unsigned height) : width(width), height(height)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwWindow = glfwCreateWindow(width, height, "Window", nullptr, nullptr);
    glfwMakeContextCurrent(glfwWindow);

    glfwSetKeyCallback(glfwWindow, onKey);

    glewExperimental = GL_TRUE;

    glewInit();

    int bufWidth, bufHeight;
    glfwGetFramebufferSize(glfwWindow, &bufWidth, &bufHeight);
    glViewport(0, 0, bufWidth, bufHeight);
}

Window::~Window()
{
    glfwTerminate();
}

void Window::Open()
{
    Triangle triangle;
    triangle.setColor(Color("#ff0000"));
    Square square;
    square.setColor(Color("#00ff00"));
    Circle circle;
    circle.setColor(Color("#0000ff"));

    Primitive* primitive = &triangle;

    while (!glfwWindowShouldClose(glfwWindow))
    {
        glfwPollEvents();

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        primitive->Draw();

        glfwSwapBuffers(glfwWindow);
    }
}

void Window::onKey(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
