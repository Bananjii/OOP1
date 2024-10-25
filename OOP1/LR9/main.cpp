#include <iostream>
#include <vector>
#include "Vantazhni.h"
#include "Vantazhni.cpp"
#include "Pasazhyrski.h"
#include "Pasazhyrski.cpp"
#include "Perevezennya.h"
#include "Perevezennya.cpp"
#include "Display.h"

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

    // Очищення пам'яті
    for (auto& p : perevezennya) {
        delete p;
    }

    return 0;
}