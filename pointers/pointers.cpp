#include <iostream>
#include "pointers_utils.h"

int main() {
    // Passing by value, reference and pointer
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

    // Pass by pointer example, swap 2 numbers
    int y = 34;
    std::cout << "before swap, x = " << x << ", " << "y = " << y << std::endl;
    ptrs_basics::swapByPointer(&x, &y);
    std::cout << "after swap, x = " << x << ", " << "y = " << y << std::endl;

    // Arithmetic operations with pointers (++, --, +, -)
    int cArray[5] = {10,20,30,40,50};
    int* ptr_cArray = nullptr;
    ptr_cArray = cArray;
    for(int idx=0; idx < 5; idx++){
        std::cout << "Address of cArray[" << idx << "] --> " << ptr_cArray << std::endl;
        std::cout << "Value of cArray[" << idx << "] --> " << *ptr_cArray << std::endl;
        ptr_cArray++;
    }


    // which is faster, pass by value or reference?
    std::vector<int> array(100000000);
    auto startTime = std::chrono::high_resolution_clock::now();
    array = ptrs_basics::fillVectorByValue(array);
    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
    std::cout << "Time taken by fillVectorByValue: " << duration.count() << " microseconds" << std::endl;

    std::vector<int> array2(100000000);
    startTime = std::chrono::high_resolution_clock::now();
    ptrs_basics::fillVectorByReference(array);
    stopTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
    std::cout << "Time taken by fillVectorByReference: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
