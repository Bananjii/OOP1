#ifndef CARGOTRANSPORT_H
#define CARGOTRANSPORT_H

#include "Transport.h"

class CargoTransport : public Transport {
private:
    int loadWeight;

public:
    CargoTransport(const std::string& name, int capacity, int loadWeight);
    virtual void showInfo() const override; // Перевизначена віртуальна функція
};

#endif
