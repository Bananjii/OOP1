#include <iostream>
#include <vector>
#include <limits>
#include "employee.h"


Employee::Employee() {}

Employee::~Employee() {}

void Employee::inputEmployeeData() {
    int numberOfEmployees;
    std::cout << "Введіть кількість службовців для додавання: ";
    std::cin >> numberOfEmployees;

    // Очищення буфера перед циклом
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < numberOfEmployees; ++i) {
        employee_s_t emp;
        std::cout << "Введіть дані для службовця " << (i + 1) << ":\n";

        std::cout << "Ім'я: ";
        std::getline(std::cin, emp.name); // Зчитуємо ім'я

        std::cout << "Вік: ";
        while (true) {
            std::cin >> emp.age;

            // Перевірка на вік
            if (emp.age < 18) {
                std::cout << "Вік не може бути менше 18. Введіть вік знову: ";
            } else {
                break; // Виходимо з циклу, якщо вік коректний
            }
        }

        // Очищення буфера після вводу віку
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Посада: ";
        std::getline(std::cin, emp.position); // Зчитуємо посаду

        employees.push_back(emp); // Додавання службовця до вектора
    }
}



void Employee::displayEmployeeData() const {
    if (employees.empty()) {
        std::cout << "Немає даних про службовців.\n";
        return;
    }

    std::cout << "\nДані службовців:\n";
    for (size_t i = 0; i < employees.size(); ++i) {
        std::cout << "Службовець " << (i + 1) << ": "
                  << "Ім'я: " << employees[i].name
                  << ", Вік: " << employees[i].age
                  << ", Посада: " << employees[i].position << "\n";
    }
}

void Employee::updateEmployeeByNumber() {
    int empNumber;
    while (true) {
        std::cout << "Введіть номер службовця для оновлення: ";
        std::cin >> empNumber;

        if (empNumber < 1 || empNumber > employees.size()) {
            std::cout << "Неправильний номер службовця. Спробуйте ще раз.\n";
        } else {
            break;
        }
    }

    employee_s_t& emp = employees[empNumber - 1];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Оновлення даних для службовця " << empNumber << ":\n";

    std::cout << "Нові ім'я (залиште порожнім для пропуску): ";
    std::string newName;
    std::getline(std::cin, newName);
    if (!newName.empty()) {
        emp.name = newName;
    }

    std::cout << "Новий вік (залиште порожнім для пропуску): ";
    std::string newAgeInput;
    std::getline(std::cin, newAgeInput);
    if (!newAgeInput.empty()) {
        int newAge = std::stoi(newAgeInput);
        if (newAge < 18) {
            std::cout << "Вік не може бути менше 18. Оновлення не виконано.\n";
        } else {
            emp.age = newAge;
        }
    }

    std::cout << "Нова посада (залиште порожнім для пропуску): ";
    std::string newPosition;
    std::getline(std::cin, newPosition);
    if (!newPosition.empty()) {
        emp.position = newPosition;
    }

    std::cout << "Дані службовця оновлено.\n";
}

void Employee::deleteEmployee() {
    int number;
    while (true) {
        std::cout << "Введіть номер службовця для видалення (1-" << employees.size() << "): ";
        std::cin >> number;

        if (number < 1 || number > employees.size()) {
            std::cout << "Некоректний номер. Спробуйте ще раз.\n";
        } else {
            break;
        }
    }

    employees.erase(employees.begin() + (number - 1));
    std::cout << "Службовець " << number << " успішно видалений.\n";
}

void Employee::swapEmployees() {
    int index1, index2;
    while (true) {
        std::cout << "Введіть номер першого службовця для обміну: ";
        std::cin >> index1;
        std::cout << "Введіть номер другого службовця для обміну: ";
        std::cin >> index2;

        if (index1 < 1 || index1 > employees.size() || index2 < 1 || index2 > employees.size()) {
            std::cout << "Некоректні номери. Спробуйте ще раз.\n";
        } else {
            break;
        }
    }

    std::swap(employees[index1 - 1], employees[index2 - 1]);
    std::cout << "Службовців " << index1 << " та " << index2 << " успішно обміняно місцями.\n";
}

void Employee::insertEmployeeAtPosition() {
    int position;
    while (true) {
        std::cout << "Введіть номер службовця після якого потрібно додати нового (0-" << employees.size() << "): ";
        std::cin >> position;

        if (position < 0 || position > employees.size()) {
            std::cout << "Некоректний номер. Спробуйте ще раз.\n";
        } else {
            break;
        }
    }

    employee_s_t emp;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введіть дані для нового службовця:\n";

    std::cout << "Ім'я: ";
    std::getline(std::cin, emp.name);

    std::cout << "Вік: ";
    std::cin >> emp.age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Посада: ";
    std::getline(std::cin, emp.position);

    employees.insert(employees.begin() + position, emp);
    std::cout << "Новий службовець успішно доданий після службовця " << position + 1 << ".\n";
}

void Employee::clearEmployees() {
    employees.clear();
    std::cout << "Всі дані службовців успішно очищені.\n";
}

