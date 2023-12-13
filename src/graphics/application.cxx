#include <iostream>

#include "application.h"

#include <glad.h>
#include <glfw3.h>

int run()
{
  GLFWwindow *window;

  /* Initialize the library */
  if (!glfwInit())
    std::cout << "Failed to initialize GLFW" << std::endl;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "fluid-engine", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  // glad: load all OpenGL function pointers
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
  }

  std::cout << glGetString(GL_VERSION) << std::endl;

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window))
  {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);
    /* Poll for and process events */
    glfwPollEvents();
  }
}