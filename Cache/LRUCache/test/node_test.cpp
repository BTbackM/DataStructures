#include <gtest/gtest.h>

#include "node.h"

TEST(NodeTest, Constructor) {
  Node<int, int> node(1, 2);
  EXPECT_EQ(node.key, 1);
  EXPECT_EQ(node.value, 2);
  EXPECT_EQ(node.prev, nullptr);
  EXPECT_EQ(node.next, nullptr);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
