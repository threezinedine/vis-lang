#include <platforms/platforms.hpp>
#include <utilities/utilities.hpp>
#include <modules/modules.hpp>
#include <datatypes/datatypes.hpp>
#include "imgui.h"

using namespace ntt;

int main(void)
{
    LogInit({
        static_cast<Ref<LogHandler>>(
            CreateRef<ntt::ConsoleHandler>(
                NTT_LOG_LEVEL_DEBUG,
                "[@level] - @time - @file:@line - @message")),
    });

    InitWindow("NTT Visualizer Language");
    NTT_LOG_INFO("Window initialized");

    while (!WindowShouldClose())
    {
        PollEvents();

        // ------------- Put the logic code below -------------

        // ------------- Put the logic code above -------------

        StartFrame();
        // ------------- Put the rendering code below -------------
        ImGui::Begin("Hello, world!");
        ImGui::Text("This is some useful text.");
        ImGui::End();

        static B8 show_demo_window = true;
        if (show_demo_window)
        {
            ImGui::ShowDemoWindow(&show_demo_window);
        }

        // ------------- Put the rendering code above -------------

        EndFrame();
    }

    CloseWindow();

    return 0;
}