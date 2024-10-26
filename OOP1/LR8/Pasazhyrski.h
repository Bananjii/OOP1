#ifndef PASAZHYRSKI_H
#define PASAZHYRSKI_H

#include "Perevezennya.h"

class Pasazhyrski : public Perevezennya {
private:
    int passengers; // Кількість пасажирів

public:
    Pasazhyrski(std::string n = "", double c = 0.0, int d = 0, int p = 0);
    ~Pasazhyrski();

    int getPassengers() const;
    void setPassengers(int p);

    void display() const override;
    void input() override; // Метод для введення даних
};

#endif
