#include <iostream>
#include <math.h>  // Для використання математичних функцій

using namespace std;

int main() {
    // Введення початкових та кінцевих значень
    double x1 = 0.4;
    double x2 = 6.8;
    double h = 0.8;
    double a = 46;
    double b = 1.85;

    // Змінні для підрахунку суми та кількості y > 1
    double sum = 0;
    int count = 0;

    // Цикл для обчислення значень y для кожного x в інтервалі
    for (double x = x1; x <= x2; x += h) {
        double y = (pow(log(b*x),4)+0.85)/cbrt(a+b*pow(x,3));  // Обчислення y

        if (y > 1) {  // Перевіряємо, чи y більше за 1
            sum += y;
            count++;
        }
    }

    // Виведення результатів
    cout << "Сума значень y > 1: " << sum << endl;
    cout << "Кількість значень y > 1: " << count << endl;

    return 0;
}
