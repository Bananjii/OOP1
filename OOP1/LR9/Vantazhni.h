#ifndef VANTAZHNI_H
#define VANTAZHNI_H

#include "Perevezennya.h"

class Vantazhni : public Perevezennya {
private:
    double weight; // Вага вантажу (тонни)

public:
    Vantazhni(std::string n = "", double c = 0.0, int d = 0, double w = 0.0);
    ~Vantazhni();

    // Дружній клас Display
    friend class Display;

    void display() const override;
    void input() override; // Метод для введення даних
    double getWeight() const { return weight; } // Геттер для ваги
};

#endif
