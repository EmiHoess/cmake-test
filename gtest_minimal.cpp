#include <gtest/gtest.h>

int add(int, int);

TEST(AdditionTest, Basic) {
    EXPECT_EQ(add(2, 3), 5);
}
