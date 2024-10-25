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
    this->day -= days;
    // Умовна корекція дати (простий варіант, не враховує всі деталі)
    if (this->day <= 0) {
        this->month--;
        if (this->month <= 0) {
            this->month = 12;
            this->year--;
        }
        this->day += 30; // Спрощено: вважаємо, що кожен місяць має 30 днів
    }
}

int Date::daysDifference(const Date& other) const {
    // Спрощене обчислення різниці між датами (не враховує високосні роки)
    return ((year - other.year) * 365) + ((month - other.month) * 30) + (day - other.day);
}

void Date::display() const {
    std::cout << day << "/" << month << "/" << year << std::endl;
}
