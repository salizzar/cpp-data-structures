#include "flight_deque.h"

using namespace std;

FlightDeque::FlightDeque(){
}

void FlightDeque::addFlight(){
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

  this->manager.addFlight(flight);

  cout << "\nSuccessfully added flight.\n";
}

void FlightDeque::deleteFirstFlight(){
  if (this->manager.noFlights()){
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

  if (!this->manager.deleteFirstFlight()){
    cout << "\nCannot remove first flight! :(";
  } else {
    cout << "\nSuccessfully removed first flight.";
  }
}

void FlightDeque::deleteLastFlight(){
  if (this->manager.noFlights()){
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

  if (!this->manager.deleteLastFlight()){
    cout << "\nCannot remove last flight! :(";
  } else {
    cout << "\nSuccessfully removed last flight.";
  }
}

void FlightDeque::deleteFlight(){
  if (this->manager.noFlights()){
    cout << "\nNo flights available.\n";
    return;
  }

  int flightId;
  cout << "\nEnter flight id: "; cin >> flightId;

  if (this->manager.deleteFlight(flightId))
    cout << "Successfully deleted flight.";
  else
    cout << "Flight not found.\n";
}

void FlightDeque::showFlights(){
  this->manager.showFlights();
}

void FlightDeque::showMenu(){
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

void FlightDeque::run(){
  int option;

  do {
    this->showMenu();

    cin >> option; cout << "\n";

    switch (option){
      case 1:
        this->addFlight();
        break;

      case 2:
        this->showFlights();
        break;

      case 3:
        this->deleteFlight();
        break;

      case 4:
        this->deleteFirstFlight();
        break;

      case 5:
        this->deleteLastFlight();
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

