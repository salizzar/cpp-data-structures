#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "hash.h"

#pragma once

class FlightHashManager {
private:
  Hash hash;

public:
  bool addFlight(Flight);
  void showFlight(int);
  bool deleteFlight(int);
  void heavyCharge(int);
};

