#include <iostream>
#include "flight_hash_manager.h"
#include "util.h"

class FlightHash {
private:
  FlightHashManager manager;

  void addFlight();
  void showFlight();
  void deleteFlight();
  void showMenu();

public:
  FlightHash();

  void run();
};

