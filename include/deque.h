#include <iostream>
#include <stdlib.h>
#include "flight.h"
#include "entry.h"

#pragma once

//TODO: use templates
class Deque {
private:
  Entry *head, *tail;

  bool insertFirstElement(Flight);

public:
  Deque();
  ~Deque();

  Entry   *getHead();
  Entry   *getTail();

  bool    isEmpty();
  int     getSize();

  bool    pushFront(Flight);
  bool    pushBack(Flight);

  bool    insertBefore(Entry*, Flight);
  bool    insertAfter(Entry*, Flight);

  Flight  popFront();
  Flight  popBack();
  Flight  remove(Entry*&);

  void    show();
  void    showReverse();
  void    clear();
};

