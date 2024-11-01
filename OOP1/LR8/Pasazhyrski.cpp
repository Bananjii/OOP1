#include "Pasazhyrski.h"
#include <iostream>
#include <limits>

Pasazhyrski::Pasazhyrski(std::string n, double c, int d, int p)
    : Perevezennya(n, c, d), passengers(p) {}

Pasazhyrski::~Pasazhyrski() {}

int Pasazhyrski::getPassengers() const {
    return passengers;
}

void Pasazhyrski::setPassengers(int p) {
    if (p >= 0)
        passengers = p;
    else
        std::cout << "Кількість пасажирів не може бути негативною!" << std::endl;
}

// Метод для введення даних з перевірками
void Pasazhyrski::input() {
    Perevezennya::input();

    while (true) {
        std::cout << "Введіть кількість пасажирів: ";
        std::cin >> passengers;
        if (std::cin.fail() || passengers < 0) {
            std::cout << "Кількість пасажирів повинна бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            setPassengers(passengers);
            break;
        }
    }
}

void Pasazhyrski::display() const {
    std::cout << "Пасажирське перевезення: " << name << "\n"
              << "Вартість: " << cost << "\n"
              << "Тривалість: " << duration << " годин\n"
              << "Кількість пасажирів: " << passengers << "\n";
}
