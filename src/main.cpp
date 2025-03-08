#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include <engine/openglApi.h>
#include <engine/window.h>
#include <engine/input.h>

using Engine::Window;

int main()
{
#ifdef RELEASE
    spdlog::set_level(spdlog::level::off);
#endif

    if (!Engine::initGLFW())
    {
        return 1;
    }

    Window window = Window(800, 800, "Opengl Window", Engine::Color{91, 168, 240});
    if (!window.initWindow())
    {
        return 1;
    }

    if (!Engine::initGlad())
    {
        return 1;
    }

    window.setCallbacks();

    while (!glfwWindowShouldClose(window.getWindow()))
    {
        window.windowUpdate();
        Engine::getBaseInput(window.getWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}