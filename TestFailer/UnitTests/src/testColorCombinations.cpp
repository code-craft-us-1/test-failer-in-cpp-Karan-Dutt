#include <gtest/gtest.h>
#include "../../TestFailer/include/misaligned.h"
#include "../../TestFailer/include/weatherReportStub.h"

namespace TestColorCombinations
{
    TEST(MisalignedColors, Test_MisalignedColors_TotalCount)
    {

        EXPECT_EQ(misaligned::computeColorMap().size(), 25);
    }

    TEST(MisalignedColors, Test_MisalignedColors_SpecificColorCombination)
    {
        auto colorMap = misaligned::computeColorMap();
        const auto key = misaligned::computeColorCombination(2, 3); // Compute key for i = 2, j = 3
        EXPECT_NE(colorMap.find(key), colorMap.end()); // Check if the key exists
        EXPECT_EQ(colorMap[key].first, "Black"); // Major color for i = 2 should be "Black"
        EXPECT_EQ(colorMap[key].second, "Brown"); // Minor color for j = 3 should be "Brown"
    }

    TEST(MisalignedColors, Test_MisalignedColors_AllColorCombinations)
    {
        auto colorMap = misaligned::computeColorMap();
        const std::string majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
        const std::string minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                auto key = misaligned::computeColorCombination(i, j);
                EXPECT_NE(colorMap.find(key), colorMap.end()); // Key should exist
                EXPECT_EQ(colorMap[key].first, majorColor[i]); // Major color should match
                EXPECT_EQ(colorMap[key].second, minorColor[j]); // Minor color should match
            }
        }
    }
}