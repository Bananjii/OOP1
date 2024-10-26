#include "Vantazhni.h"
#include <iostream>

Vantazhni::Vantazhni(std::string n, double c, int d, double w)
    : Perevezennya(n, c, d), weight(w) {}

Vantazhni::~Vantazhni() {}

double Vantazhni::getWeight() const {
    return weight;
}

void Vantazhni::setWeight(double w) {
    if (w >= 0)
        weight = w;
    else
        std::cout << "Вага не може бути негативною!" << std::endl;
}

// Метод для введення даних
void Vantazhni::input() {
    Perevezennya::input(); // Викликаємо базовий метод для вводу загальних даних
    std::cout << "Введіть вагу вантажу (тонни): ";
    std::cin >> weight;
    setWeight(weight); // Викликаємо метод для валідації
}

void Vantazhni::display() const {
    std::cout << "Вантажне перевезення: " << name << "\n"
              << "Вартість: " << cost << "\n"
              << "Тривалість: " << duration << " годин\n"
              << "Вага: " << weight << " тонн\n";
}
