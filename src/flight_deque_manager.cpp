#include "flight_deque_manager.h"

using namespace std;

bool FlightDequeManager::noFlights(){
  return deque.isEmpty();
}

bool FlightDequeManager::addFlight(Flight newFlight){
  if (deque.isEmpty())
    return deque.pushFront(newFlight);

  if (newFlight.national_authority)
    return deque.pushFront(newFlight);

  Node *node = deque.getHead();
  Flight flight;
  bool lowerFuel;

  while (node != NULL){
    lowerFuel = flight.fuel_quantity > newFlight.fuel_quantity;
    flight = node->flight;

    if (lowerFuel)
      return deque.insertBefore(node, newFlight);

    node = node->next;
  }

  deque.pushBack(newFlight);

  return true;
}

bool FlightDequeManager::deleteFlight(int flightId){
  Node *node = deque.getHead();
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

  deque.remove(target);

  return true;
}

bool FlightDequeManager::deleteFirstFlight(){
  deque.popFront();
  return true;
}

bool FlightDequeManager::deleteLastFlight(){
  deque.popBack();
  return true;
}

void FlightDequeManager::showFlights(){
  if (deque.isEmpty()){
    cout << "\n No flights to show.\n";
    return;
  }

  Node *node = deque.getHead();
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

