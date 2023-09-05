#include "config.hpp"

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
}

int main(int, char**){
    std::cout << "Hello, from Chess Engine!\n";

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // OpenGL version 4.1
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for macOS

    GLFWwindow* window = glfwCreateWindow(800, 800, "Chess Engine", nullptr, nullptr);
    if (window == nullptr) throw std::runtime_error("WINDOW::FAILED_TO_CREATE");
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) throw std::runtime_error("Failed to initialize GLEW library");
    glfwSwapInterval(1); // set frame rate to v-sync
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback); // to handle resizing

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glClearColor(0.2, 0.3, 0.4, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
