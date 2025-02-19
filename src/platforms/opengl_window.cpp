#include "window.hpp"
#include "console_utils.hpp"
#include <constants.hpp>
#include <datatypes/common.hpp>

#include <cstdlib>

#ifdef USE_OPENGL
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

namespace ntt
{
    namespace
    {
        GLFWwindow *s_window = nullptr;
        ImVec4 s_ClearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

        void GLFW_Error_Callback(int error, const char *description)
        {
            // TODO: Modify it when the logging system is implemented.
            Print(description, DefaultColor::RED);
        }
    } // namespace anonymous

    void InitWindow(const char *title)
    {
        glfwSetErrorCallback(GLFW_Error_Callback);

        if (!glfwInit())
        {
            // TODO: Modify it when the logging system is implemented.
            Print("Failed to initialize GLFW.", DefaultColor::RED);
            std::exit(NTT_ERROR_FAILED_TO_INIT_WINDOW);
        }

        const char *glsl_version = "#version 130";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only

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
        I32 width, height, channels;

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
        glfwSwapInterval(1); // Enable vsync

        auto err = glewInit();

        if (err != GLEW_OK)
        {
            // TODO: Modify it when the logging system is implemented.
            Print((const char *)glewGetErrorString(err), DefaultColor::RED);
            std::exit(NTT_ERROR_FAILED_TO_INIT_WINDOW);
        }

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // Enable Multi-Viewport / Platform Windows
        ImGui::StyleColorsDark();

        ImGuiStyle &style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        ImGui_ImplGlfw_InitForOpenGL(s_window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);
    }

    void StartFrame()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
    }

    void EndFrame()
    {
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(s_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        glfwSwapBuffers(s_window);
    }

    B8 WindowShouldClose()
    {
        return glfwWindowShouldClose(s_window);
    }

    void PollEvents()
    {
        glfwPollEvents();
    }

    void CloseWindow()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(s_window);
        glfwTerminate();
    }
} // namespace ntt

#else // TODO: If a new graphic API is added, this else if block should be deleted.
#error "Only OpenGL is supported for now."
#endif
