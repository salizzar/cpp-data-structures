#include "flight_facade.h"

using namespace std;

Flight FlightFacade::create(){
  int     flightId;
  char    flightAuthority[1];
  double  flightFuel;
  Flight  flight;

  cout << "Flight id:                               "; cin >> flightId;
  flight.id = flightId;

  cout << "Flight fuel quantity:                    "; cin >> flightFuel;
  flight.fuel_quantity = flightFuel;

  cout << "Flight is from national authority? (y/n) "; cin >> flightAuthority;
  flight.national_authority = tolower(flightAuthority[0]) == 'y';

  return flight;
}

void FlightFacade::showHeaders(){
  cout << "\n";
  cout << "| flight id | fuel quantity | national authority |";
  cout << "\n";
}

void FlightFacade::show(Flight flight){
  cout << "|" << std::setw(10) << flight.id << " ";
  cout << "|" << std::setw(14) << flight.fuel_quantity << " ";
  cout << "|" << std::setw(19) << flight.national_authority << " ";
  cout << "|\n";
}

