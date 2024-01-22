#include <gtest/gtest.h>

#include "node.h"

TEST(NodeTest, Constructor) {
  Node<int, int> node(1, 2);

  EXPECT_EQ(node.key, 1);
  EXPECT_EQ(node.value, 2);
  EXPECT_EQ(node.prev, nullptr);
  EXPECT_EQ(node.next, nullptr);
}

TEST(NodeTest, NextPrev) {
  Node<int, int>* next = new Node<int, int>(1, 2);
  Node<int, int>* prev = new Node<int, int>(3, 4);
  prev->next = next;
  next->prev = prev;

  EXPECT_EQ(prev->next, next);
  EXPECT_EQ(next->prev, prev);
}

TEST(NodeTest, Destructor) {
  Node<int, int>* next = new Node<int, int>(1, 2);
  Node<int, int>* prev = new Node<int, int>(3, 4);
  prev->next = next;
  next->prev = prev;

  delete next;
  delete prev;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
