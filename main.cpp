#include <iostream>
#include <cstdio>
#include <cstdint> // Для uint32_t
#include <cstring> // Для функции memcpy
#include <limits>


void sizeOfTypes() {
    std::cout << "Size of int: " << sizeof(int) << " bytes" << '\n';
    std::cout << "Size of short: " << sizeof(short)<< " bytes" << '\n';
    std::cout << "Size of long: " << sizeof(long) << " bytes" << '\n';
    std::cout << "Size of long long: " << sizeof(long long) << " bytes" << '\n';
    std::cout << "Size of float: " << sizeof(float) << " bytes" << '\n';
    std::cout << "Size of double: " << sizeof(double) << " bytes" << '\n';
    std::cout << "Size of long double: " << sizeof(long double) << " bytes" << '\n';
    std::cout << "Size of char: " << sizeof(char) << " bytes" << '\n';
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << '\n';
}

void convertIntToBin (int value, int width = 32) {
    unsigned u = static_cast<unsigned>(value); // Представляем n типа int в виде unsigned с помощью static_cast
    for (int i = width - 1; i >= 0; i--) { // Цикл от страрших битов числа к младшим
        if (i == width - 1) {
            std::cout << "[sign]";
        }
        putchar((u >> i) & 1 ? '1' : '0'); // Выводим символ '1' если при смещении битов u на i битов вправо, в нулевой позиции стоит '1'
        if (i == (width - 1)){
            std::cout << " ";
        }
        if ((width - 1 - i) % 8 == 7) { // Если осток от деления номера бита на 8 равен 7, то отделям биты пробелом
            std::cout << " ";
        }
    }
    std::cout << '\n';
}

void printFloatBits(float value){
    uint32_t bits;
    std::memcpy(&bits, &value, sizeof(float)); // Копируем биты числа типа float в переменную bits типа uint32_t
    
    std::cout << "[sign]" << ((bits >> 31) & 1u);
    
    std::cout << " [exponent]";
    for (int i = 30; i >= 23; --i){
        std::cout << ((bits >> i) & 1u);
    }

    std::cout << " [mantissa]";
    for (int i = 22; i >= 0; --i){
        std::cout << ((bits >> i) & 1u);
    }

    std::cout << '\n';
}

void printDoubleBits(double value){
    uint64_t bits;
    std::memcpy(&bits, &value, sizeof(double)); // Копируем биты числа типа double в переменную bits типа uint64_t
    
    std::cout << "[sign]" << ((bits >> 63) & 1ull);
    
    std::cout << " [exponent]";
    for (int i = 62; i >= 52; --i){
        std::cout << ((bits >> i) & 1ull);
    }

    std::cout << " [mantissa]";
    for (int i = 51; i >= 0; --i){
        std::cout << ((bits >> i) & 1ull);
    }

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

int operationsWithBitsInt(int value, int numberBit, int numberOperation) {
    if (numberBit < 0 || numberBit >= 32) {
        std::cout << "Некорректный номер бита" << '\n';
        return value;
    }
    if (numberOperation == 1) {
        value |= (1u << numberBit);
    } else if (numberOperation == 2) {
        value &= ~(1u << numberBit);
    } else if (numberOperation == 3) {
        value ^= (1u << numberBit);
    } else {
        std::cout << "Некорректный номер операции" << '\n';
    }

    return value;
}

float operationsWithBitsFloat(float value, int numberBit, int numberOperation) {
    uint32_t bits;

    std::memcpy(&bits, &value, sizeof(value));

    if (numberBit < 0 || numberBit >= 32) {
        std::cout << "Некорректный номер бита" << '\n';
        return value;
    }

    if (numberOperation == 1) {
        bits |= (1u << numberBit);
    } else if (numberOperation == 2) {
        bits &= ~(1u << numberBit);
    } else if (numberOperation == 3) {
        bits ^= (1u << numberBit);
    } else {
        std::cout << "Некорректный номер операции" << '\n';
    }

    std::memcpy(&value, &bits, sizeof(value));

    return value;
}

double operationsWithBitsDouble(double value, int numberBit, int numberOperation) {
    uint64_t bits;

    std::memcpy(&bits, &value, sizeof(value));

    if (numberBit < 0 || numberBit >= 64) {
        std::cout << "Некорректный номер бита" << '\n';
        return value;
    }

    if (numberOperation == 1) {
        bits |= (1ull << numberBit);
    } else if (numberOperation == 2) {
        bits &= ~(1ull << numberBit);
    } else if (numberOperation == 3) {
        bits ^= (1ull << numberBit);
    } else {
        std::cout << "Некорректный номер операции" << '\n';
    }

    std::memcpy(&value, &bits, sizeof(value));

    return value;
}

void printExampleBitManipulation() {
    int intValue = 10;
    int intResult = operationsWithBitsInt(intValue, 2, 1);

    std::cout << "Установка бита 2 для числа типа int равного 10" << '\n';
    std::cout << "Исходное значение: " << intValue << '\n';
    std::cout << "Биты до операции: " << '\n';
    convertIntToBin(intValue);

    std::cout << "Результат: " << intResult << '\n';
    std::cout << "Биты после операции:" << '\n';
    convertIntToBin(intResult);
    std::cout << '\n';


    // int: сброс бита
    intResult = operationsWithBitsInt(intValue, 3, 2);

    std::cout << "Сброс бита 3 для числа типа int равного 10" << '\n';
    std::cout << "Исходное значение: " << intValue << '\n';
    std::cout << "Биты до операции: " << '\n';
    convertIntToBin(intValue);

    std::cout << "Результат: " << intResult << '\n';
    std::cout << "Биты после операции: " << '\n';
    convertIntToBin(intResult);
    std::cout << '\n';


    // int: инверсия бита
    intResult = operationsWithBitsInt(intValue, 1, 3);

    std::cout << "Инверсия бита 1 для числа типа int равного 10" << '\n';
    std::cout << "Исходное значение: " << intValue << '\n';
    std::cout << "Биты до операции:" << '\n';
    convertIntToBin(intValue);

    std::cout << "Результат: " << intResult << '\n';
    std::cout << "Биты после операции:" << '\n';
    convertIntToBin(intResult);
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

int main() {
    std::cout << "\n===== РАЗМЕРЫ ТИПОВ =====\n";
    sizeOfTypes();


    std::cout << "\n===== INT =====\n";
    int valueInt;
    std::cout << "Введите число типа int для вывода всех битов от старшего к младшему: ";
    std::cin >> valueInt;
    convertIntToBin(valueInt);


    std::cout << "\n===== FLOAT IEEE 754 =====\n";
    float valueFloat;
    std::cout << "Введите число типа float для получения битового представления: ";
    std::cin >> valueFloat;
    printFloatBits(valueFloat);
    std::cout << '\n';

    std::cout << "\n===== ВЫВОД ПРИМЕРОВ ДЛЯ FLOAT IEEE 754 =====\n";
    printExamplesFloatBits();

    
    std::cout << "\n===== DOUBLE IEEE 754 =====\n";
    double valueDouble;
    std::cout << "Введите число типа double для получения битового представления: ";
    std::cin >> valueDouble;
    printDoubleBits(valueDouble);
    std::cout << '\n';

    std::cout << "\n===== ВЫВОД ПРИМЕРОВ ДЛЯ DOUBLE IEEE 754 =====\n";
    printExamplesDoubleBits();

    std::cout << "\n===== ОПЕРАЦИИ С БИТАМИ =====\n";
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
    convertIntToBin(valueIntOperation);

    int resultInt = operationsWithBitsInt(valueIntOperation, numberBitInt, numberOperationInt);

    std::cout << "Результат операции: " << resultInt << '\n';
    std::cout << "Битовое представление результата операции: " << '\n';
    convertIntToBin(resultInt);
    std::cout << '\n';  

    
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

    printExampleBitManipulation();

    return 0;
}