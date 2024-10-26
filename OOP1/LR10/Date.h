#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(); // Конструктор за замовчуванням
    Date(int d, int m, int y); // Конструктор з параметрами
    ~Date(); // Деструктор

    // Перевантаження операторів
    bool operator<=(const Date& other) const; // Перевантаження оператора <=
    bool operator==(const Date& other); // Перевантаження оператора == для зменшення на 1 день

    void reduceDays(int days); // Метод для зменшення дати на кількість днів
    int daysDifference(const Date& other) const; // Метод для обчислення різниці між датами

    void display() const; // Метод для виведення дати

    static Date getCurrentDate(); // Метод для отримання поточної дати

private:
    bool isLeapYear() const; // Метод для перевірки, чи рік високосний
    int daysInMonth(int month, int year) const; // Метод для отримання кількості днів у місяці
};

#endif
