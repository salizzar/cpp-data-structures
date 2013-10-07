#include <iostream>
#include "flight_facade.h"
#include "flight_tree_manager.h"
#include "util.h"

#pragma once

class FlightTree {
private:
  FlightTreeManager manager;

  void addFlight();
  void showFlight();
  void deleteFlight();
  void showAllFlights();
  void deleteAllFlights();
  void showMenu();

public:
  void run();
};

