#include "window.h"
#include <iostream>

namespace Graphics
{
    void frameBufferSizeCallback(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    Window::Window(const char *title, int width, int height)
        : _width(width),
          _height(height)
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE,
                       GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        _window = glfwCreateWindow(_width,
                                   _height,
                                   title,
                                   nullptr,
                                   nullptr);

        if (_window == nullptr)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }

        glfwMakeContextCurrent(_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }

        glViewport(0, 0, width, height);

        glfwSetFramebufferSizeCallback(_window, frameBufferSizeCallback);
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    void Window::render()
    {
        while (!glfwWindowShouldClose(_window))
        {
            processInput();
            draw();
            glfwSwapBuffers(_window);
            glfwPollEvents();
        }
    }

    void Window::processInput()
    {
        if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(_window, true);
        }
    }

    void Window::draw()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}