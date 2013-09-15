#include "flight_hash_manager.h"

using namespace std;

bool FlightHashManager::addFlight(Flight newFlight){
  return this->hash.add(newFlight);
};

void FlightHashManager::showFlight(int flightId){
  Node *node = this->hash.get(flightId);
  if (node == NULL){
    cout << "\nNo flight to show.\n";
    return;
  }

  Flight flight = node->flight;

  cout << "\n";
  cout << "| flight id | fuel quantity | national authority |";
  cout << "\n";

  cout << "|" << std::setw(10) << flight.id << " ";
  cout << "|" << std::setw(14) << flight.fuel_quantity << " ";
  cout << "|" << std::setw(19) << flight.national_authority << " ";
  cout << "|\n";
};

bool FlightHashManager::deleteFlight(int flightId){
  Node *node = this->hash.get(flightId);
  if (node == NULL){
    return false;
  }

  this->hash.remove(node);

  return true;
}

void FlightHashManager::heavyCharge(int items){
  int id;

  srand(time(NULL));

  for (int i = 0; i < items; i++){
    id = rand() % items + 1;

    Flight flight;
    flight.id = id;
    flight.fuel_quantity = i + 10.5;
    flight.national_authority = false;

    cout << "\nAdding flight " << flight.id;

    this->hash.add(flight);
  }
}

