#include "hash.h"

using namespace std;

Hash::Hash(){
  for (int i = 0; i < HASH_ARRAY_SIZE; i++)
    this->table[i] = NULL;
}

Hash::~Hash(){
  for (int i = 0; i < HASH_ARRAY_SIZE; i++){
    if (this->table[i] != NULL)
      delete(this->table[i]);
  }
}

Node *Hash::get(int flightId){
  int hash = this->createHash(flightId);

  Deque *list = this->table[hash];
  if (list == NULL)
    return NULL;

  Node *current = list->getHead();

  while (current != NULL){
    if (current->flight.id == flightId)
      break;

    current = current->next;
  }

  return current;
}

bool Hash::add(Flight flight){
  int hash = this->createHash(flight.id);

  if (this->table[hash] == NULL)
    this->table[hash] = new Deque();

  this->table[hash]->pushFront(flight);

  return true;
}

bool Hash::exists(int flightId){
  return this->get(flightId) != NULL;
}

Flight Hash::remove(Node *node){
  int hash = this->createHash(node->flight.id);

  Flight flight = this->table[hash]->remove(node);

  if (this->table[hash]->isEmpty())
    delete(this->table[hash]);

  return flight;
}

int Hash::createHash(int key){
  return key % HASH_ARRAY_SIZE;
}

