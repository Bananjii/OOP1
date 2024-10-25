// Transport.h
#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>
#include <fstream>

class Transport {
protected:
    std::string name;
    int capacity;

public:
    Transport(const std::string& name = "", int capacity = 0) : name(name), capacity(capacity) {}
    virtual ~Transport() {}

    virtual void showInfo() const = 0; // Чисто віртуальний метод для виведення інформації
    virtual void saveToFile(std::ofstream& ofs) const = 0; // Віртуальний метод для запису у файл
    virtual void loadFromFile(std::ifstream& ifs) = 0; // Віртуальний метод для читання з файлу
};

#endif // TRANSPORT_H
