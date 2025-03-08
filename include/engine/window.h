#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include <engine/gameMath.h>

namespace Engine
{
    class Window
    {
    public:
        Window(uint32_t width, uint32_t height, const char *title, Engine::Color windowColor);
        ~Window();

        int initWindow();
        void setCallbacks();

        virtual void windowUpdate();
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

        uint32_t getWidth() { return width; }
        uint32_t getHeight() { return height; }
        const char *getTitle() { return title; }
        GLFWwindow *getWindow() { return window; }

        Engine::Color windowColor = Engine::Color{255, 255, 255};

    private:
        uint32_t width, height;
        const char *title;
        GLFWwindow *window;
    };
}