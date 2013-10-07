#include "flight_tree.h"

using namespace std;

void FlightTree::addFlight(){
  Flight flight = FlightFacade::create();

  this->manager.addFlight(flight);

  cout << "\nSuccessfully added flight.\n";
}

void FlightTree::showFlight(){
  int flightId;
  cout << "\nEnter flight id: "; cin >> flightId;

  this->manager.showFlight(flightId);
}

void FlightTree::deleteFlight(){
  int flightId;
  cout << "\nEnter flight id: "; cin >> flightId;

  if (this->manager.deleteFlight(flightId))
    cout << "Successfully deleted flight.";
  else
    cout << "Flight not found.\n";
}

void FlightTree::showAllFlights(){
  this->manager.showAllFlights();

  cout << "\nDone.\n";
}

void FlightTree::deleteAllFlights(){
  this->manager.deleteAllFlights();

  cout << "\nSuccessfully deleted all flights.\n";
}

void FlightTree::showMenu(){
  cout << "\n------------------------";
  cout << "\n1 - Add flight";
  cout << "\n2 - Show flight";
  cout << "\n3 - Delete flight";
  cout << "\n4 - Show all flights";
  cout << "\n5 - Delete all flights";
  cout << "\n9 - Exit";
  cout << "\n";
  cout << "\nEnter a option:  ";
}

void FlightTree::run(){
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

      case 4:
        this->showAllFlights();
        break;

      case 5:
        this->deleteAllFlights();
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

