#include <iostream>
#include "flight_manager.h"

void addFlight(FlightManager &manager){
  int    flight_id;
  char   flight_authority[1];
  double flight_fuel;

  cout << "Flight id:                               "; cin >> flight_id;
  cout << "Flight is from national authority? (y/n) "; cin >> flight_authority;
  cout << "Flight fuel quantity:                    "; cin >> flight_fuel;

  Flight flight;
  flight.id = flight_id;
  flight.national_authority = tolower(flight_authority[0]) == 'y';
  flight.fuel_quantity = flight_fuel;

  manager.addFlight(flight);

  cout << "\nSuccessfully added flight.\n";
}

void deleteFlight(FlightManager &manager){
  int flight_id;

  cout << "\nEnter flight id: "; cin >> flight_id;

  if (manager.deleteFlight(flight_id))
    cout << "\nSuccessfully deleted flight.";
  else
    cout << "\nFlight not found.";
}

void showFlights(FlightManager &manager){
  manager.showFlights();
}

int main(){
  FlightManager manager;
  int option;

  do {
    cout << "\n-----------------\n";
    cout << "\n1 - Add flight";
    cout << "\n2 - Delete flight";
    cout << "\n3 - Show flights";
    cout << "\n9 - Exit";
    cout << "\n-----------------\n";
    cout << "\nEnter a option:  ";

    cin >> option; cout << "\n";

    switch (option){
      case 1:
        addFlight(manager);
        break;

      case 2:
        deleteFlight(manager);
        break;

      case 3:
        showFlights(manager);
        break;

      case 9:
        break;

      default:
        cout << "\nInvalid option, try again.\n";
    }
  } while (option != 9);

  cin.ignore();
}

