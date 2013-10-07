#include "tree.h"

Tree::Tree(){
  this->root = NULL;
}

Tree::~Tree(){
  this->clear();
}

bool Tree::add(Flight flight){
  Node *node = new Node();
  node->flight = flight;
  node->left = node->right = NULL;

  if (this->isEmpty()){
    this->root = node;
  } else {
    this->walkInsert(node);
  }

  return true;
}

void Tree::walkInsert(Node *node){
  Node *father, *current;
  int currentId;

  father = this->root;

  while (true){
    current = father;
    currentId = current->flight.id;

    if (node->flight.id < currentId){
      current = father->left;

      if (current == NULL){
        father->left = node;
        return;
      }
    } else {
      current = father->right;

      if (current == NULL){
        father->right = node;
        return;
      }
    }
  }
}

bool Tree::exists(int flightId){
  Node *node = this->get(flightId);
  return node != NULL;
}

bool Tree::isEmpty(){
  return (this->root == NULL);
}

Node* Tree::get(int flightId){
  if (this->isEmpty())
    return NULL;

  Node *current = this->root;

  while (current->flight.id != flightId){
    if (flightId < current->flight.id)
      current = current->left;
    else
      current = current->right;

    if (current == NULL)
      return NULL;
  }

  return current;
}

Flight Tree::remove(Node *node){
}

int Tree::getSize(){
  return 0;
}

void Tree::prefix(){
}

void Tree::infix(){
}

void Tree::postfix(){
}

void Tree::clear(){
  this->recursiveDestroy(this->root);
}

void Tree::recursiveDestroy(Node *node){
  if (node == NULL)
    return;

  this->recursiveDestroy(node->left);
  this->recursiveDestroy(node->right);

  delete(node);
}

