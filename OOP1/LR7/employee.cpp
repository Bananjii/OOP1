#include "employee.h"

Employee::Employee() {}

Employee::~Employee() {}

void Employee::inputEmployeeData() {
    int numberOfEmployees;
    std::cout << "Введіть кількість службовців для додавання: ";
    std::cin >> numberOfEmployees;

    for (int i = 0; i < numberOfEmployees; ++i) {
        employee_s_t emp;
        std::cout << "Введіть дані для службовця " << (i + 1) << ":\n";

        std::cout << "Ім'я: ";
        std::cin >> emp.name;

        std::cout << "Вік: ";
        std::cin >> emp.age;

        std::cout << "Посада: ";
        std::cin >> emp.position;

        employees.push_back(emp); // Додавання службовця до вектора
    }
}

void Employee::displayEmployeeData() const {
    if (employees.empty()) {
        return; // Якщо немає службовців, нічого не виводимо
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
    int number;
    std::cout << "Введіть номер службовця для оновлення (1-" << employees.size() << "): ";
    std::cin >> number;

    // Перевірка номера службовця
    if (number < 1 || number > employees.size()) {
        std::cout << "Некоректний номер.\n";
        return;
    }

    employee_s_t emp;
    int index = number - 1; // Зменшення на 1 для використання як індексу в векторі

    std::cout << "Оновлення даних службовця " << number << ":\n";
    
    std::cout << "Ім'я: ";
    std::cin >> emp.name;

    std::cout << "Вік: ";
    std::cin >> emp.age;

    std::cout << "Посада: ";
    std::cin >> emp.position;

    employees[index] = emp; // Оновлення даних службовця
}

void Employee::deleteEmployee() {
    int number;
    std::cout << "Введіть номер службовця для видалення (1-" << employees.size() << "): ";
    std::cin >> number;

    // Перевірка номера службовця
    if (number < 1 || number > employees.size()) {
        std::cout << "Некоректний номер.\n";
        return;
    }

    // Видалення службовця за номером
    employees.erase(employees.begin() + (number - 1)); 
    std::cout << "Службовець " << number << " успішно видалений.\n";
}

void Employee::clearEmployees() {
    employees.clear(); // Очищення вектора
    std::cout << "Всі дані службовців успішно очищені.\n";
}
