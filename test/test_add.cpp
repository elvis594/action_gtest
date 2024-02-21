#include "gtest/gtest.h"

// 假设add函数定义在add.h中
#include "add.h" 

// 定义测试用例
TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(3, add(1, 2));
}

TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(-3, add(-1, -2));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}