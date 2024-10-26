#ifndef PASSENGERTRANSPORT_H
#define PASSENGERTRANSPORT_H

#include "Transport.h"

class PassengerTransport : public Transport {
private:
    int passengerCount;

public:
    PassengerTransport(const std::string& name, int capacity, int passengerCount);
    virtual void showInfo() const override; // Перевизначена віртуальна функція
};

#endif
