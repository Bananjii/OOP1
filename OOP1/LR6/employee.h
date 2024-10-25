#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <array>
#include <iostream>
#include <string>

const int SIZE = 5; // Кількість службовців

struct employee_s_t {
    std::string name;
    int age;
    std::string position;
};

class Employee {
private:
    std::array<employee_s_t, SIZE> employees;
    int count; // Фактична кількість службовців

public:
    Employee();
    ~Employee();
    
    void initializeEmployees(); // Метод для ініціалізації службовців
    void inputEmployeeData();
    void displayEmployeeData() const;
    void updateEmployeeByNumber();
    void validateEmployeeData(employee_s_t& emp) const;
    void searchEmployee();
};

#endif // EMPLOYEE_H
