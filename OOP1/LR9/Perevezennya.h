#ifndef PEREVEZENNYA_H
#define PEREVEZENNYA_H

#include <string>

class Perevezennya {
protected:
    std::string name; // Назва перевезення
    double cost;      // Вартість
    int duration;     // Тривалість (години)

public:
    Perevezennya(std::string n = "", double c = 0.0, int d = 0);
    virtual ~Perevezennya();

    virtual void display() const = 0; // Чисто віртуальний метод
    virtual void input(); // Метод для введення даних

    std::string getName() const;
    double getCost() const;
    int getDuration() const;

    void setName(std::string n);
    void setCost(double c);
    void setDuration(int d);
};

#endif
