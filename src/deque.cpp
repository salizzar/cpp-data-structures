#include "deque.h"

Deque::Deque(){
  this->head = this->tail = NULL;
}

Deque::~Deque(){
  Node *current = this->head;

  while (current != NULL){
    Node *node = current;

    current = current->next;

    delete(node);
  }
}

Node *Deque::getHead(){ return this->head; }
Node *Deque::getTail(){ return this->tail; }
bool Deque::isEmpty() { return (!this->head || !this->tail); }

bool Deque::pushFront(Flight flight){
  if (this->isEmpty())
    return this->insertFirstElement(flight);

  Node *node = new Node();
  node->flight = flight;

  node->previous = NULL;
  node->next = this->head;

  this->head->previous = node;
  this->head = node;

  return true;
}

bool Deque::pushBack(Flight flight){
  if (this->isEmpty())
    return this->insertFirstElement(flight);

  Node *node = new Node();
  node->flight = flight;

  node->previous = this->tail;
  node->next = NULL;

  this->tail->next = node;
  this->tail = node;

  return true;
}

bool Deque::insertBefore(Node *current, Flight flight){
  if (this->isEmpty())
    return this->insertFirstElement(flight);

  if (current == this->head)
    return this->pushFront(flight);

  Node *node = new Node();
  node->flight = flight;

  node->previous = current->previous;
  node->next = current;

  current->previous->next = node;
  current->previous = node;

  return true;
}

bool Deque::insertAfter(Node *current, Flight flight){
  if (this->isEmpty())
    return this->insertFirstElement(flight);

  if (current == this->tail)
    return this->pushBack(flight);

  Node *node = new Node();
  node->flight = flight;

  node->previous = current;
  node->next = current->next;

  current->next->previous = node;
  current->next = node;

  return true;
}

Flight Deque::popFront(){
  Node *node = this->head;
  Flight flight = node->flight;

  if (node->next != NULL)
    node->next->previous = NULL;

  this->head = node->next;

  delete(node);

  return flight;
}

Flight Deque::popBack(){
  Node *node = this->tail;
  Flight flight = node->flight;

  if (node->previous != NULL)
    node->previous->next = NULL;

  this->tail = node->previous;

  delete(node);

  return flight;
}

Flight Deque::remove(Node *&node){
  if (node == this->head)
    return this->popFront();

  if (node == this->tail)
    return this->popBack();

  Flight flight = node->flight;

  node->previous->next = node->next;
  node->next->previous = node->previous;

  delete(node);

  return flight;
}

void Deque::show(){
  Node *node = this->head;

  while (node != NULL){
    cout << node->flight.id << "\n";
    node = node->next;
  }
}

void Deque::showReverse(){
  Node *node = this->tail;

  while (node != NULL){
    cout << node->flight.id << "\n";
    node = node->previous;
  }
}

bool Deque::insertFirstElement(Flight flight){
  Node *node = new Node();
  node->flight = flight;
  node->previous = node->next = NULL;

  this->head = this->tail = node;

  return true;
}

