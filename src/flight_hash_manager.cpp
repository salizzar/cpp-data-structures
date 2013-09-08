#include "flight_hash_manager.h"

using namespace std;

FlightHashManager::FlightHashManager(){
}

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

  hash.remove(node);

  return true;
}

