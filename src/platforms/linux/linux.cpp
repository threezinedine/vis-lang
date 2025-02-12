#include <iostream>
#include <string>

#include <platforms/platforms.hpp>

namespace ntt
{
    void Print(const String &msg, DefaultColor color, bool newLine)
    {
        std::string colorCode;

        switch (color)
        {
        case DefaultColor::WHITE:
            colorCode = "0";
            break;
        case DefaultColor::BLACK:
            colorCode = "30";
            break;
        case DefaultColor::YELLOW:
            colorCode = "33";
            break;
        case DefaultColor::RED:
            colorCode = "31";
            break;
        case DefaultColor::GREEN:
            colorCode = "32";
            break;
        case DefaultColor::BLUE:
            colorCode = "34";
            break;
        case DefaultColor::ORANGE:
            colorCode = "33";
            break;
        case DefaultColor::PURPLE:
            colorCode = "35";
            break;
        case DefaultColor::PINK:
            colorCode = "35";
            break;
        case DefaultColor::BROWN:
            colorCode = "33";
            break;
        case DefaultColor::GREY:
            colorCode = "37";
            break;
        case DefaultColor::CYAN:
            colorCode = "36";
            break;
        case DefaultColor::MAGENTA:
            colorCode = "35";
            break;
        case DefaultColor::LIME:
            colorCode = "32";
            break;
        case DefaultColor::TEAL:
            colorCode = "36";
            break;
        default:
            colorCode = "0"; // Default color is white
            break;
        }

        std::cout << "\033[" << colorCode << "m" << msg << "\033[0m";
        if (newLine)
        {
            std::cout << std::endl;
        }

        return;
    }
} // namespace ntt
