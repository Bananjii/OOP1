#ifndef PEREVEZENNYA_H
#define PEREVEZENNYA_H

#include <string>

class Perevezennya {
protected:
    std::string name;
    double cost;
    int duration; // Тривалість перевезення (години)

public:
    Perevezennya(std::string n = "", double c = 0.0, int d = 0);
    virtual ~Perevezennya();

    std::string getName() const;
    double getCost() const;
    int getDuration() const;

    virtual void display() const = 0;
    virtual void input(); // Метод для введення даних

    void setName(std::string n);
    void setCost(double c);
    void setDuration(int d);
};

#endif
