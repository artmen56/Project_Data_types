#include <iostream>
#include <string>

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

void convertIntToBin (int n, int width = 32) {
    unsigned u = static_cast<unsigned>(n); // Представляем n типа int в виде unsigned с помощью static_cast
    for (int i = width - 1; i >= 0; i--) { // Цикл от страрших битов числа к младшим
        if (i == width - 1) {
            std::cout << "sign ->";
        }
        putchar((u >> i) & 1 ? '1' : '0'); // Выводим симво '1' если при смещении битов u на i битов вправо, в нулевой позиции стоит '1'
        if ((width - 1 - i) % 8 == 7) { // Если осток от деления номера бита на 8 равен 7, то отделям биты пробелом
            std::cout << " ";
        }
    }
    std::cout << '\n';
}

int main() {
    sizeOfTypes();
    
    int n;
    std::cout << "Введите число n: ";
    std::cin >> n;
    convertIntToBin(n);
    return 0;
}