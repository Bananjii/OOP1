#include <iostream>
#include <vector>
#include "Vantazhni.h"
#include "Pasazhyrski.h"
#include "Perevezennya.h"

int main() {
    std::vector<Perevezennya*> perevezennya;
    int totalPassengers = 0;
    double totalWeight = 0.0;
    double totalCost = 0.0; // Змінна для накопичення загальної вартості
    int totalDuration = 0; // Змінна для накопичення загальної тривалості
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

        // Накопичуємо загальну вартість і тривалість
        totalCost += p->getCost();
        totalDuration += p->getDuration();
    }

    // Обчислення середньої ваги вантажу
    if (vanCount > 0) {
        double avgWeight = totalWeight / vanCount;
        std::cout << "Середня вага вантажу: " << avgWeight << " тонн\n";
    }

    // Виведення загальної кількості пасажирів
    std::cout << "Загальна кількість пасажирів: " << totalPassengers << "\n";

    // Обчислення та виведення середньої вартості та тривалості
    int totalCount = vantazhniCount + pasazhyrskiCount;
    if (totalCount > 0) {
        double avgCost = totalCost / totalCount;
        double avgDuration = static_cast<double>(totalDuration) / totalCount;

        std::cout << "Середня вартість перевезення: " << avgCost << "\n";
        std::cout << "Середня тривалість перевезення: " << avgDuration << " годин\n";
    }

    // Очищення пам'яті
    for (auto& p : perevezennya) {
        delete p;
    }

    return 0;
}
