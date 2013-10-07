#include "flight_hash_manager.h"

using namespace std;

bool FlightHashManager::addFlight(Flight flight){
  return this->hash.add(flight);
};

void FlightHashManager::showFlight(int flightId){
  Entry *entry = this->hash.get(flightId);
  if (entry == NULL){
    cout << "\nNo flight to show.\n";
    return;
  }

  FlightFacade::showHeaders();
  FlightFacade::show(entry->flight);
};

bool FlightHashManager::deleteFlight(int flightId){
  Entry *entry = this->hash.get(flightId);
  if (entry == NULL){
    return false;
  }

  this->hash.remove(entry);

  return true;
}

void FlightHashManager::heavyCharge(int items, int range){
  int id;

  srand(time(NULL));

  for (int i = 0; i < items; i++){
    id = rand() % range + 1;

    Flight flight;
    flight.id = id;
    flight.fuel_quantity = i + 10.5;
    flight.national_authority = false;

    cout << "\nAdding flight " << flight.id;

    this->hash.add(flight);
  }
}

void FlightHashManager::showAllFlights(){
  this->hash.show();
}

void FlightHashManager::deleteAllFlights(){
  this->hash.clear();
}

