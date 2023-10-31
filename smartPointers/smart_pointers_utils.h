#ifndef CPPBASICS_SMART_POINTERS_UTILS_H
#define CPPBASICS_SMART_POINTERS_UTILS_H

#include <iostream>

namespace smartPtrs{

    class SmartPtr {
        int* ptr; // Actual pointer
    public:
        explicit SmartPtr(int* p = NULL) { ptr = p; }

        // Destructor
        ~SmartPtr() { delete (ptr); }

        // Overloading dereferencing operator
        int& operator*() { return *ptr; }
    };

    class Rectangle {
        int length;
        int width;

    public:
        Rectangle(int l, int w)
        {
            length = l;
            width = w;
        }

        int area() { return length * width; }
    };

    void fun(std::unique_ptr<std::unique_ptr<int[]>[]> &myArray)
    {
        for (int i = 0; i<4; i++){
            for (int j = 0; j<3; j++){
                std::cout << myArray[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }



}

#endif //CPPBASICS_SMART_POINTERS_UTILS_H
