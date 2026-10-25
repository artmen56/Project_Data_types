#include "BitPrint.hpp"

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstring>
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

void printIntBits (const int& value, int width) {
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

void printUnsignedBits(const unsigned& value, int width) {
    for (int i = width - 1; i >= 0; --i) {
        putchar((value >> i) & 1u ? '1' : '0');

        if ((width - 1 - i) % 8 == 7) {
            std::cout << ' ';
        }
    }

    std::cout << '\n';
}


void printFloatBits(const float& value){
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

void printDoubleBits(const double& value){
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
