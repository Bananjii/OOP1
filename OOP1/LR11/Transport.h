#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>

class Transport {
protected:
    std::string name;
    int capacity;

public:
    Transport(const std::string& name, int capacity); // Конструктор
    virtual ~Transport(); // Віртуальний деструктор

    virtual void showInfo() const = 0; // Чисто віртуальна функція
};

#endif
