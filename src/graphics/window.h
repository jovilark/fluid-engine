#pragma once
#include <memory>

#include <glad.h>
#include <glfw3.h>

namespace Graphics
{
    void frameBufferSizeCallback(GLFWwindow *window, int width, int height);

    class Window
    {
    public:
        Window(const char *title, int width, int height);
        ~Window();
        void render();
        void draw();
        void processInput();

    private:
        GLFWwindow *_window;
        int _width;
        int _height;
    };
}