#include <iostream>
#include <vector>
#include <string>
#include "PassengerTransport.h"
#include "CargoTransport.h"
#include "Transport.h"

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

    // Початкове додавання кількох транспортних засобів
    transports.push_back(new PassengerTransport("Bus", 50, 45));
    transports.push_back(new CargoTransport("Truck", 10000, 8000));

    int option;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Додати новий транспорт\n";
        std::cout << "2. Вивести інформацію про всі транспортні засоби\n";
        std::cout << "3. Вийти\n";
        std::cin >> option;
        std::cin.ignore(); // Очищуємо буфер вводу перед використанням getline

        switch (option) {
            case 1:
                addTransport(transports); // Додавання нового транспорту
                break;
            case 2:
                std::cout << "\nІнформація про транспортні засоби:\n";
                for (const auto& transport : transports) {
                    transport->showInfo();
                    std::cout << "-----------------------" << std::endl;
                }
                break;
            case 3:
                std::cout << "Вихід...\n";
                break;
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
                break;
        }
    } while (option != 3);

    // Звільнення пам'яті
    for (auto& transport : transports) {
        delete transport;
    }

    return 0;
}
