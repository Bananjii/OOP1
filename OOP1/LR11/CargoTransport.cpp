#include "CargoTransport.h"

CargoTransport::CargoTransport(const std::string& name, int capacity, int loadWeight)
    : Transport(name, capacity), loadWeight(loadWeight) {}

void CargoTransport::showInfo() const {
    std::cout << "Cargo Transport: " << name << "\nCapacity: " << capacity 
              << "\nLoad weight: " << loadWeight << " kg" << std::endl;
}
