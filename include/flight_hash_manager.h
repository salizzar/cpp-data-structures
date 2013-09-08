#include <iostream>
#include <iomanip>
#include "hash.h"

#pragma once

class FlightHashManager {
private:
  Hash hash;

public:
  FlightHashManager();

  bool addFlight(Flight);
  void showFlight(int);
  bool deleteFlight(int);
};

