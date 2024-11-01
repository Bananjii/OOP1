#include "Vantazhni.h"
#include <iostream>
#include <limits>

Vantazhni::Vantazhni(std::string n, double c, int d, double w)
    : Perevezennya(n, c, d), weight(w) {}

Vantazhni::~Vantazhni() {}

void Vantazhni::input() {
    Perevezennya::input();

    // Перевірка для введення ваги вантажу
    while (true) {
        std::cout << "Введіть вагу вантажу (тонни): ";
        std::cin >> weight;
        if (std::cin.fail() || weight <= 0) {
            std::cout << "Вага вантажу має бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

void Vantazhni::display() const {
    std::cout << "Вантажне перевезення: " << name << "\n"
              << "Вартість: " << cost << "\n"
              << "Тривалість: " << duration << " годин\n";
}
