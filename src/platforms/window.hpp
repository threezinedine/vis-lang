#pragma once
#include <datatypes/common.hpp>

namespace ntt
{
    /**
     * Starting the window with the given parameters. All the needed graphics
     *      resources will be loaded. The window will be windowed and maximized.
     *
     * @param title The title of the window. It cannot be null or empty string.
     *
     * @note This function is OS dependent. It must be called before the application
     *      loop.
     */
    void InitWindow(const char *title);

    /**
     * Checks whether the application should be ended or not (like clicking the quit
     *      button on the window). This function should be used as the condition of
     *      the main loop.
     *
     * @return true if the application should be ended, false otherwise.
     */
    b8 WindowShouldClose();

    /**
     * Used for catching the actions from user inputs (like keyboard, mouse, etc.) or other
     *      signals. This function should be called inside the main loop.
     * This function should only modify the state of the application, not and logic, graphics
     *      logic or anything else are allowed to be done here.
     */
    void PollEvents();

    /**
     * The beginning setup for drawing section of the graphics API. This should must be called
     *      after the PollEvents function (can have some logic between them).
     */
    void StartFrame();

    /**
     * The ending setup for drawing section of the graphics API. This should must be called
     *      after the StartFrame function (can have some logic between them).
     */
    void EndFrame();

    /**
     * Deletes all the windows and frees the resources which were used by the
     *      application.
     *
     * @note This function is OS dependent. It must be called at the end of the
     *      main function.
     */
    void CloseWindow();
} // namespace ntt
