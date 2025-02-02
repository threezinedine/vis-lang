#include <platforms/platforms.hpp>

using namespace ntt;

int main(void)
{
    InitWindow("NTT Visualizer Language");

    while (!WindowShouldClose())
    {
        PollEvents();
    }

    CloseWindow();

    return 0;
}