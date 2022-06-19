#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

int main() {
    GLFWwindow* window;
    if(!glfwInit())
        return -1;

    window = glfwCreateWindow(600, 480 , "GL", NULL,NULL);
    if(!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    std::cout << glGetString(GL_VERSION) << std::endl;

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}