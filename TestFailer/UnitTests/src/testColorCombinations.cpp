#include <gtest/gtest.h>
#include "../../TestFailer/include/misaligned.h"
#include "../../TestFailer/include/weatherReportStub.h"

namespace TestColorCombinations
{
    TEST(MisalignedColors, Test_MisalignedColors_TotalCount)
    {
        constexpr auto total_count_of_colors = 25;
        EXPECT_EQ(misaligned::computeColorMap().size(), total_count_of_colors);
    }

    TEST(MisalignedColors, Test_MisalignedColors_SpecificColorCombination)
    {
        auto colorMap = misaligned::computeColorMap();
        constexpr auto majorColorIndex = 2;
        constexpr auto minorColorIndex = 3;
        const auto key = misaligned::getZeroBasedColorCombinationIndex(majorColorIndex, minorColorIndex); // Compute key for i = 2, j = 3
        EXPECT_NE(colorMap.find(key), colorMap.end()); // Check if the key exists
        EXPECT_EQ(colorMap[key].first, "Black"); // Major color for i = 2 should be "Black"
        EXPECT_EQ(colorMap[key].second, "Brown"); // Minor color for j = 3 should be "Brown"
    }

    TEST(MisalignedColors, Test_MisalignedColors_AllColorCombinations)
    {
        auto colorMap = misaligned::computeColorMap();
        const std::string majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
        const std::string minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

        for (int majorColorIndex = 0; majorColorIndex < 5; majorColorIndex++) {
            for (int minorColorIndex = 0; minorColorIndex < 5; minorColorIndex++) {
                auto key = misaligned::getZeroBasedColorCombinationIndex(majorColorIndex, minorColorIndex);
                EXPECT_NE(colorMap.find(key), colorMap.end()); // Key should exist
                EXPECT_EQ(colorMap[key].first, majorColor[majorColorIndex]); // Major color should match
                EXPECT_EQ(colorMap[key].second, minorColor[minorColorIndex]); // Minor color should match
            }
        }
    }
}