#include "BitPrint.hpp"
#include "Input.hpp"
#include "Examples.hpp"


#include <iostream>

int main() {
    std::cout << "\n===== РАЗМЕРЫ ТИПОВ =====\n";
    sizeOfTypes();
    std::cout << '\n';

    std::cout << "===== INT =====" << '\n' ;
    inputIntBits();

    std::cout << "===== UNSIGNED =====" << '\n' ;
    printExampleUnsignedBits();

    std::cout << "===== FLOAT IEEE 754 =====" << '\n';
    inputFloatBits();

    std::cout << "===== ВЫВОД ПРИМЕРОВ ДЛЯ FLOAT IEEE 754 =====" << '\n';
    printExamplesFloatBits();
    std::cout << '\n';
    
    std::cout << "===== DOUBLE IEEE 754 =====" << '\n';
    inputDoubleBits();

    std::cout << "===== ВЫВОД ПРИМЕРОВ ДЛЯ DOUBLE IEEE 754 =====\n";
    printExamplesDoubleBits();
    std::cout << '\n';

    std::cout << "===== ОПЕРАЦИИ С БИТАМИ =====" << '\n';

    inputOperationWithBitsInt();

    inputOperationWithBitsFloat();

    inputOperationWithBitsDouble();

    printExampleBitManipulation();
    std::cout << '\n';

    std::cout << "===== УМНОЖЕНИЕ НА ДВА ЧЕРЕЗ ПОБИТОВЫЙ СДВИГ =====" << '\n';

    inputMultiplyByTwoWithShift();

    std::cout << "===== ВЫВОД ПРИМЕРА ДЛЯ УМНОЖЕНИЯ НА ДВА ЧЕРЕЗ ПОБИТОВЫЙ СДВИГ =====" << '\n';

    printExampleMultiplyByTwo();

    return 0;
}