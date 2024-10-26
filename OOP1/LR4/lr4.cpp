#include <iostream>
#include <string>
#include <Windows.h>
#include <limits> // Для numeric_limits

using namespace std;

class Employee {
private:
    string name;
    int age;
    string position;

public:
    // Конструктор для ініціалізації даних
    Employee(const string& empName, int empAge, const string& empPosition) 
        : name(empName), age(empAge), position(empPosition) {}

    // Конструктор за замовчуванням
    Employee() : name(""), age(0), position("") {}

    // Метод для введення даних з перевіркою
    void inputEmployeeData() {
        // Введення імені з перевіркою на порожнє значення
        while (true) {
            cout << "Введіть ім'я: ";
            getline(cin, name);
            if (name.empty()) {
                cout << "Поле 'Ім'я' не може бути порожнім. Повторіть ввод.\n";
            } else {
                break;
            }
        }

        // Введення віку з перевіркою на діапазон 18-65
        while (true) {
            cout << "Введіть вік: ";
            cin >> age;
            if (cin.fail() || age < 18 || age > 65) {
                cout << "Вік повинен бути в діапазоні від 18 до 65. Повторіть ввод.\n";
                
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Забираємо залишок нової лінії в потоці
                break;
            }
        }

        // Введення посади з перевіркою на порожнє значення
        while (true) {
            cout << "Введіть посаду: ";
            getline(cin, position);
            if (position.empty()) {
                cout << "Поле 'Посада' не може бути порожнім. Повторіть ввод.\n";
            } else {
                break;
            }
        }
    }

    // Метод для виведення даних
    void printEmployeeData() const {
        cout << "Ім'я: " << name << "\nВік: " << age << "\nПосада: " << position << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // Перший службовець з ініціалізацією даних при створенні
    Employee employee1("Олена", 30, "Менеджер");

    // Другий службовець з введенням даних через метод
    Employee employee2;
    cout << "Введіть дані для другого службовця:\n";
    employee2.inputEmployeeData();

    // Третій службовець з ініціалізацією даних при створенні
    Employee employee3("Іван", 45, "Директор");

    // Виведення даних про службовців
    cout << "\nПерший службовець:\n";
    employee1.printEmployeeData();

    cout << "\nДругий службовець:\n";
    employee2.printEmployeeData();

    cout << "\nТретій службовець:\n";
    employee3.printEmployeeData();

    return 0;
}