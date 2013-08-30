#include <iostream>
#include <stdlib.h>
#include "flight.h"
#include "node.h"

#pragma once

using namespace std;

//TODO: use templates
class Deque {
private:
  Node *head, *tail;

  bool insertFirstElement(Flight);

public:
  Deque();
  ~Deque();

  Node *getHead();
  Node *getTail();

  bool isEmpty();

  bool pushFront(Flight);
  bool pushBack(Flight);

  bool insertBefore(Node*, Flight);
  bool insertAfter(Node*, Flight);

  Flight popFront();
  Flight popBack();
  Flight remove(Node*);

  void show();
  void showReverse();
};

