#include <iostream>
#include <vector>
#include "Vantazhni.h"
#include "Vantazhni.cpp"
#include "Pasazhyrski.h"
#include "Pasazhyrski.cpp"
#include "Perevezennya.h"
#include "Perevezennya.cpp"

int main() {
    std::vector<Perevezennya*> perevezennya;
    int totalPassengers = 0;
    double totalWeight = 0.0;
    int vanCount = 0;

    int vantazhniCount = 0;
    int pasazhyrskiCount = 0;

    // Запитуємо кількість вантажних та пасажирських перевезень
    std::cout << "Скільки вантажних перевезень ви хочете додати? ";
    std::cin >> vantazhniCount;

    std::cout << "Скільки пасажирських перевезень ви хочете додати? ";
    std::cin >> pasazhyrskiCount;

    // Введення даних для вантажних перевезень
    for (int i = 0; i < vantazhniCount; i++) {
        std::cout << "\nВведення даних для вантажного перевезення №" << (i + 1) << ":\n";
        Vantazhni* v = new Vantazhni();
        v->input();
        perevezennya.push_back(v);
    }

    // Введення даних для пасажирських перевезень
    for (int i = 0; i < pasazhyrskiCount; i++) {
        std::cout << "\nВведення даних для пасажирського перевезення №" << (i + 1) << ":\n";
        Pasazhyrski* p = new Pasazhyrski();
        p->input();
        perevezennya.push_back(p);
    }

    // Виведення даних та підрахунок результатів
    for (const auto& p : perevezennya) {
        p->display();
        std::cout << "---------------------\n";

        // Підрахунок кількості пасажирів та середньої ваги вантажу
        if (dynamic_cast<Vantazhni*>(p)) {
            totalWeight += dynamic_cast<Vantazhni*>(p)->getWeight();
            vanCount++;
        } else if (dynamic_cast<Pasazhyrski*>(p)) {
            totalPassengers += dynamic_cast<Pasazhyrski*>(p)->getPassengers();
        }
    }

    // Обчислення середньої ваги вантажу
    if (vanCount > 0) {
        double avgWeight = totalWeight / vanCount;
        std::cout << "Середня вага вантажу: " << avgWeight << " тонн\n";
    }

    // Виведення загальної кількості пасажирів
    std::cout << "Загальна кількість пасажирів: " << totalPassengers << "\n";

    // Очищення пам'яті
    for (auto& p : perevezennya) {
        delete p;
    }

    return 0;
}