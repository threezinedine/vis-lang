#include <iostream>
#include <Windows.h>

#include <platforms/platforms.hpp>

namespace ntt
{
    void Print(const char *msg, DefaultColor color, bool newLine)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        switch (color)
        {
        case DefaultColor::WHITE:
            SetConsoleTextAttribute(hConsole, 15);
            break;
        case DefaultColor::BLACK:
            SetConsoleTextAttribute(hConsole, 0);
            break;
        case DefaultColor::YELLOW:
            SetConsoleTextAttribute(hConsole, 14);
            break;
        case DefaultColor::RED:
            SetConsoleTextAttribute(hConsole, 12);
            break;
        case DefaultColor::GREEN:
            SetConsoleTextAttribute(hConsole, 10);
            break;
        case DefaultColor::BLUE:
            SetConsoleTextAttribute(hConsole, 9);
            break;
        case DefaultColor::ORANGE:
            SetConsoleTextAttribute(hConsole, 6);
            break;
        case DefaultColor::PURPLE:
            SetConsoleTextAttribute(hConsole, 5);
            break;
        case DefaultColor::PINK:
            SetConsoleTextAttribute(hConsole, 13);
            break;
        case DefaultColor::BROWN:
            SetConsoleTextAttribute(hConsole, 3);
            break;
        case DefaultColor::GREY:
            SetConsoleTextAttribute(hConsole, 8);
            break;
        case DefaultColor::CYAN:
            SetConsoleTextAttribute(hConsole, 11);
            break;
        case DefaultColor::MAGENTA:
            SetConsoleTextAttribute(hConsole, 13);
            break;
        case DefaultColor::LIME:
            SetConsoleTextAttribute(hConsole, 10);
            break;
        case DefaultColor::TEAL:
            SetConsoleTextAttribute(hConsole, 11);
            break;
        default:
            SetConsoleTextAttribute(hConsole, 15); // Default color is white
            break;
        }

        std::cout << msg;

        if (newLine)
        {
            std::cout << std::endl;
        }

        // Reset the color to white
        SetConsoleTextAttribute(hConsole, 15);

        return;
    }
} // namespace ntt
