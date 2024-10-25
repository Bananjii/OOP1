#include "employee.h"
#include "employee.cpp"

int main() {
    Employee emp;

    emp.inputEmployeeData(); // Введення даних службовців
    emp.displayEmployeeData();

    // Оновлення даних для службовця
    emp.updateEmployeeByNumber();
    emp.displayEmployeeData();

    // Видалення службовця
    emp.deleteEmployee();
    emp.displayEmployeeData();

    // Очищення даних
    emp.clearEmployees();
    emp.displayEmployeeData();

    return 0; // Завершення програми
}
