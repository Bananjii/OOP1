#include "Vantazhni.h"
#include <iostream>
#include <limits>

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

// Метод для введення даних з перевірками
void Vantazhni::input() {
    Perevezennya::input();

    while (true) {
        std::cout << "Введіть вагу вантажу (тонни): ";
        std::cin >> weight;
        if (std::cin.fail() || weight < 0) {
            std::cout << "Вага повинна бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            setWeight(weight);
            break;
        }
    }
}

void Vantazhni::display() const {
    std::cout << "Вантажне перевезення: " << name << "\n"
              << "Вартість: " << cost << "\n"
              << "Тривалість: " << duration << " годин\n"
              << "Вага: " << weight << " тонн\n";
}
