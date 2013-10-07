#include <iostream>
#include <iomanip>
#include "flight.h"

#pragma once

class FlightFacade {
public:
  static Flight create();

  static void   showHeaders();
  static void   show(Flight);
};

