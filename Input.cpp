#include "Input.hpp"
#include "BitPrint.hpp"
#include "BitOperation.hpp"


#include <iostream>

void inputIntBits() {
    int valueInt;
    std::cout << "Введите число типа int для вывода всех битов от старшего к младшему: ";
    std::cin >> valueInt;
    printIntBits(valueInt);
    std::cout << '\n';
}

void inputFloatBits() {
    float valueFloat;
    std::cout << "Введите число типа float для получения битового представления: ";
    std::cin >> valueFloat;
    printFloatBits(valueFloat);
    std::cout << '\n';
}

void inputDoubleBits() {
    double valueDouble;
    std::cout << "Введите число типа double для получения битового представления: ";
    std::cin >> valueDouble;
    printDoubleBits(valueDouble);
    std::cout << '\n';
}


void inputOperationWithBitsInt() {
    std::cout << "Введите число типа int для выполнения операции с битом: " << '\n';
    int valueIntOperation;
    std::cin >> valueIntOperation;
    std::cout << '\n';

    std::cout << "Введите номер бита, над которым будет проводится операция: " << '\n';
    int numberBitInt;
    std::cin >> numberBitInt;
    std::cout << '\n';

    std::cout << "Введите номер операции, которую хотите выполнить над числом типа int: " << '\n';
    std::cout << "1 - установить бит" << '\n';
    std::cout << "2 - сбросить бит" << '\n';
    std::cout << "3 - инвертировать бит" << '\n';
    int numberOperationInt;
    std::cin >> numberOperationInt;
    std::cout << '\n';

    std::cout << "Битовое представление до операции: " << '\n';
    printIntBits(valueIntOperation);

    int resultInt = operationsWithBitsInt(valueIntOperation, numberBitInt, numberOperationInt);

    std::cout << "Результат операции: " << resultInt << '\n';
    std::cout << "Битовое представление результата операции: " << '\n';
    printIntBits(resultInt);
    std::cout << '\n';  
}

void inputOperationWithBitsFloat() {
    std::cout << "Введите число типа float для выполнения операции с битом: " << '\n';
    float valueFloatOperation;
    std::cin >> valueFloatOperation;
    std::cout << '\n';

    std::cout << "Введите номер бита, над которым будет проводится операция: " << '\n';
    int numberBitFloat;
    std::cin >> numberBitFloat;
    std::cout << '\n';

    std::cout << "Введите номер операции, которую хотите выполнить над числом типа float: " << '\n';
    std::cout << "1 - установить бит" << '\n';
    std::cout << "2 - сбросить бит" << '\n';
    std::cout << "3 - инвертировать бит" << '\n';
    
    int numberOperationFloat;
    std::cin >> numberOperationFloat;
    std::cout << '\n';

    std::cout << "Битовое представление до операции: " << '\n';
    printFloatBits(valueFloatOperation);

    float resultFloat = operationsWithBitsFloat(valueFloatOperation, numberBitFloat, numberOperationFloat);

    std::cout << "Результат операции: " << resultFloat << '\n';
    std::cout << "Битовое представление результата операции: " << '\n';
    printFloatBits(resultFloat);
    std::cout << '\n';
}

void inputOperationWithBitsDouble() {
    std::cout << "Введите число типа double для выполнения операции с битом: " << '\n';
    double valueDoubleOperation;
    std::cin >> valueDoubleOperation;
    std::cout << '\n';

    std::cout << "Введите номер бита, над которым будет проводится операция: " << '\n';
    int numberBitDouble;
    std::cin >> numberBitDouble;
    std::cout << '\n';

    std::cout << "Введите номер операции, которую хотите выполнить над числом типа double: " << '\n';
    std::cout << "1 - установить бит" << '\n';
    std::cout << "2 - сбросить бит" << '\n';
    std::cout << "3 - инвертировать бит" << '\n';
    int numberOperationDouble;
    std::cin >> numberOperationDouble;
    std::cout << '\n';

    std::cout << "Битовое представление до операции: " << '\n';
    printDoubleBits(valueDoubleOperation);

    double resultDouble = operationsWithBitsDouble(valueDoubleOperation, numberBitDouble, numberOperationDouble);

    std::cout << "Результат операции: " << resultDouble << '\n';
    std::cout << "Битовое представление результата операции: " << '\n';
    printDoubleBits(resultDouble);
    std::cout << '\n';
}

void inputMultiplyByTwoWithShift() {
    std::cout << "Введите число, которое необходимо умножить на два: " << '\n';
    int valueForMultiplyByTwo;
    std::cin >> valueForMultiplyByTwo;
    std::cout << "Битовое представление до операции: " << '\n';
    printIntBits(valueForMultiplyByTwo);
    int resultMultiply = multiplyByTwoWithShift(valueForMultiplyByTwo);
    std::cout << "Результат операции: " << resultMultiply << '\n';
    std::cout << "Битовое представление результата операции: " << '\n';
    printIntBits(resultMultiply);
    std::cout << '\n';
}
