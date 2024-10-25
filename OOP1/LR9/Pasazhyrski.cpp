#include "Pasazhyrski.h"
#include <iostream>

Pasazhyrski::Pasazhyrski(std::string n, double c, int d, int p)
    : Perevezennya(n, c, d), passengers(p) {}

Pasazhyrski::~Pasazhyrski() {}

void Pasazhyrski::input() {
    Perevezennya::input();
    std::cout << "Введіть кількість пасажирів: ";
    std::cin >> passengers;
}

void Pasazhyrski::display() const {
    std::cout << "Пасажирське перевезення: " << name << "\n"
              << "Вартість: " << cost << "\n"
              << "Тривалість: " << duration << " годин\n";
}
