#include "Pasazhyrski.h"
#include <iostream>
#include <limits>

Pasazhyrski::Pasazhyrski(std::string n, double c, int d, int p)
    : Perevezennya(n, c, d), passengers(p) {}

Pasazhyrski::~Pasazhyrski() {}

void Pasazhyrski::input() {
    Perevezennya::input();

    // Перевірка для введення кількості пасажирів
    while (true) {
        std::cout << "Введіть кількість пасажирів: ";
        std::cin >> passengers;
        if (std::cin.fail() || passengers <= 0) {
            std::cout << "Кількість пасажирів має бути цілим числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

void Pasazhyrski::display() const {
    std::cout << "Пасажирське перевезення: " << name << "\n"
              << "Вартість: " << cost << "\n"
              << "Тривалість: " << duration << " годин\n";
}
