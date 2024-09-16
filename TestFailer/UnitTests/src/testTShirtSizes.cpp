#include <gtest/gtest.h>
#include "../../TestFailer/include/tshirts.h"

namespace TestTShirtSizes
{
    TEST(TShirtSizes, Test_TShirt_SmallSize)
    {
        EXPECT_EQ(tShirts::size(37), 'S');
        EXPECT_EQ(tShirts::size(38), 'S');
    }

    TEST(TShirtSizes, Test_TShirt_MediumSize)
    {

        EXPECT_EQ(tShirts::size(40), 'M');
        EXPECT_EQ(tShirts::size(42), 'M');
    }

    TEST(TShirtSizes, Test_TShirt_LargeSize)
    {

        EXPECT_EQ(tShirts::size(43), 'L');
    }
}