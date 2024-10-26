#include <iostream>
#include <algorithm>
#include "Date.h"

int main() {
    // Масив дат
    Date dates[] = {
        Date(12, 5, 2023),
        Date(20, 10, 2022),
        Date(1, 1, 2024),
        Date(15, 7, 2021)
    };

    int n = sizeof(dates) / sizeof(dates[0]);

    // Виведення початкових дат
    std::cout << "Початкові дати:\n";
    for (int i = 0; i < n; ++i) {
        dates[i].display();
    }

    // Сортування за абсолютною різницею від поточної дати
    std::sort(dates, dates + n, [](const Date& d1, const Date& d2) {
        return d1 <= d2;
    });

    // Виведення відсортованих дат
    std::cout << "\nВідсортовані дати за різницею від поточної дати:\n";
    for (int i = 0; i < n; ++i) {
        dates[i].display();
    }

    // Зменшення кожної дати на 5 днів
    int reduceBy = 5;
    for (int i = 0; i < n; ++i) {
        dates[i].reduceDays(reduceBy);
    }

    // Виведення дат після зменшення
    std::cout << "\nЗменшення кожної дати на " << reduceBy << " днів:\n";
    for (int i = 0; i < n; ++i) {
        dates[i].display();
    }

    return 0;
}
