#pragma once

template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node<K, V>* next;
  Node<K, V>* prev;
  
  Node(K key, V value) {
    this->key = key;
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
  }

  Node(K key, V value, Node<K, V>* next, Node<K, V>* prev) {
    this->key = key;
    this->value = value;
    this->next = next;
    this->prev = prev;
  }

  ~Node() {
    this->next = nullptr;
    this->prev = nullptr;

    delete this->next;
    delete this->prev;
  }
};
