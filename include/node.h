#include <iostream>
#include "flight.h"

#pragma once

struct Node {
  Node    *left, *right;
  Flight  flight;
};

