#include <iostream>
#include <iomanip>
#include "deque.h"
#include "flight_facade.h"

#pragma once

class FlightDequeManager {
private:
  Deque deque;

public:
  bool noFlights();
  bool addFlight(Flight);
  bool deleteFlight(int);
  bool deleteFirstFlight();
  bool deleteLastFlight();
  void showFlights();
};

