#include "employee.h"
#include <iostream>
#include <limits>

Employee::Employee() : count(0) {
    initializeEmployees(); // Ініціалізація службовців
}

Employee::~Employee() {}

void Employee::initializeEmployees() {
    employees[0] = {"Thomas Shelby", 30, "CEO"};
    employees[1] = {"Arthur Shelby", 25, "Manager"};
    employees[2] = {"Michael Shelby", 40, "Badboy"};
    count = 3; // Встановлення фактичної кількості службовців
}

void Employee::inputEmployeeData() {
    for (int i = count; i < SIZE; ++i) {
        std::cout << "Введіть дані для службовця " << (i + 1) << ":\n";
        employee_s_t emp;
        
        std::cout << "Ім'я: ";
        std::getline(std::cin, emp.name); // Зчитуємо повний рядок для імені

        // Перевірка віку з повторним введенням
        while (true) {
            std::cout << "Вік: ";
            if (!(std::cin >> emp.age)) {
                std::cout << "Невірне значення. Введіть числове значення віку.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (emp.age < 18 || emp.age > 65) {
                std::cout << "Невірний вік, введіть ще раз.\n";
            } else {
                break;
            }
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистити залишок буфера після введення числа
        std::cout << "Посада: ";
        std::getline(std::cin, emp.position); // Зчитуємо повний рядок для посади

        validateEmployeeData(emp);

        employees[i] = emp;
        count++;
    }
}

void Employee::displayEmployeeData() const {
    std::cout << "\nДані службовців:\n";
    for (int i = 0; i < count; ++i) {
        std::cout << "Службовець " << (i + 1) << ": "
                  << "Ім'я: " << employees[i].name
                  << ", Вік: " << employees[i].age
                  << ", Посада: " << employees[i].position << "\n";
    }
}

void Employee::updateEmployeeByNumber() {
    int number;
    std::cout << "Введіть номер службовця для оновлення (1-" << count << "): ";
    std::cin >> number;

    if (number < 1 || number > count) {
        std::cout << "Некоректний номер.\n";
        return;
    }

    employee_s_t emp;
    int index = number - 1;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистити залишок буфера після введення числа
    std::cout << "Оновлення даних службовця " << number << ":\n";
    
    std::cout << "Ім'я: ";
    std::getline(std::cin, emp.name); // Зчитуємо повний рядок для імені

    while (true) {
        std::cout << "Вік: ";
        if (!(std::cin >> emp.age)) {
            std::cout << "Невірне значення. Введіть числове значення віку.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (emp.age < 18 || emp.age > 65) {
            std::cout << "Невірний вік, введіть ще раз.\n";
        } else {
            break;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистити залишок буфера після введення числа
    std::cout << "Посада: ";
    std::getline(std::cin, emp.position); // Зчитуємо повний рядок для посади

    validateEmployeeData(emp);

    employees[index] = emp;
}

void Employee::validateEmployeeData(employee_s_t& emp) const {
    if (emp.name.empty()) {
        std::cout << "Некоректне ім'я. Ім'я не повинно бути пустим.\n";
    }
}

void Employee::searchEmployee() {
    int choice;
    std::cout << "Шукати за:\n1. Віком\n2. Посадою\nВведіть вибір: ";
    std::cin >> choice;

    if (choice == 1) {
        int age;
        std::cout << "Введіть вік для пошуку: ";
        std::cin >> age;

        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (employees[i].age == age) {
                std::cout << "Службовець " << (i + 1) << ": "
                          << "Ім'я: " << employees[i].name
                          << ", Вік: " << employees[i].age
                          << ", Посада: " << employees[i].position << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "Немає жодного працівника з таким віком.\n";
        }
    } else if (choice == 2) {
        std::string position;
        std::cout << "Введіть посаду для пошуку: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, position);

        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (employees[i].position == position) {
                std::cout << "Службовець " << (i + 1) << ": "
                          << "Ім'я: " << employees[i].name
                          << ", Вік: " << employees[i].age
                          << ", Посада: " << employees[i].position << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "Немає жодного працівника з такою посадою.\n";
        }
    } else {
        std::cout << "Некоректний вибір.\n";
    }
}
