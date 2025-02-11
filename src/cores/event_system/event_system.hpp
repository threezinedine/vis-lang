#pragma once

/**
 * The event system is the base system of the project which will record all the events
 *      occurred ontop of it (the higher level of the systems). This event will both be
 *      used for debugging, logging, profiling, timing system, etc.
 */

namespace ntt
{
    void InitEventSystem();

    void ShutdownEventSystem();
} // namespace ntt
