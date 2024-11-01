#include <iostream>
#include <vector>
#include "Vantazhni.h"
#include "Pasazhyrski.h"
#include "Perevezennya.h"

int main() {
    std::vector<Perevezennya*> perevezennya;
    int totalPassengers = 0;
    double totalWeight = 0.0;
    double totalCost = 0.0;
    int totalDuration = 0;
    int vanCount = 0;

    int vantazhniCount = 0;
    int pasazhyrskiCount = 0;

    // Запитуємо кількість вантажних перевезень з перевіркою
    while (true) {
        std::cout << "Скільки вантажних перевезень ви хочете додати? ";
        std::cin >> vantazhniCount;
        if (std::cin.fail() || vantazhniCount < 1) {
            std::cout << "Кількість перевезень повинна бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Запитуємо кількість пасажирських перевезень з перевіркою
    while (true) {
        std::cout << "Скільки пасажирських перевезень ви хочете додати? ";
        std::cin >> pasazhyrskiCount;
        if (std::cin.fail() || pasazhyrskiCount < 1) {
            std::cout << "Кількість перевезень повинна бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

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

        if (dynamic_cast<Vantazhni*>(p)) {
            totalWeight += dynamic_cast<Vantazhni*>(p)->getWeight();
            vanCount++;
        } else if (dynamic_cast<Pasazhyrski*>(p)) {
            totalPassengers += dynamic_cast<Pasazhyrski*>(p)->getPassengers();
        }

        totalCost += p->getCost();
        totalDuration += p->getDuration();
    }

    if (vanCount > 0) {
        double avgWeight = totalWeight / vanCount;
        std::cout << "Середня вага вантажу: " << avgWeight << " тонн\n";
    }

    std::cout << "Загальна кількість пасажирів: " << totalPassengers << "\n";

    int totalCount = vantazhniCount + pasazhyrskiCount;
    if (totalCount > 0) {
        double avgCost = totalCost / totalCount;
        double avgDuration = static_cast<double>(totalDuration) / totalCount;

        std::cout << "Середня вартість перевезення: " << avgCost << "\n";
        std::cout << "Середня тривалість перевезення: " << avgDuration << " годин\n";
    }

    for (auto& p : perevezennya) {
        delete p;
    }

    return 0;
}
