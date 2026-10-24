#include <iostream>
#include <string>
#include <cstdio>
#include <cstdint> // Для uint32_t
#include <cstring> // Для функции memcpy


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

int main() {
    sizeOfTypes();

    int valueInt;
    std::cout << "Введите число типа int для вывода всех битов от старшего к младшему: ";
    std::cin >> valueInt;
    convertIntToBin(valueInt);

    float valueFloat;
    std::cout << "Введите число типа float для получения битового представления: ";
    std::cin >> valueFloat;
    printFloatBits(valueFloat);
    std::cout << '\n';

    std::cout << "Print for 3.14: " << '\n';
    printFloatBits(3.14);
    std::cout << '\n';

    std::cout << "Print for -2.5: " << '\n';
    printFloatBits(-2.5);
    std::cout << '\n';

    std::cout << "Print for 0.0: " << '\n';
    printFloatBits(0.0);
    std::cout << '\n';
    printFloatBits(valueFloat);

    double valueDouble;
    std::cout << "Введите число типа double для получения битового представления: ";
    std::cin >> valueDouble;
    printDoubleBits(valueDouble);
    printFloatBits(valueFloat);

    std::cout << "Print for 3.14: " << '\n';
    printDoubleBits(3.14);
    std::cout << '\n';

    std::cout << "Print for -2.5: " << '\n';
    printDoubleBits(-2.5);
    std::cout << '\n';

    std::cout << "Print for 0.0: " << '\n';
    printDoubleBits(0.0);
    std::cout << '\n';
    return 0;
}