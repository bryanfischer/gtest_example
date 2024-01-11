#include "LinkedList.h"

#include <gtest/gtest.h>

TEST(MathTest, TwoPlusTwoEqualsFour) {
    EXPECT_EQ(2 + 2, 4);
}

TEST(LinkedList, CreateList) {
    new LinkedList();
    ASSERT_TRUE(true);
}

TEST(LinkedList, Size0Test) {
    LinkedList list;
    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedList, Size1Test) {
    LinkedList list;
    list.push_back(2);
    EXPECT_EQ(list.size(), 1);
}

TEST(LinkedList, Size2Test) {
    LinkedList list;
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.size(), 2);
}

TEST(LinkedList, Size20Test) {
    LinkedList list;
    int expectedSize = 20;
    for( int i = 0; i < expectedSize; i++ ) {
        list.push_back(i);
    }
    EXPECT_EQ(list.size(), expectedSize);
}

TEST(LinkedList, pop_front_null_list) {
    LinkedList list;
    list.pop_front();
    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedList, pop_front_1size_list) {
    LinkedList list;
    list.push_front(2); // Add single list node
    list.pop_front();
    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedList, pop_front_3size_list) {
    LinkedList list;
    list.push_front(2); // Add single list node
    list.push_front(4); // Add single list node
    list.push_front(8); // Add single list node
    list.pop_front();
    list.pop_front();
    EXPECT_EQ(list.size(), 1);
}

TEST(LinkedList, removeFirstOnEmptyList) {
    LinkedList list;
    list.remove(5);
    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedList, removeFirstOn1Size_NotFound) {
    LinkedList list;
    list.push_front(8);
    list.remove(5);
    EXPECT_EQ(list.size(), 1);
}

TEST(LinkedList, removeFirstOn1Size_Found) {
    LinkedList list;
    list.push_front(8);
    list.remove(8);
    EXPECT_EQ(list.size(), 0);
}





int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
