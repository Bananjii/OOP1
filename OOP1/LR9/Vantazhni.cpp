#include "Vantazhni.h"
#include <iostream>

Vantazhni::Vantazhni(std::string n, double c, int d, double w)
    : Perevezennya(n, c, d), weight(w) {}

Vantazhni::~Vantazhni() {}

void Vantazhni::input() {
    Perevezennya::input();
    std::cout << "Введіть вагу вантажу (тонни): ";
    std::cin >> weight;
}

void Vantazhni::display() const {
    std::cout << "Вантажне перевезення: " << name << "\n"
              << "Вартість: " << cost << "\n"
              << "Тривалість: " << duration << " годин\n";
}
