#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "PassengerTransport.h"
#include "CargoTransport.h"
#include "Transport.h"

// Функція для збереження даних у файл
void saveToFile(const std::string& filename, const std::vector<Transport*>& transports) {
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return;
    }
    for (const auto& transport : transports) {
        transport->saveToFile(ofs);
    }
    ofs.close();
    std::cout << "Дані успішно збережено у файл." << std::endl;
}

// Функція для завантаження даних з файлу
void loadFromFile(const std::string& filename, std::vector<Transport*>& transports) {
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cerr << "Не вдалося відкрити файл для читання." << std::endl;
        return;
    }

    std::string type;
    while (ifs >> type) {
        if (type == "Passenger") {
            Transport* transport = new PassengerTransport();
            transport->loadFromFile(ifs);
            transports.push_back(transport);
        } else if (type == "Cargo") {
            Transport* transport = new CargoTransport();
            transport->loadFromFile(ifs);
            transports.push_back(transport);
        }
    }
    ifs.close();
    std::cout << "Дані успішно завантажено з файлу." << std::endl;
}

// Функція для введення нових транспортних засобів
void addTransport(std::vector<Transport*>& transports) {
    int choice;
    std::cout << "Оберіть тип транспорту для додавання:\n";
    std::cout << "1. Пасажирський транспорт\n";
    std::cout << "2. Вантажний транспорт\n";
    std::cin >> choice;
    std::cin.ignore(); // Очищуємо буфер вводу перед використанням getline

    std::string name;
    int capacity;

    std::cout << "Введіть назву транспорту: ";
    std::getline(std::cin, name); // Використовуємо getline для вводу назви
    std::cout << "Введіть місткість транспорту: ";
    std::cin >> capacity;
    std::cin.ignore(); // Очищуємо буфер вводу

    if (choice == 1) {
        int passengerCount;
        std::cout << "Введіть кількість пасажирів: ";
        std::cin >> passengerCount;
        transports.push_back(new PassengerTransport(name, capacity, passengerCount));
    }
    else if (choice == 2) {
        int loadWeight;
        std::cout << "Введіть вагу вантажу (кг): ";
        std::cin >> loadWeight;
        transports.push_back(new CargoTransport(name, capacity, loadWeight));
    }
    else {
        std::cout << "Невірний вибір. Спробуйте ще раз.\n";
    }
}

int main() {
    std::vector<Transport*> transports;
    std::string filename = "transports.txt";

    int option;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Додати новий транспорт\n";
        std::cout << "2. Вивести інформацію про всі транспортні засоби\n";
        std::cout << "3. Зберегти дані у файл\n";
        std::cout << "4. Завантажити дані з файлу\n";
        std::cout << "5. Вийти\n";
        std::cin >> option;
        std::cin.ignore(); // Очищуємо буфер вводу перед використанням getline

        switch (option) {
            case 1:
                addTransport(transports);
                break;
            case 2:
                std::cout << "\nІнформація про транспортні засоби:\n";
                for (const auto& transport : transports) {
                    transport->showInfo();
                    std::cout << "-----------------------" << std::endl;
                }
                break;
            case 3:
                saveToFile(filename, transports);
                break;
            case 4:
                loadFromFile(filename, transports);
                break;
            case 5:
                std::cout << "Вихід...\n";
                break;
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
                break;
        }
    } while (option != 5);

    // Звільнення пам'яті
    for (auto& transport : transports) {
        delete transport;
    }

    return 0;
}
