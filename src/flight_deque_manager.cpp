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

  Entry *entry = this->deque.getHead();
  Flight flight;
  bool lowerFuel;

  while (entry != NULL){
    lowerFuel = flight.fuel_quantity > newFlight.fuel_quantity;
    flight = entry->flight;

    if (lowerFuel)
      return this->deque.insertBefore(entry, newFlight);

    entry = entry->next;
  }

  this->deque.pushBack(newFlight);

  return true;
}

bool FlightDequeManager::deleteFlight(int flightId){
  Entry *entry = this->deque.getHead();
  Entry *target = NULL;

  while (target == NULL && entry != NULL){
    if (entry->flight.id == flightId){
      target = entry;
      break;
    }

    entry = entry->next;
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

  Entry *entry = this->deque.getHead();

  FlightFacade::showHeaders();

  while (entry != NULL){
    FlightFacade::show(entry->flight);

    entry = entry->next;
  }
}

