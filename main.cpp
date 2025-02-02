#include <platforms/platforms.hpp>
#include "imgui.h"

using namespace ntt;

int main(void)
{
    InitWindow("NTT Visualizer Language");

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

        static b8 show_demo_window = true;
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