#include <iostream>
#include "pointers_utils.h"

int main() {
    int x = 2;
    std::cout << "x value = " << x << std::endl;
    std::cout << "x address -> " << &x << std::endl;

    ptrs_basics::squarePassByReference(x);
    std::cout << "x after pass by reference= " << x << std::endl;
    std::cout << "x address pass by reference-> " << &x << std::endl;

    x = ptrs_basics::squarePassByValue(x);
    std::cout << "x after pass by value= " << x << std::endl;
    std::cout << "x address pass by value-> " << &x << std::endl;

    ptrs_basics::squarePassByPointer(&x);
    std::cout << "x after pass by pointer= " << x << std::endl;
    std::cout << "x address pass by pointer-> " << &x << std::endl;
    return 0;
}
