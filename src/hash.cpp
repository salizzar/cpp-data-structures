#include "hash.h"

using namespace std;

Hash::Hash(){
  this->size = HASH_ARRAY_SIZE;
  this->table = new Deque*[this->size];

  for (int i = 0; i < HASH_ARRAY_SIZE; i++)
    this->table[i] = new Deque();
}

Hash::~Hash(){
  for (int i = 0; i < HASH_ARRAY_SIZE; i++)
    delete(this->table[i]);
}

Entry *Hash::get(int flightId){
  int hash = this->createHash(flightId);

  Deque *list = this->table[hash];
  if (list == NULL)
    return NULL;

  Entry *current = list->getHead();

  while (current != NULL){
    if (current->flight.id == flightId)
      break;

    current = current->next;
  }

  return current;
}

bool Hash::add(Flight flight){
  int hash = this->createHash(flight.id);

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

  return this->table[hash]->getSize() >= HASH_LIST_LIMIT;
}

void Hash::rearrange(){
  cout << "\n";
  cout << "\nTime to rearrange Hash...";

  int oldSize = this->size;
  int newSize = this->getNextPrime(this->size);

  Deque **result = (Deque**) realloc(this->table, newSize * sizeof(Deque*));
  if (result == NULL){
    cout << "OH MY GOD, I CAN'T REALLOCATE MORE MEMORY! :'(";
    exit(1);
  }

  cout << "\nCurrent Hash size: " << this->size;
  cout << "\nNew Hash size:     " << newSize;
  cout << "\n";

  this->table = result;
  this->size = newSize;

  for (int i = oldSize; i < newSize; i++)
    this->table[i] = new Deque();

  this->moveEntries(oldSize);
}

void Hash::moveEntries(int oldSize){
  Deque deque;
  Flight flight;

  for (int i = 0; i < oldSize; i++){
    Deque *list = this->table[i];

    if (list == NULL)
      continue;

    while (!list->isEmpty()){
      flight = list->popFront();
      deque.pushFront(flight);
    }
  }

  Entry *walker = deque.getHead();
  int hash;

  while (walker != NULL){
    Flight flight = walker->flight;
    hash = this->createHash(flight.id);

    this->table[hash]->pushFront(flight);

    walker = walker->next;
  }
}

bool Hash::exists(int flightId){
  return this->get(flightId) != NULL;
}

Flight Hash::remove(Entry *entry){
  int hash = this->createHash(entry->flight.id);
  Flight flight = this->table[hash]->remove(entry);

  return flight;
}

void Hash::show(){
  for (int i = 0; i < this->size; i++)
    this->table[i]->show();
}

void Hash::clear(){
  for (int i = 0; i < this->size; i++)
    this->table[i]->clear();
}

int Hash::createHash(int key){
  return key % this->size;
}

bool Hash::isPrime(int value){
  if (value == 1)
    return false;

  if (value == 2 || value == 3)
    return true;

  int square = (int) sqrt(value);
  for (int i = 2; i <= square; i++){
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

