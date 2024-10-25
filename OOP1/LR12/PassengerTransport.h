// PassengerTransport.h
#ifndef PASSENGER_TRANSPORT_H
#define PASSENGER_TRANSPORT_H

#include "Transport.h"
#include <iostream>

class PassengerTransport : public Transport {
private:
    int passengerCount;

public:
    PassengerTransport(const std::string& name = "", int capacity = 0, int passengerCount = 0)
        : Transport(name, capacity), passengerCount(passengerCount) {}

    void showInfo() const override {
        std::cout << "Passenger Transport: " << name << "\nCapacity: " << capacity
                  << "\nPassenger count: " << passengerCount << std::endl;
    }

    void saveToFile(std::ofstream& ofs) const override {
        ofs << "Passenger " << name << " " << capacity << " " << passengerCount << std::endl;
    }

    void loadFromFile(std::ifstream& ifs) override {
        ifs >> name >> capacity >> passengerCount;
    }
};

#endif // PASSENGER_TRANSPORT_H
