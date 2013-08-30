#include <iostream>
#include <iomanip>
#include "deque.h"

#pragma once

using namespace std;

class FlightManager {
private:
  Deque deque;

public:
  bool addFlight(Flight);

  bool deleteFlight(int);
  bool deleteFirstFlight();
  bool deleteLastFlight();

  void showFlights();
};

