#include <iostream>
#include <cmath>

using namespace std;

double calculate(double a, double b, double x) {
    return (pow(log(b * x), 4) + 0.85) / cbrt(a + b * pow(x, 3));
}

void Values(double x1, double x2, double h, double a, double b, double &sum, int &count) {
    for (double x = x1; x <= x2; x += h) {
        double y = calculate(a, b, x);
        
        if (y > 1) {
            sum += y;
            count++;
        }
    }
}

int main() {
    double x1 = 0.4;
    double x2 = 6.8;
    double h = 0.8;
    double a = 46;
    double b = 1.85;

    double sum = 0;
    int count = 0;

    Values(x1, x2, h, a, b, sum, count);

    cout << "Сума значень y > 1: " << sum << endl;
    cout << "Кількість значень y > 1: " << count << endl;

    return 0;
}
