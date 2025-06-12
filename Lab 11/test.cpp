#include "pch.h"
#include "Sorter.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestSorter, Testul1) {
    Sorter<int> sorter;
    vector<int> data = { 5, 2, 4, 1, 3 };

    sorter.Sort(data);
    EXPECT_TRUE(sorter.isSortedAscending(data));
}
TEST(TestSorter, Testul2) 
{
    Sorter<int> sorter;
    vector<int> data = { 1, 2, 3, 4, 5 };

    sorter.Sort(data);
    EXPECT_TRUE(sorter.isSortedAscending(data));
}
TEST(TestSorter, Testul3)
{
    Sorter<int> sorter;
    vector<int> data = { 42 };

    sorter.Sort(data);
    EXPECT_TRUE(sorter.isSortedAscending(data));
}
TEST(TestSorter, Testul4)
{
    Sorter<int> sorter;
    vector<int> data = { };

    sorter.Sort(data);
    EXPECT_TRUE(sorter.isSortedAscending(data));
}
