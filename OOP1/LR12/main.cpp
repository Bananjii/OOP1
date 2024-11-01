#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include "PassengerTransport.h"
#include "CargoTransport.h"
#include "Transport.h"

// Функція для перевірки, чи рядок не є порожнім
bool isValidName(const std::string& name) {
    return !name.empty(); // Назва не повинна бути порожньою
}

// Функція для перевірки, чи введено дійсне позитивне число
bool isValidPositiveNumber(const std::string& str) {
    if (str.empty()) return false; // Якщо рядок порожній

    for (char c : str) {
        if (c < '0' || c > '9') { // Перевірка, що кожен символ є цифрою
            return false; // Якщо знайдено недопустимий символ
        }
    }
    return std::stoi(str) > 0; // Перевірка, що число більше 0
}

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

    // Введення вибору типу транспорту
    while (true) {
        std::cout << "Оберіть тип транспорту для додавання:\n";
        std::cout << "1. Пасажирський транспорт\n";
        std::cout << "2. Вантажний транспорт\n";
        std::cin >> choice;

        // Перевірка на введення некоректного значення
        if (std::cin.fail() || (choice != 1 && choice != 2)) {
            std::cout << "Невірний вибір. Будь ласка, введіть 1 або 2.\n";
            std::cin.clear(); // Очищення стану потоку
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищення буфера
        } else {
            break; // Виходимо з циклу, якщо вибір коректний
        }
    }

    std::cin.ignore(); // Очищуємо буфер вводу перед використанням getline

    std::string name;
    std::string capacityStr;

    // Введення назви транспорту
    while (true) {
        std::cout << "Введіть назву транспорту: ";
        std::getline(std::cin, name);
        if (isValidName(name)) {
            break; // Виходимо з циклу, якщо назва не порожня
        } else {
            std::cout << "Назва не може бути порожньою. Спробуйте ще раз.\n";
        }
    }

    // Введення місткості транспорту
    while (true) {
        std::cout << "Введіть місткість транспорту: ";
        std::getline(std::cin, capacityStr);
        if (isValidPositiveNumber(capacityStr)) {
            break; // Виходимо з циклу, якщо місткість введена коректно
        } else {
            std::cout << "Місткість має бути дійсним числом більше 0. Спробуйте ще раз.\n";
        }
    }
    int capacity = std::stoi(capacityStr); // Перетворюємо рядок у число

    if (choice == 1) {
        std::string passengerCountStr;
        // Введення кількості пасажирів
        while (true) {
            std::cout << "Введіть кількість пасажирів: ";
            std::getline(std::cin, passengerCountStr);
            if (isValidPositiveNumber(passengerCountStr)) {
                int passengerCount = std::stoi(passengerCountStr); // Перетворюємо рядок у число
                transports.push_back(new PassengerTransport(name, capacity, passengerCount));
                break;
            } else {
                std::cout << "Кількість пасажирів має бути дійсним числом більше 0. Спробуйте ще раз.\n";
            }
        }
    }
    else if (choice == 2) {
        std::string loadWeightStr;
        // Введення ваги вантажу
        while (true) {
            std::cout << "Введіть вагу вантажу (кг): ";
            std::getline(std::cin, loadWeightStr);
            if (isValidPositiveNumber(loadWeightStr)) {
                int loadWeight = std::stoi(loadWeightStr); // Перетворюємо рядок у число
                transports.push_back(new CargoTransport(name, capacity, loadWeight));
                break;
            } else {
                std::cout << "Вага вантажу має бути дійсним числом більше 0. Спробуйте ще раз.\n";
            }
        }
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
