#include "window.hpp"
#include "console_utils.hpp"
#include <constants.hpp>
#include <datatypes/common.hpp>

#include <cstdlib>

#ifdef USE_OPENGL
#include <GLFW/glfw3.h>
#include <stb_image.h>

namespace ntt
{
    namespace
    {
        GLFWwindow *s_window = nullptr;
    } // namespace anonymous

    void InitWindow(const char *title)
    {
        if (!glfwInit())
        {
            // TODO: Modify it when the logging system is implemented.
            Print("Failed to initialize GLFW.", DefaultColor::RED);
            std::exit(NTT_ERROR_FAILED_TO_INIT_WINDOW);
        }

        // maximize the window
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
        s_window = glfwCreateWindow(800, 600, title, nullptr, nullptr);

        if (!s_window)
        {
            // TODO: Modify it when the logging system is implemented.
            Print("Failed to create a window.", DefaultColor::RED);
            glfwTerminate();
            std::exit(NTT_ERROR_FAILED_TO_INIT_WINDOW);
        }

        GLFWimage icon;
        i32 width, height, channels;

        icon.pixels = stbi_load("assets/images/mini-icon.png", &width, &height, &channels, 4);
        icon.height = height;
        icon.width = width;

        if (icon.pixels)
        {
            glfwSetWindowIcon(s_window, 1, &icon);
            stbi_image_free(icon.pixels);
        }
        else
        {
            // TODO: Modify it when the logging system is implemented.
            Print("Failed to load the icon image.", DefaultColor::YELLOW);
        }

        glfwMakeContextCurrent(s_window);
    }

    b8 WindowShouldClose()
    {
        return glfwWindowShouldClose(s_window);
    }

    void PollEvents()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(s_window);
        glfwPollEvents();
    }

    void CloseWindow()
    {
        glfwDestroyWindow(s_window);
        glfwTerminate();
    }
} // namespace ntt

#else // TODO: If a new graphic API is added, this else if block should be deleted.
#error "Only OpenGL is supported for now."
#endif
