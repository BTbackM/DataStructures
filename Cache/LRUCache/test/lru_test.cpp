#include <gtest/gtest.h>

#include "lru_cache.h"

TEST(LRUCacheTest, Constructor) {
  LRUCache<int, int> cache(1);

  EXPECT_EQ(cache.get_head(), nullptr);
  EXPECT_EQ(cache.get_tail(), nullptr);
  EXPECT_EQ(cache.get_capacity(), 1);
  EXPECT_EQ(cache.get_size(), 0);
}

TEST(LRUCacheTest, SetHead) {
  LRUCache<int, int> cache(5);
  cache.put(1, 1);

  Node<int, int>* head, *tail;
  head = cache.get_head();
  tail = cache.get_tail();

  EXPECT_EQ(head, tail);
  EXPECT_EQ(head->next, tail);
  EXPECT_EQ(tail->next, head);
  EXPECT_EQ(cache.get_size(), 1);
}

TEST(LRUCacheTest, SetTail) {
  LRUCache<int, int> cache(5);
  cache.put(1, 1);
  cache.put(2, 2);

  EXPECT_EQ(cache.get_head()->key, 2);
  EXPECT_EQ(cache.get_tail()->key, 1);
  EXPECT_EQ(cache.get_size(), 2);
}

TEST(LRUCacheTest, PutGet) {
  LRUCache<int, int> cache(5);
  cache.put(1, 1);
  cache.put(2, 2);
  cache.put(3, 3);
  cache.put(4, 4);
  cache.put(5, 5);

  EXPECT_EQ(cache.get(1)->key, 1);
  EXPECT_EQ(cache.get(2)->key, 2);
  EXPECT_EQ(cache.get(3)->key, 3);
  EXPECT_EQ(cache.get(4)->key, 4);
  EXPECT_EQ(cache.get(5)->key, 5);
  EXPECT_EQ(cache.get_size(), 5);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
