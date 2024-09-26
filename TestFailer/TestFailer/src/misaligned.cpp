#include <iostream>
#include "../include/misaligned.h"

namespace misaligned
{
    constexpr auto MAX_NUMBER_OF_COLORS = 5;;
    int getZeroBasedColorCombinationIndex(int majorColorIndex, int minorColorIndex)
    {
        return majorColorIndex * 5 + minorColorIndex;
    }
    std::map<int, std::pair<std::string, std::string>> computeColorMap() {
        const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
        const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
        std::map<int, std::pair<std::string, std::string>> colorCombination;
        int majorColorIndex = 0, minorColorIndex = 0;
        for (majorColorIndex = 0; majorColorIndex < MAX_NUMBER_OF_COLORS; majorColorIndex++) {
            for (minorColorIndex = 0; minorColorIndex < MAX_NUMBER_OF_COLORS; minorColorIndex++) 
            {
                colorCombination[getZeroBasedColorCombinationIndex(majorColorIndex, minorColorIndex)] = { majorColor[majorColorIndex], minorColor[minorColorIndex] };
            }
        }
        return colorCombination;
    }
}
