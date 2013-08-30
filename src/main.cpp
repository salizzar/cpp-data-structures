#include <iostream>
#include "flight_manager.h"

using namespace std;

void addFlight(FlightManager &manager){
  int    flight_id;
  char   flight_authority[1];
  double flight_fuel;
  Flight flight;

  cout << "Flight id:                               "; cin >> flight_id;
  flight.id = flight_id;

  cout << "Flight fuel quantity:                    "; cin >> flight_fuel;
  flight.fuel_quantity = flight_fuel;

  cout << "Flight is from national authority? (y/n) "; cin >> flight_authority;
  flight.national_authority = tolower(flight_authority[0]) == 'y';

  manager.addFlight(flight);

  cout << "\nSuccessfully added flight.\n";
}

void deleteFirstFlight(FlightManager &manager){
  if (manager.noFlights()){
    cout << "\nNo flights available.\n";
    return;
  }

  char option;

  cout << "\nAre you sure? (y/n) ";
  cin >> option;

  if (tolower(option) != 'y'){
    cout << "\nNothing to do.";
    return;
  }

  if (!manager.deleteFirstFlight()){
    cout << "\nCannot remove first flight! :(";
  } else {
    cout << "\nSuccessfully removed first flight.";
  }
}

void deleteLastFlight(FlightManager &manager){
  if (manager.noFlights()){
    cout << "\nNo flights available.\n";
    return;
  }

  char option;

  cout << "\nAre you sure? (y/n) ";
  cin >> option;

  if (tolower(option) != 'y'){
    cout << "\nNothing to do.";
    return;
  }

  if (!manager.deleteLastFlight()){
    cout << "\nCannot remove last flight! :(";
  } else {
    cout << "\nSuccessfully removed last flight.";
  }
}

void deleteFlight(FlightManager &manager){
  if (manager.noFlights()){
    cout << "\nNo flights available.\n";
    return;
  }

  int flight_id;

  cout << "\nEnter flight id: "; cin >> flight_id;

  if (manager.deleteFlight(flight_id))
    cout << "Successfully deleted flight.";
  else
    cout << "Flight not found.\n";
}

void showFlights(FlightManager &manager){
  manager.showFlights();
}

void showMenu(){
  cout << "\n------------------------";
  cout << "\n1 - Add flight";
  cout << "\n2 - Show flights";
  cout << "\n3 - Delete flight";
  cout << "\n4 - Delete first flight";
  cout << "\n5 - Delete last flight";
  cout << "\n9 - Exit";
  cout << "\n-----------------------";
  cout << "\n";
  cout << "\nEnter a option:  ";
}

int main(){
  FlightManager manager;
  int option;

  do {
    showMenu();

    cin >> option; cout << "\n";

    switch (option){
      case 1:
        addFlight(manager);
        break;

      case 2:
        showFlights(manager);
        break;

      case 3:
        deleteFlight(manager);
        break;

      case 4:
        deleteFirstFlight(manager);
        break;

      case 5:
        deleteLastFlight(manager);
        break;

      case 9:
        break;

      default:
        if (cin.fail()){
          char dummy[255];
          cin.clear();
          cin >> dummy;
        }

        cout << "\nInvalid option, try again.\n";
    }
  } while (option != 9);

  cin.ignore();
}

