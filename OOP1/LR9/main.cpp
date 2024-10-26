#include <iostream>
#include <vector>
#include "Vantazhni.h"
#include "Pasazhyrski.h"
#include "Perevezennya.h"
#include "display.h"

int main() {
    std::vector<Perevezennya*> perevezennya;
    int vantazhniCount = 0, pasazhyrskiCount = 0;

    std::cout << "Скільки вантажних перевезень ви хочете додати? ";
    std::cin >> vantazhniCount;

    std::cout << "Скільки пасажирських перевезень ви хочете додати? ";
    std::cin >> pasazhyrskiCount;

    // Введення вантажних перевезень
    for (int i = 0; i < vantazhniCount; i++) {
        std::cout << "\nВведення даних для вантажного перевезення №" << (i + 1) << ":\n";
        Vantazhni* v = new Vantazhni();
        v->input();
        perevezennya.push_back(v);
    }

    // Введення пасажирських перевезень
    for (int i = 0; i < pasazhyrskiCount; i++) {
        std::cout << "\nВведення даних для пасажирського перевезення №" << (i + 1) << ":\n";
        Pasazhyrski* p = new Pasazhyrski();
        p->input();
        perevezennya.push_back(p);
    }

    Display display;

    // Виведення даних
    for (const auto& p : perevezennya) {
        display.show(*p);

        if (auto* v = dynamic_cast<Vantazhni*>(p)) {
            display.showWeight(*v);
        } else if (auto* pas = dynamic_cast<Pasazhyrski*>(p)) {
            display.showPassengers(*pas);
        }

        std::cout << "---------------------\n";
    }

    // Обчислення середньої ваги для вантажів
    double totalWeight = 0.0;
    int totalVantazhni = 0;

    // Обчислення середньої кількості пасажирів для пасажирських перевезень
    int totalPassengers = 0;
    int totalPasazhyrski = 0;

    // Обчислення загальної вартості та часу для обох видів перевезень
    double totalCost = 0.0;
    double totalDuration = 0.0;

    for (const auto& p : perevezennya) {
        totalCost += p->getCost();
        totalDuration += p->getDuration();

        if (auto* v = dynamic_cast<Vantazhni*>(p)) {
            totalWeight += v->getWeight(); // Використовуйте геттер
            totalVantazhni++;
        } else if (auto* pas = dynamic_cast<Pasazhyrski*>(p)) {
            totalPassengers += pas->getPassengers(); // Використовуйте геттер
            totalPasazhyrski++;
        }
    }

    // Виведення середньої ваги
    if (totalVantazhni > 0) {
        std::cout << "Середня вага вантажу: " << (totalWeight / totalVantazhni) << " тонн\n";
    } else {
        std::cout << "Не введено вантажних перевезень.\n";
    }

    // Виведення середньої кількості пасажирів
    if (totalPasazhyrski > 0) {
        std::cout << "Середня кількість пасажирів: " << (totalPassengers / totalPasazhyrski) << "\n";
    } else {
        std::cout << "Не введено пасажирських перевезень.\n";
    }

    // Виведення загальної середньої вартості
    if (!perevezennya.empty()) {
        std::cout << "Загальна середня вартість: " << (totalCost / perevezennya.size()) << "\n";
    } else {
        std::cout << "Не введено жодного перевезення.\n";
    }

    // Виведення загальної середньої тривалості
    if (!perevezennya.empty()) {
        std::cout << "Загальна середня тривалість: " << (totalDuration / perevezennya.size()) << " годин\n";
    } else {
        std::cout << "Не введено жодного перевезення.\n";
    }

    // Очищення пам'яті
    for (auto p : perevezennya) {
        delete p;
    }

    return 0;
}