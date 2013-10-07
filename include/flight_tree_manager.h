#include <iostream>
#include "flight_facade.h"
#include "tree.h"

#pragma once

class FlightTreeManager {
private:
  Tree tree;

public:
  bool addFlight(Flight);
  void showFlight(int);
  bool deleteFlight(int);
  void showAllFlights();
  void deleteAllFlights();
};

