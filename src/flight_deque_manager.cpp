#include "flight_deque_manager.h"

using namespace std;

bool FlightDequeManager::noFlights(){
  return this->deque.isEmpty();
}

bool FlightDequeManager::addFlight(Flight newFlight){
  if (this->deque.isEmpty())
    return this->deque.pushFront(newFlight);

  if (newFlight.national_authority)
    return this->deque.pushFront(newFlight);

  Node *node = this->deque.getHead();
  Flight flight;
  bool lowerFuel;

  while (node != NULL){
    lowerFuel = flight.fuel_quantity > newFlight.fuel_quantity;
    flight = node->flight;

    if (lowerFuel)
      return this->deque.insertBefore(node, newFlight);

    node = node->next;
  }

  this->deque.pushBack(newFlight);

  return true;
}

bool FlightDequeManager::deleteFlight(int flightId){
  Node *node = this->deque.getHead();
  Node *target = NULL;

  while (target == NULL && node != NULL){
    if (node->flight.id == flightId){
      target = node;
      break;
    }

    node = node->next;
  }

  if (target == NULL)
    return false;

  this->deque.remove(target);

  return true;
}

bool FlightDequeManager::deleteFirstFlight(){
  this->deque.popFront();
  return true;
}

bool FlightDequeManager::deleteLastFlight(){
  this->deque.popBack();
  return true;
}

void FlightDequeManager::showFlights(){
  if (this->deque.isEmpty()){
    cout << "\nNo flights to show.\n";
    return;
  }

  Node *node = this->deque.getHead();
  Flight flight;

  cout << "\n";
  cout << "| flight id | fuel quantity | national authority |";
  cout << "\n";

  while (node != NULL){
    flight = node->flight;

    cout << "|" << std::setw(10) << flight.id << " ";
    cout << "|" << std::setw(14) << flight.fuel_quantity << " ";
    cout << "|" << std::setw(19) << flight.national_authority << " ";
    cout << "|\n";

    node = node->next;
  }
}

