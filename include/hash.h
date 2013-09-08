#include <iostream>
#include "deque.h"

#pragma once

const int HASH_ARRAY_SIZE = 100;

class Hash {
private:
  Deque *table[HASH_ARRAY_SIZE];

  int createHash(int);

public:
  Hash();
  ~Hash();

  Node    *get(int);
  bool    add(Flight);
  bool    exists(int);
  Flight  remove(Node*);
};

