#pragma once
#include <datatypes/color.hpp>

namespace ntt
{
    /**
     * Display a string into the the terminal/command prompt. This function is based
     *      on the operating system that the application is running on.
     * After the message is displayed, the cursor will be moved to the next line (default) and
     *      the color of the command prompt/terminal will be reset to the default color (WHITE).
     *
     * @param msg The message to be displayed.
     * @param color The color of the text. The default color is white.
     * @param newLine If true, the cursor will be moved to the next line
     *      after the message is displayed. The default value is true.
     *
     * @note This function is platform dependent.
     *
     * @example
     *     Print("Hello, World!", DefaultColor::GREEN);
     */
    void Print(const char *msg, DefaultColor color = DefaultColor::WHITE, bool newLine = true);
}