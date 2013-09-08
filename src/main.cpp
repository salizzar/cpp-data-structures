#include <iostream>
#include "flight_deque.h"
#include "flight_hash.h"
#include "util.h"

using namespace std;

void showMenu(){
  cout << "\n-----------------------------";
  cout << "\n1 - Deque";
  cout << "\n2 - Hash";
  cout << "\n9 - Exit Program";
  cout << "\n-----------------------------";
  cout << "\n";
  cout << "\nEnter a option:  ";
}

int main(){
  int         option;
  FlightDeque deque;
  FlightHash  hash;

  do {
    showMenu();

    cin >> option; cout << "\n";

    switch (option){
      case 1:
        deque.run();
        break;

      case 2:
        hash.run();
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

