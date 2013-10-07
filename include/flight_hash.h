#include <iostream>
#include "flight_facade.h"
#include "flight_hash_manager.h"
#include "util.h"

#pragma once

class FlightHash {
private:
  FlightHashManager manager;

  void addFlight();
  void showFlight();
  void deleteFlight();
  void heavyCharge();
  void showAllFlights();
  void deleteAllFlights();
  void showMenu();

public:
  void run();
};

