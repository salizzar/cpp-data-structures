#include "hash.h"

using namespace std;

Hash::Hash(){
  this->currentSize = HASH_ARRAY_SIZE;
  this->table = new Deque*[this->currentSize];

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

  if (this->tableIsFull(hash)){
    this->rearrange();
    hash = this->createHash(flight.id);
  }

  this->table[hash]->pushFront(flight);

  return true;
}

bool Hash::tableIsFull(int hash){
  Deque *list = this->table[hash];
  if (list == NULL)
    return false;

  return this->table[hash]->getSize() == HASH_LIST_LIMIT;
}

void Hash::rearrange(){
  cout << "\n";
  cout << "\nTime to rearrange Hash...";

  int newSize = this->getNextPrime(this->currentSize);

  Deque **result = (Deque**) realloc(this->table, newSize * sizeof(Deque));
  if (result == NULL){
    cout << "OH MY GOD, I CAN'T REALLOCATE MORE MEMORY! :'(";
    exit(1);
  }

  cout << "\nCurrent Hash size: " << this->currentSize;
  cout << "\nNew Hash size:     " << newSize;
  cout << "\n";

  this->table = result;
  this->currentSize = newSize;

  for (int i = 0; i < this->currentSize; i++){
    Deque *list = this->table[i];

    if (list == NULL || list->isEmpty())
      continue;

    this->moveEntries(list, i);
  }
}

void Hash::moveEntries(Deque *list, int index){
  Node  *walker = list->getHead();

  while (walker != NULL){
    Flight flight = walker->flight;
    int hash = this->createHash(flight.id);

    if (hash == index){
      walker = walker->next;
    } else {
      list->remove(walker);
      this->add(flight);

      walker = list->getHead();
    }
  }
}

bool Hash::exists(int flightId){
  return this->get(flightId) != NULL;
}

Flight Hash::remove(Node *node){
  int hash = this->createHash(node->flight.id);
  Flight flight = this->table[hash]->remove(node);

  return flight;
}

int Hash::createHash(int key){
  return key % HASH_ARRAY_SIZE;
}

bool Hash::isPrime(int value){
  if (value == 1)
    return false;

  if (value == 2 || value == 3)
    return true;

  for (int i = 2; i <= value / 2; i++){
    if (value % i == 0)
      return false;
  }

  return true;
}

int Hash::getNextPrime(int current){
  int found = current;
  int walker = current;

  while (found == current) {
    if (this->isPrime(++walker))
      found = walker;
  }

  return found;
}

