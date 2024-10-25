// CargoTransport.h
#ifndef CARGO_TRANSPORT_H
#define CARGO_TRANSPORT_H

#include "Transport.h"
#include <iostream>

class CargoTransport : public Transport {
private:
    int loadWeight;

public:
    CargoTransport(const std::string& name = "", int capacity = 0, int loadWeight = 0)
        : Transport(name, capacity), loadWeight(loadWeight) {}

    void showInfo() const override {
        std::cout << "Cargo Transport: " << name << "\nCapacity: " << capacity
                  << "\nLoad weight: " << loadWeight << " kg" << std::endl;
    }

    void saveToFile(std::ofstream& ofs) const override {
        ofs << "Cargo " << name << " " << capacity << " " << loadWeight << std::endl;
    }

    void loadFromFile(std::ifstream& ifs) override {
        ifs >> name >> capacity >> loadWeight;
    }
};

#endif // CARGO_TRANSPORT_H
