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
    std::vector<employee_s_t> employees;

public:
    Employee();
    ~Employee();

    void inputEmployeeData();
    void displayEmployeeData() const;
    void updateEmployeeByNumber();
    void deleteEmployee();
    void clearEmployees();
    void swapEmployees(); // Метод для обміну службовців
    void insertEmployeeAtPosition(); // Метод для вставки службовця в позицію
};

#endif // EMPLOYEE_H
