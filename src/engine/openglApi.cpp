#include <engine/openglApi.h>

int Engine::initGLFW()
{
    if (!glfwInit())
    {
        spdlog::critical("Failed to initialize Opengl");
        return GL_FALSE;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef OS_MACOS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    spdlog::info("GLFW is successfully initialized");
    return GL_TRUE;
}

int Engine::initGlad()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        spdlog::critical("Failed to initialize GLAD");
        return GL_FALSE;
    }
    spdlog::info("Glad is successfully initialized");
    return GL_TRUE;
}