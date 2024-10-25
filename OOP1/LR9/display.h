#ifndef DISPLAY_H
#define DISPLAY_H

#include "Perevezennya.h"
#include "Pasazhyrski.h"
#include "Vantazhni.h"
#include <iostream>

class Display {
public:
    void show(const Perevezennya& perevezennya) const {
        perevezennya.display();
    }

    void showPassengers(const Pasazhyrski& p) const {
        std::cout << "Кількість пасажирів: " << p.passengers << std::endl;
    }

    void showWeight(const Vantazhni& v) const {
        std::cout << "Вага вантажу: " << v.weight << " тонн" << std::endl;
    }
};

#endif
