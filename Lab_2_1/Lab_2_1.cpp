#include <iostream>
#include <Windows.h>
#include "Bill.h"

using namespace std;

// Структура для демонстрації #pragma pack(1)
#pragma pack(push, 1)
class BillPacked {
    unsigned int first;
    double second;
};
#pragma pack(pop)

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    // Вивід розміру класу
    cout << "Розмір класу Bill без #pragma pack(1): " << sizeof(Bill) << " байт" << endl;
    cout << "Розмір класу з #pragma pack(1): " << sizeof(BillPacked) << " байт" << endl;
    cout << "-------------------------------------------------" << endl;

    // Демонстрація конструкторів
    Bill b1;                  // За умовчанням
    Bill b2(15, 2.5);         // Ініціалізації
    Bill b3 = b2;             // Копіювання

    cout << "Створені об'єкти:" << endl;
    cout << "b1 (за умовчанням): " << b1 << endl;
    cout << "b2 (ініціалізації) : " << b2 << endl;
    cout << "b3 (копіювання)    : " << b3 << endl;

    // Операція присвоєння
    b1 = b2;
    cout << "\nПісля b1 = b2, об'єкт b1: " << b1 << endl;

    // Метод cost()
    cout << "Загальна вартість розмови для b1: " << b1.cost() << " грн" << endl;

    // Демонстрація інкрементів і декрементів
    cout << "\nТестування операторів ++ та -- :" << endl;
    cout << "++b1 (збільшує first)       : " << ++b1 << endl;
    cout << "--b1 (зменшує first)        : " << --b1 << endl;
    cout << "b1++ (збільшує second)      : " << b1++ << " (значення до зміни)" << endl;
    cout << "Поточний стан b1 після b1++ : " << b1 << endl;
    cout << "b1-- (зменшує second)       : " << b1-- << " (значення до зміни)" << endl;
    cout << "Поточний стан b1 після b1-- : " << b1 << endl;

    // Ввід з клавіатури
    cout << "\nТестування вводу:" << endl;
    Bill b4;
    cin >> b4;
    cout << "Ви ввели: " << b4 << endl;
    cout << "Загальна вартість розмови: " << b4.cost() << " грн" << endl;

    // Робота з масивом об'єктів
    cout << "\nДемонстрація масиву об'єктів:" << endl;
    Bill arr[3] = { Bill(5, 1.5), Bill(12, 0.5), Bill() };
    for (int i = 0; i < 3; ++i) {
        cout << "arr[" << i << "] : " << arr[i] << " | Загальна вартість: " << arr[i].cost() << " грн" << endl;
    }

    return 0;
}