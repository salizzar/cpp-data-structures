#include "deque.h"

using namespace std;

Deque::Deque(){
  this->head = this->tail = NULL;
}

Deque::~Deque(){
  this->clear();
}

Entry *Deque::getHead(){ return this->head; }
Entry *Deque::getTail(){ return this->tail; }
bool Deque::isEmpty() { return (!this->head || !this->tail); }

int Deque::getSize() {
  int size = 0;
  Entry *walker = this->head;

  while (walker != NULL){
    size++;
    walker = walker->next;
  }

  return size;
}

bool Deque::pushFront(Flight flight){
  if (this->isEmpty())
    return this->insertFirstElement(flight);

  Entry *entry = new Entry();
  entry->flight = flight;

  entry->previous = NULL;
  entry->next = this->head;

  this->head->previous = entry;
  this->head = entry;

  return true;
}

bool Deque::pushBack(Flight flight){
  if (this->isEmpty())
    return this->insertFirstElement(flight);

  Entry *entry = new Entry();
  entry->flight = flight;

  entry->previous = this->tail;
  entry->next = NULL;

  this->tail->next = entry;
  this->tail = entry;

  return true;
}

bool Deque::insertBefore(Entry *current, Flight flight){
  if (this->isEmpty())
    return this->insertFirstElement(flight);

  if (current == this->head)
    return this->pushFront(flight);

  Entry *entry = new Entry();
  entry->flight = flight;

  entry->previous = current->previous;
  entry->next = current;

  current->previous->next = entry;
  current->previous = entry;

  return true;
}

bool Deque::insertAfter(Entry *current, Flight flight){
  if (this->isEmpty())
    return this->insertFirstElement(flight);

  if (current == this->tail)
    return this->pushBack(flight);

  Entry *entry = new Entry();
  entry->flight = flight;

  entry->previous = current;
  entry->next = current->next;

  current->next->previous = entry;
  current->next = entry;

  return true;
}

Flight Deque::popFront(){
  Entry *entry = this->head;
  Flight flight = entry->flight;

  if (entry->next != NULL)
    entry->next->previous = NULL;

  this->head = entry->next;

  delete(entry);

  return flight;
}

Flight Deque::popBack(){
  Entry *entry = this->tail;
  Flight flight = entry->flight;

  if (entry->previous != NULL)
    entry->previous->next = NULL;

  this->tail = entry->previous;

  delete(entry);

  return flight;
}

Flight Deque::remove(Entry *&entry){
  if (entry == this->head)
    return this->popFront();

  if (entry == this->tail)
    return this->popBack();

  Flight flight = entry->flight;

  entry->previous->next = entry->next;
  entry->next->previous = entry->previous;

  delete(entry);

  return flight;
}

void Deque::show(){
  Entry *entry = this->head;

  while (entry != NULL){
    cout << "\n" << entry->flight.id;
    entry = entry->next;
  }
}

void Deque::showReverse(){
  Entry *entry = this->tail;

  while (entry != NULL){
    cout << "\n" << entry->flight.id;
    entry = entry->previous;
  }
}

bool Deque::insertFirstElement(Flight flight){
  Entry *entry = new Entry();
  entry->flight = flight;
  entry->previous = entry->next = NULL;

  this->head = this->tail = entry;

  return true;
}

void Deque::clear(){
  Entry *walker, *current;
  walker = this->head;

  while (walker != NULL){
    current = walker;
    walker = walker->next;

    delete(current);
  }

  this->head = this->tail = NULL;
}

