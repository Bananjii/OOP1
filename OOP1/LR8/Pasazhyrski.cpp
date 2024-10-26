#include "Pasazhyrski.h"
#include <iostream>

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

// Метод для введення даних
void Pasazhyrski::input() {
    Perevezennya::input(); // Викликаємо базовий метод для вводу загальних даних
    std::cout << "Введіть кількість пасажирів: ";
    std::cin >> passengers;
    setPassengers(passengers); // Викликаємо метод для валідації
}

void Pasazhyrski::display() const {
    std::cout << "Пасажирське перевезення: " << name << "\n"
              << "Вартість: " << cost << "\n"
              << "Тривалість: " << duration << " годин\n"
              << "Кількість пасажирів: " << passengers << "\n";
}
