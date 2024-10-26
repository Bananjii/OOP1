#include "employee.h"

int main() {
    Employee emp;
    
    emp.displayEmployeeData(); // Вивід вже існуючих службовців

    // Можливість введення нових службовців
    emp.inputEmployeeData();
    emp.displayEmployeeData();

    // Оновлення даних для службовця
    emp.updateEmployeeByNumber();
    emp.displayEmployeeData();

    // Пошук службовця
    emp.searchEmployee();

    return 0;
}
