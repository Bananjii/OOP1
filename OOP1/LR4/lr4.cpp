#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void inputEmployeeData(string& name, int& age, string& position) {
    cout << "Введіть ім'я: ";
    getline(cin, name);
    cout << "Введіть вік: ";
    cin >> age;
    cin.ignore();
    cout << "Введіть посаду: ";
    getline(cin, position);
}

void printEmployeeData(const string& name, int age, const string& position) {
    cout << "Ім'я: " << name << "\nВік: " << age << "\nПосада: " << position << endl;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    // Дані для першого службовця
    string name1 = "Олена";
    int age1 = 30;
    string position1 = "Менеджер";

    // Дані для другого службовця
    string name2, position2;
    int age2;

    cout << "Введіть дані для другого службовця:\n";
    inputEmployeeData(name2, age2, position2);

    // Дані для третього службовця
    string name3 = "Іван";
    int age3 = 45;
    string position3 = "Директор";

    // Виведення даних про службовців
    cout << "\nПерший службовець:\n";
    printEmployeeData(name1, age1, position1);

    cout << "\nДругий службовець:\n";
    printEmployeeData(name2, age2, position2);

    cout << "\nТретій службовець:\n";
    printEmployeeData(name3, age3, position3);

    return 0;
}
