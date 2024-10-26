#include "employee.h"

int main() {
    Employee emp;

    emp.inputEmployeeData();
    emp.displayEmployeeData();

    emp.updateEmployeeByNumber();
    emp.displayEmployeeData();

    emp.deleteEmployee();
    emp.displayEmployeeData();

    emp.swapEmployees(); // Виклик обміну службовців місцями
    emp.displayEmployeeData();

    emp.insertEmployeeAtPosition(); // Виклик вставки службовця після певного номера
    emp.displayEmployeeData();

    emp.clearEmployees();
    emp.displayEmployeeData();

    return 0;
}
