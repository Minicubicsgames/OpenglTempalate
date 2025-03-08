#include <engine/window.h>

Engine::Window::Window(uint32_t width, uint32_t height, const char* title, Engine::Color windowColor)
    : width(width), height(height), title(title), window(nullptr), windowColor(windowColor)
{
}

Engine::Window::~Window()
{
    glfwDestroyWindow(window);
    spdlog::info("Window \"{0}\" destroyed", getTitle());
}

int Engine::Window::initWindow()
{
    window = glfwCreateWindow(width, height, "Opengl Window", NULL, NULL);
    if (!window)
    {
        spdlog::critical("Failed to create GLFW window for \"{0}\"!", glfwGetWindowTitle(window));
        glfwTerminate();
        return GL_FALSE;
    }
    glfwMakeContextCurrent(window);
    spdlog::info("\"{0}\" successfully initialized with size: {1}:{2}", getTitle(), getWidth(), getWidth());
    return GL_TRUE;
}

void Engine::Window::setCallbacks()
{
    spdlog::info("Set \"{0}\" window callbacks successfully", getTitle());
    glViewport(0, 0, getWidth(), getHeight());
    glfwSetFramebufferSizeCallback(getWindow(), framebuffer_size_callback);
}

void Engine::Window::windowUpdate()
{
    glClearColor(map(windowColor.r, 0, 255, 0.0f, 1.0f), map(windowColor.g, 0, 255, 0.0f, 1.0f),
                 map(windowColor.b, 0, 255, 0.0f, 1.0f), 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}

void Engine::Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}