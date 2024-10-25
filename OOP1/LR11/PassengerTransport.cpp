#include "PassengerTransport.h"

PassengerTransport::PassengerTransport(const std::string& name, int capacity, int passengerCount)
    : Transport(name, capacity), passengerCount(passengerCount) {}

void PassengerTransport::showInfo() const {
    std::cout << "Passenger Transport: " << name << "\nCapacity: " << capacity 
              << "\nPassenger count: " << passengerCount << std::endl;
}
