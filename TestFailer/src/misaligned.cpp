#include <iostream>
#include "../include/misaligned.h"

namespace misaligned
{
    int computeColorCombination(int i, int j)
    {
        return i * 5 + j;
    }
    std::map<int, std::pair<std::string, std::string>> computeColorMap() {
        const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
        const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
        std::map<int, std::pair<std::string, std::string>> colorCombination;
        int i = 0, j = 0;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) 
            {
                colorCombination[computeColorCombination(i, j)] = { majorColor[i], minorColor[j] };
            }
        }
        return colorCombination;
    }
}
