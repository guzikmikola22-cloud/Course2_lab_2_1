#pragma once
#include <iostream>
#include <string>

using namespace std;

class Bill {
private:
    unsigned int first; // тривалість розмови у хвилинах 
    double second;      // вартість однієї хвилини в гривнях 

public:
    // Конструктори
    Bill();                                       // за умовчанням
    Bill(unsigned int duration, double price);    // ініціалізації
    Bill(const Bill& other);                      // копіювання

    // Деструктор
    ~Bill();                                      // стандартний деструктор

    // Методи доступу (гетери та сетери)
    unsigned int getFirst() const;                // отримати тривалість
    void setFirst(unsigned int duration);         // змінити тривалість
    double getSecond() const;                     // отримати вартість
    void setSecond(double price);                 // змінити вартість

    // Метод обчислення загальної вартості розмови
    double cost() const;                          // рахує first * second

    // Перевантаження операції присвоєння
    Bill& operator=(const Bill& other);           // для копіювання об'єктів (b1 = b2)

    // Операція приведення типу
    operator string() const;                      // для зручного виводу тексту

    // Перевантаження інкременту та декременту
    Bill& operator++();    // префіксний інкремент (збільшує first)
    Bill& operator--();    // префіксний декремент (зменшує first)
    Bill operator++(int);  // постфіксний інкремент (збільшує second)
    Bill operator--(int);  // постфіксний декремент (зменшує second)

    // Дружні функції потокового вводу/виводу
    friend ostream& operator<<(ostream& out, const Bill& b); // для виводу на екран (cout <<)
    friend istream& operator>>(istream& in, Bill& b);        // для вводу з клавіатури (cin >>)
};