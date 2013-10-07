#include "flight_tree_manager.h"

using namespace std;

bool FlightTreeManager::addFlight(Flight flight){
  return this->tree.add(flight);
}

void FlightTreeManager::showFlight(int flightId){
  Node *node = this->tree.get(flightId);
  if (node == NULL){
    cout << "\nNo flight to show.\n";
    return;
  }

  FlightFacade::showHeaders();
  FlightFacade::show(node->flight);
}

bool FlightTreeManager::deleteFlight(int flightId){
  Node *node = this->tree.get(flightId);
  if (node == NULL){
    return false;
  }

  this->tree.remove(node);

  return true;
}

void FlightTreeManager::showAllFlights(){
  cout << "\n\nPrefix";
  this->tree.prefix();

  cout << "\n\nInfix";
  this->tree.infix();

  cout << "\n\nPostfix";
  this->tree.postfix();
}

void FlightTreeManager::deleteAllFlights(){
  this->tree.clear();
}

