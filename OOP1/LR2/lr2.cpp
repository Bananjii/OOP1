#include <iostream>
#include <cmath>

double First(double a, double x) {
    return cbrt(pow(x, 2) + abs(a));
}

double Second(double a, double b, double x) {
    return pow(sin(a * x), 2) * pow(cos(b * x), 2);
}

double Third(double a, double b, double x) {
    return abs(a + x + b);
}

void calculateResult(double a, double b, double x) {
    double result;

    if (x <= 1) {
        result = First(a, x);
    } else if (x > 1 && x <= 3) {
        result = Second(a, b, x);
    } else {
        result = Third(a, b, x);
    }

    std::cout << "Відповідь: " << result << std::endl;
}

int main() {
    double a = 3;
    double b = 5;
    double x;
    
    std::cout << "Введіть число x: ";
    std::cin >> x;

    calculateResult(a, b, x);

    return 0;
}