#pragma once

#include <iostream>
#include <unordered_map>
#include "node.h"

using namespace std;

template <typename K, typename V>
class LRUCache {
private:
  Node<K, V>* head;
  Node<K, V>* tail;
  size_t capacity;
  unordered_map<K, Node<K, V>*> map;

  // Remove node from double linked list
  // Complexity: O(1)
  void remove(Node<K, V>* node) {
    if(node->prev != nullptr or node->next != nullptr)
      return;
    if(this->capacity == 1) {
      this->head = nullptr;
      this->tail = nullptr;
      return;
    }

    if(node == this->head)
      this->head = node->next;
    if(node == this->tail)
      this->tail = node->prev;

    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  // Set node to head of double linked list
  // Complexity: O(1)
  void set_head(Node<K, V>* node) {
    if(this->head == nullptr and this->tail == nullptr) {
      this->head = node;
      this->tail = node;
      this->head->next = this->head->prev = this->tail;
      this->tail->prev = this->tail->next = this->head;

      return;
    }

    if(this->head == node)
      return;

    if(this->tail == node)
      this->tail = node->prev;

    node->next = this->head;
    this->head->prev = node;
    this->head = node;
    this->tail->next = node;
  }

public:
  LRUCache(size_t capacity) {
    this->head = nullptr;
    this->tail = nullptr;
    this->capacity = capacity;
    this->map = unordered_map<K, Node<K, V>*>();
  }

  // Get value from cache
  // Complexity: O(1)
  Node<K, V>* get(const K& key) {
    if(this->map.find(key) == this->map.end())
      return nullptr;

    Node<K, V>* node = this->map[key];
    this->remove(node);
    this->set_head(node);

    return node;
  }

  // Get head value from cache
  // Complexity: O(1)
  Node<K, V>* get_head() {
    if(this->head == nullptr)
      return nullptr;

    return this->head;
  }

  // Get tail value from cache
  // Complexity: O(1)
  Node<K, V>* get_tail() {
    if(this->tail == nullptr)
      return nullptr;

    return this->tail;
  }

  // Get size of cache
  // Complexity: O(1)
  size_t get_size() {
    return this->map.size();
  }

  // Get capacity of cache
  // Complexity: O(1)
  size_t get_capacity() {
    return this->capacity;
  }

  // Set value to cache
  // Complexity: O(1)
  void put(const K key, const V value) {
    // If key exists, update value and move to head
    if(this->map.find(key) != this->map.end()) {
      Node<K, V>* node = this->map[key];
      node->value = value;
      this->remove(node);
      this->set_head(node);
    }

    // If key doesn't exist, create a new node
    // Verify capacity
    if(this->map.size() == this->capacity) {
      Node<K, V>* node = this->tail;
      this->remove(node);
      this->map.erase(node->key);
      delete node;
    }

    Node<K, V>* new_node = new Node<V, V>(key, value);
    this->set_head(new_node);
    this->map[key] = new_node;
  }

  // Clear double linked list nodes
  // Complexity: O(1)
  ~LRUCache() {
    if(this->head == nullptr and this->tail == nullptr)
      return;

    Node<K, V>* curr = this->head;
    this->tail->next = nullptr;

    do {
      Node<K, V>* next = curr->next;
      delete curr;
      curr = next;
    } while(curr != nullptr);
  }
};
