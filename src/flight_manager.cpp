#include "flight_manager.h"

bool FlightManager::noFlights(){
  return deque.isEmpty();
}

bool FlightManager::addFlight(Flight newFlight){
  if (deque.isEmpty())
    return deque.pushFront(newFlight);

  if (newFlight.national_authority)
    return deque.pushFront(newFlight);

  Node *node = deque.getHead();
  bool lowerFuel;

  while (node != NULL){
    Flight flight = node->flight;
    lowerFuel = flight.fuel_quantity > newFlight.fuel_quantity;

    if (lowerFuel)
      return deque.insertBefore(node, newFlight);

    node = node->next;
  }

  deque.pushBack(newFlight);

  return true;
}

bool FlightManager::deleteFlight(int flight_id){
  Node *node = deque.getHead();
  Node *target = NULL;

  while (target == NULL && node != NULL){
    if (node->flight.id == flight_id){
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

bool FlightManager::deleteFirstFlight(){
  deque.popFront();
  return true;
}

bool FlightManager::deleteLastFlight(){
  deque.popBack();
  return true;
}

void FlightManager::showFlights(){
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

