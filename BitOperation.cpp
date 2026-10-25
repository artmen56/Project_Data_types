#include "BitOperation.hpp"

#include <iostream>
#include <cstdint>
#include <cstring>

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

int multiplyByTwoWithShift(int value) {
    unsigned bits = static_cast<unsigned>(value);
    bits <<= 1;
    return static_cast<int>(bits);
}
