#include "Examples.hpp"
#include "BitPrint.hpp"
#include "BitOperation.hpp"

#include <iostream>
#include <limits>

void printExampleUnsignedBits() {
    unsigned value = 10;

    std::cout << "Для числа 10 без знака двоичное представление:" << '\n';
    printUnsignedBits(value);
    std::cout << '\n';
}

void printExamplesFloatBits() {
    std::cout << "Вывод битового предствления числа 3.14: " << '\n';
    printFloatBits(3.14);
    std::cout << '\n';

    std::cout << "Вывод битового предствления числа -2.5: " << '\n';
    printFloatBits(-2.5);
    std::cout << '\n';

    std::cout << "Вывод битового предствления числа 0.0: "<< '\n';
    printFloatBits(0.0);
    std::cout << '\n';

    float denormFloat = std::numeric_limits<float>::denorm_min();
    std::cout << "Вывод битового представления денормализованного числа (float): ";
    printFloatBits(denormFloat);
    std::cout << '\n';

    float infFloat = std::numeric_limits<float>::infinity();
    std::cout << "Вывод битового представления inf (float): ";
    printFloatBits(infFloat);
    std::cout << '\n';
}

void printExamplesDoubleBits(){
    std::cout << "Вывод битового предствления числа 3.14: " << '\n';
    printDoubleBits(3.14);
    std::cout << '\n';

    std::cout << "Вывод битового предствления числа -2.5: " << '\n';
    printDoubleBits(-2.5);
    std::cout << '\n';

    std::cout << "Вывод битового предствления числа 0.0: " << '\n';
    printDoubleBits(0.0);
    std::cout << '\n';

    double denormDouble = std::numeric_limits<double>::denorm_min();
    std::cout << "Вывод битового представления денормализованного числа (double): ";
    printDoubleBits(denormDouble);
    std::cout << '\n';

    double infDouble = std::numeric_limits<double>::infinity();
    std::cout << "Вывод битового представления inf (double): ";
    printDoubleBits(infDouble);
    std::cout << '\n';
}

void printExampleBitManipulation() {
    int intValue = 10;
    int intResult = operationsWithBitsInt(intValue, 2, 1);

    std::cout << "Установка бита 2 для числа типа int равного 10" << '\n';
    std::cout << "Исходное значение: " << intValue << '\n';
    std::cout << "Биты до операции: " << '\n';
    printIntBits(intValue);

    std::cout << "Результат: " << intResult << '\n';
    std::cout << "Биты после операции:" << '\n';
    printIntBits(intResult);
    std::cout << '\n';


    // int: сброс бита
    intResult = operationsWithBitsInt(intValue, 3, 2);

    std::cout << "Сброс бита 3 для числа типа int равного 10" << '\n';
    std::cout << "Исходное значение: " << intValue << '\n';
    std::cout << "Биты до операции: " << '\n';
    printIntBits(intValue);

    std::cout << "Результат: " << intResult << '\n';
    std::cout << "Биты после операции: " << '\n';
    printIntBits(intResult);
    std::cout << '\n';


    // int: инверсия бита
    intResult = operationsWithBitsInt(intValue, 1, 3);

    std::cout << "Инверсия бита 1 для числа типа int равного 10" << '\n';
    std::cout << "Исходное значение: " << intValue << '\n';
    std::cout << "Биты до операции:" << '\n';
    printIntBits(intValue);

    std::cout << "Результат: " << intResult << '\n';
    std::cout << "Биты после операции:" << '\n';
    printIntBits(intResult);
    std::cout << '\n';


    // float: инверсия знакового бита
    float floatValue = 3.14;
    float floatResult = operationsWithBitsFloat(floatValue, 31, 3);

    std::cout << "Инверсия знакового бита 31 для числа типа float равного 3.14" << '\n';
    std::cout << "Исходное значение: " << floatValue << '\n';
    std::cout << "Биты до операции:" << '\n';
    printFloatBits(floatValue);

    std::cout << "Результат: " << floatResult << '\n';
    std::cout << "Биты после операции:" << '\n';
    printFloatBits(floatResult);
    std::cout << '\n';


    // double: инверсия знакового бита
    double doubleValue = 3.141592653589793;
    double doubleResult = operationsWithBitsDouble(doubleValue, 63, 3);

    std::cout << "Инверсия знакового бита 63 для числа типа double равного 3.141592653589793" << '\n';
    std::cout << "Исходное значение: " << doubleValue << '\n';
    std::cout << "Биты до операции:" << '\n';
    printDoubleBits(doubleValue);

    std::cout << "Результат: " << doubleResult << '\n';
    std::cout << "Биты после операции:" << '\n';
    printDoubleBits(doubleResult);
}

void printExampleMultiplyByTwo() {
    int value = 5;

    std::cout << "Умножение числа 5 на 2 с помощью битового сдвига\n";

    std::cout << "Исходное значение: " << value << '\n';
    std::cout << "Битовое представление до сдвига:\n";
    printIntBits(static_cast<int>(value));

    unsigned result = multiplyByTwoWithShift(value);

    std::cout << "Битовое представление после сдвига влево на 1:\n";
    printIntBits(static_cast<int>(result));

    std::cout << "Результат: " << result << '\n';
}
