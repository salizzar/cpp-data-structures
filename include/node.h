#include <iostream>
#include "flight.h"

#pragma once

//TODO: use templates
struct Node {
  Node   *previous, *next;
  Flight flight;
};

