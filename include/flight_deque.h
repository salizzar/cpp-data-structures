#include <iostream>
#include "flight_deque_manager.h"
#include "util.h"

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
  FlightDeque();

  void run();
};

