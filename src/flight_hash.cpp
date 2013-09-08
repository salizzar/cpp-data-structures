#include "flight_hash.h"

using namespace std;

FlightHash::FlightHash(){
}

void FlightHash::addFlight(){
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

  manager.addFlight(flight);

  cout << "\nSuccessfully added flight.\n";
}

void FlightHash::showFlight(){
  int flightId;
  cout << "\nEnter flight id: "; cin >> flightId;

  manager.showFlight(flightId);
}

void FlightHash::deleteFlight(){
  int flightId;
  cout << "\nEnter flight id: "; cin >> flightId;

  if (manager.deleteFlight(flightId))
    cout << "Successfully deleted flight.";
  else
    cout << "Flight not found.\n";
}

void FlightHash::showMenu(){
  cout << "\n------------------------";
  cout << "\n1 - Add flight";
  cout << "\n2 - Show flight";
  cout << "\n3 - Delete flight";
  cout << "\n9 - Exit";
  cout << "\n";
  cout << "\nEnter a option:  ";
}

void FlightHash::run(){
  int option;

  do {
    this->showMenu();

    cin >> option; cout << "\n";

    switch (option){
      case 1:
        this->addFlight();
        break;

      case 2:
        this->showFlight();
        break;

      case 3:
        this->deleteFlight();
        break;

      case 9:
        break;

      default:
        Util::clearInvalidOption();
        cout << "\nInvalid option, try again.\n";
    }
  } while (option != 9);

  cin.ignore();
}

