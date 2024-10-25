#include <iostream>
#include <math.h>  

int main() {
    double a = 3;
    double b = 5;
    double x;
    std::cout << "Введіть число x: ";
    std::cin >> x;
    double y;
    std::cout << "Введіть число y: ";
    std::cin >> y;
    double i;

    // Використання умовного розгалуження
    if (x<=1) {
        i = cbrt(pow(x,2)+abs(2));
        std::cout << "Відповідь:" << i;
    } else if (x>1 && x<=3) {
        i = pow(sin(a*x),2)*pow(cos(b*x),2);
        std::cout << "Відповідь:" << i;
    } else {
        i = abs(a+x+b);
        std::cout << "Відповідь:" << i;
    }

    return 0;
}
