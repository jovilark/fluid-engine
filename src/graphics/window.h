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

    private:
        void draw();
        void processInput();
        void initialize();
        GLFWwindow *create(const char *title, int width, int height);
        void loadFunctionPointers();
        unsigned int buildVertexShader();
        unsigned int buildFragmentShader();
        unsigned int buildShaderProgram(unsigned int vertexShader,
                                        unsigned int fragmentShader);

        GLFWwindow *_window;
        int _width;
        int _height;
    };
}