#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include <string>

struct employee_s_t {
    std::string name;
    int age;
    std::string position;
};

class Employee {
private:
    std::vector<employee_s_t> employees; // Використання вектора для зберігання службовців

public:
    Employee(); // Конструктор
    ~Employee(); // Деструктор

    void inputEmployeeData();
    void displayEmployeeData() const;
    void updateEmployeeByNumber();
    void deleteEmployee();
    void clearEmployees();
};

#endif // EMPLOYEE_H
