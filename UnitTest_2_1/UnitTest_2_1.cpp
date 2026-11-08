#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2_1/Bill.h"   
#include "../Lab_2_1/Bill.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest_Bill)
    {
    public:

        // Тестуємо конструктор ініціалізації
        TEST_METHOD(TestInitialization)
        {
            Bill b(10, 2.5);
            Assert::AreEqual(10u, b.getFirst());   // перевіряємо хвилини
            Assert::AreEqual(2.5, b.getSecond());  // перевіряємо ціну
        }

        // Тестуємо метод cost() - загальну вартість
        TEST_METHOD(TestCostMethod)
        {
            Bill b(10, 2.5); // 10 хв * 2.5 грн = 25.0
            double expected = 25.0;
            Assert::AreEqual(expected, b.cost());  // перевіряємо результат
        }

        // Тестуємо префіксний інкремент (++b)
        TEST_METHOD(TestPrefixIncrement)
        {
            Bill b(5, 2.0);
            ++b; // має збільшити first (тривалість) на 1
            Assert::AreEqual(6u, b.getFirst());
        }

        // Тестуємо постфіксний інкремент (b++)
        TEST_METHOD(TestPostfixIncrement)
        {
            Bill b(5, 2.0);
            b++; // має збільшити second (вартість) на 1
            Assert::AreEqual(3.0, b.getSecond());
        }

        // Тестуємо префіксний декремент (--b)
        TEST_METHOD(TestPrefixDecrement)
        {
            Bill b(5, 2.0);
            --b; // має зменшити first (тривалість) на 1
            Assert::AreEqual(4u, b.getFirst());
        }
    };
}