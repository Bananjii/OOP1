#include "Perevezennya.h"
#include <iostream>

Perevezennya::Perevezennya(std::string n, double c, int d) : name(n), cost(c), duration(d) {}

Perevezennya::~Perevezennya() {}

std::string Perevezennya::getName() const {
    return name;
}

double Perevezennya::getCost() const {
    return cost;
}

int Perevezennya::getDuration() const {
    return duration;
}

void Perevezennya::setName(std::string n) {
    name = n;
}

void Perevezennya::setCost(double c) {
    if (c >= 0)
        cost = c;
    else
        std::cout << "Вартість не може бути негативною!" << std::endl;
}

void Perevezennya::setDuration(int d) {
    if (d >= 0)
        duration = d;
    else
        std::cout << "Тривалість не може бути негативною!" << std::endl;
}

// Метод для введення даних
void Perevezennya::input() {
    std::cout << "Введіть назву перевезення: ";
    std::cin >> name;
    std::cout << "Введіть вартість перевезення: ";
    std::cin >> cost;
    setCost(cost); // Викликаємо метод для валідації
    std::cout << "Введіть тривалість перевезення (години): ";
    std::cin >> duration;
    setDuration(duration); // Викликаємо метод для валідації
}
