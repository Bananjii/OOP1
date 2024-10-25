#include "employee.h"

Employee::Employee() : count(0) {
    initializeEmployees(); // Ініціалізація службовців
}

Employee::~Employee() {}

void Employee::initializeEmployees() {
    employees[0] = {"Іван Петров", 30, "Менеджер"};
    employees[1] = {"Олена Сидоренко", 25, "Аналітик"};
    employees[2] = {"Степан Іванов", 40, "Розробник"};
    count = 3; // Встановлення фактичної кількості службовців
}

void Employee::inputEmployeeData() {
    for (int i = count; i < SIZE; ++i) {
        std::cout << "Введіть дані для службовця " << (i + 1) << ":\n";
        employee_s_t emp;
        
        std::cout << "Ім'я: ";
        std::cin >> emp.name;

        // Перевірка віку
        do {
            std::cout << "Вік: ";
            std::cin >> emp.age;
            if (emp.age < 18 || emp.age > 65) {
                std::cout << "Невірний вік, введіть ще раз.\n";
            }
        } while (emp.age < 18 || emp.age > 65);

        std::cout << "Посада: ";
        std::cin >> emp.position;

        // Перевірка валідності даних
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

    // Перевірка номера службовця
    if (number < 1 || number > count) {
        std::cout << "Некоректний номер.\n";
        return;
    }

    employee_s_t emp;
    int index = number - 1; // Зменшення на 1 для використання як індексу в масиві

    std::cout << "Оновлення даних службовця " << number << ":\n";
    
    std::cout << "Ім'я: ";
    std::cin >> emp.name;

    // Перевірка віку
    do {
        std::cout << "Вік: ";
        std::cin >> emp.age;
        if (emp.age < 18 || emp.age > 65) {
            std::cout << "Невірний вік, введіть ще раз.\n";
        }
    } while (emp.age < 18 || emp.age > 65);

    std::cout << "Посада: ";
    std::cin >> emp.position;

    // Перевірка валідності даних
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

        std::cout << "Результати пошуку:\n";
        for (int i = 0; i < count; ++i) {
            if (employees[i].age == age) {
                std::cout << "Службовець " << (i + 1) << ": "
                          << "Ім'я: " << employees[i].name
                          << ", Вік: " << employees[i].age
                          << ", Посада: " << employees[i].position << "\n";
            }
        }
    } else if (choice == 2) {
        std::string position;
        std::cout << "Введіть посаду для пошуку: ";
        std::cin >> position;

        std::cout << "Результати пошуку:\n";
        for (int i = 0; i < count; ++i) {
            if (employees[i].position == position) {
                std::cout << "Службовець " << (i + 1) << ": "
                          << "Ім'я: " << employees[i].name
                          << ", Вік: " << employees[i].age
                          << ", Посада: " << employees[i].position << "\n";
            }
        }
    } else {
        std::cout << "Некоректний вибір.\n";
    }
}
