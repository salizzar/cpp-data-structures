#include <iostream>
#include "flight_deque_manager.h"
#include "flight_facade.h"
#include "util.h"

#pragma once

class FlightDeque {
private:
  FlightDequeManager manager;

  void addFlight();
  void deleteFirstFlight();
  void deleteLastFlight();
  void deleteFlight();
  void showFlights();
  void showMenu();

public:
  void run();
};

