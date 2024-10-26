#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int age;
    string position;

public:
    // Конструктор за замовчуванням і з параметрами
    Employee(string empName = "Unknown", int empAge = 18, string empPosition = "Unknown")
        : name(empName), age(empAge), position(empPosition) {
        if (age < 18) {
            cout << "Помилка. Вік не може бути меншим 18-ти. Встановлено за замовчуванням 18 років." << endl;
            age = 18;
        }
    }

    // Метод для введення даних
    void input() {
        cout << "Введіть ім'я: ";
        getline(cin, name);
        cout << "Введіть вік: ";
        cin >> age;
        cin.ignore(); // Очищуємо буфер після введення числа
        cout << "Введіть посаду: ";
        cin >> position;
        if (age < 18) {
            cout << "Помилка. Вік не може бути меншим 18-ти. Встановлено за замовчуванням 18 років." << endl;
            age = 18;
        }
    }

    // Метод для виведення даних
    void display() const {
        cout << "Ім'я: " << name << ", Вік: " << age << ", Посада: " << position << endl;
    }

    // Геттери для критеріїв
    int getAge() const {
        return age;
    }

    string getPosition() const {
        return position;
    }
};

// Функція для виведення працівників за віковим критерієм
void displayByAge(const vector<Employee>& employees, int ageCriteria) {
    bool found = false;
    for (const auto& emp : employees) {
        if (emp.getAge() > ageCriteria) {
            emp.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Не знайдено працівників, вік яких більший за " << ageCriteria << " років." << endl;
    }
}

// Функція для виведення працівників за посадою
void displayByPosition(const vector<Employee>& employees, const string& positionCriteria) {
    bool found = false;
    for (const auto& emp : employees) {
        if (emp.getPosition() == positionCriteria) {
            emp.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Не знайдено працівників з посадою: " << positionCriteria << "." << endl;
    }
}

int main() {
    // Створюємо кілька екземплярів класу
    Employee emp1("John Doe", 25, "Manager");
    Employee emp2("Jane Smith", 30, "Engineer");
    Employee emp3; // Використання конструктора за замовчуванням

    // Виведення даних про працівників
    emp1.display();
    emp2.display();
    emp3.input(); // Введення даних для третього працівника
    emp3.display();

    // Додавання працівників у список
    vector<Employee> employees = {emp1, emp2, emp3};

    // Вибір фільтру
    int choice;
    cout << "Фільтрувати за: 1 - Віком, 2 - Посадою. Виберіть: ";
    cin >> choice;
    cin.ignore();  // Очищуємо буфер після введення числа

    if (choice == 1) {
        // Фільтрація за віком
        int ageCriteria;
        cout << "Введіть вік для фільтру: ";
        cin >> ageCriteria;
        displayByAge(employees, ageCriteria);
    } else if (choice == 2) {
        // Фільтрація за посадою
        string positionCriteria;
        cout << "Введіть назву посади для фільтру: ";
        cin >> positionCriteria;
        displayByPosition(employees, positionCriteria);
    } else {
        cout << "Невірний вибір!" << endl;
    }

    return 0;
}
