#include <iostream>
#include "node.h"

#pragma once

class Tree {
private:
  Node  *root;

  void  walkInsert(Node*);
  void  recursiveDestroy(Node*);

public:
  Tree();
  ~Tree();

  bool    add(Flight);
  bool    exists(int);
  bool    isEmpty();

  Node    *get(int);
  Flight  remove(Node*);
  int     getSize();

  void    prefix();
  void    infix();
  void    postfix();

  void    clear();
};

