#include <iostream>
#include "flight.h"

#pragma once

//TODO: use templates
struct Entry {
  Entry   *previous, *next;
  Flight  flight;
};

