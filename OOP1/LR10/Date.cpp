#include "Date.h"
#include <iostream>
#include <cmath>
#include <ctime>

Date::Date() : day(1), month(1), year(1970) {} // Конструктор за замовчуванням

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {} // Конструктор з параметрами

Date::~Date() {} // Деструктор

Date Date::getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return Date(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
}

bool Date::operator<=(const Date& other) const {
    Date current = getCurrentDate();
    int diff1 = abs(this->daysDifference(current));
    int diff2 = abs(other.daysDifference(current));
    return diff1 <= diff2;
}

bool Date::operator==(const Date& other) {
    this->reduceDays(1);
    return this->daysDifference(other) == 0;
}

void Date::reduceDays(int days) {
    while (days > 0) {
        if (this->day > days) {
            this->day -= days;
            days = 0; // Всі дні зменшено
        } else {
            days -= this->day; // Витрачаємо дні на поточний місяць
            this->month--;

            if (this->month <= 0) {
                this->month = 12;
                this->year--;
            }

            this->day = daysInMonth(this->month, this->year); // Встановлюємо на останній день попереднього місяця
        }
    }
}

int Date::daysDifference(const Date& other) const {
    // Зарахування днів
    int totalDays1 = year * 365 + day;
    int totalDays2 = other.year * 365 + other.day;

    // Додавання днів для місяців
    for (int m = 1; m < month; ++m) {
        totalDays1 += daysInMonth(m, year);
    }
    for (int m = 1; m < other.month; ++m) {
        totalDays2 += daysInMonth(m, other.year);
    }

    // Додавання днів високосних років
    for (int y = 1; y < year; ++y) {
        if (Date(y, 2, 29).isLeapYear()) {
            totalDays1++;
        }
    }
    for (int y = 1; y < other.year; ++y) {
        if (Date(y, 2, 29).isLeapYear()) {
            totalDays2++;
        }
    }

    return totalDays1 - totalDays2;
}

void Date::display() const {
    std::cout << day << "/" << month << "/" << year << std::endl;
}

// Метод для перевірки, чи рік високосний
bool Date::isLeapYear() const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Метод для отримання кількості днів у місяці
int Date::daysInMonth(int month, int year) const {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear() ? 29 : 28; // Високосний рік для лютого
        default: return 0; // Неправильний місяць
    }
}
