#include <iostream>
#include "deque.h"

#pragma once

const int HASH_ARRAY_SIZE = 11;
const int HASH_LIST_LIMIT = 3;

class Hash {
private:
  int   currentSize;
  Deque **table;

  int   createHash(int);
  int   getNextPrime(int);
  bool  isPrime(int);
  bool  tableIsFull(int);
  void  rearrange();
  void  moveEntries(Deque*, int);

public:
  Hash();
  ~Hash();

  Node    *get(int);
  bool    add(Flight);
  bool    exists(int);
  Flight  remove(Node*);
};

