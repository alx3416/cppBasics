#ifndef CPPBASICS_POINTERS_UTILS_H
#define CPPBASICS_POINTERS_UTILS_H

namespace ptrs_basics {
    int squarePassByValue(int n) {
        n *= n;
        return n;
    }

    void squarePassByReference(int &n) {
        n *= n;
    }

    void squarePassByPointer(int *n_ptr) {
        int n = *n_ptr;
        n *= n;
        *n_ptr = n;
    }
}  // ptrs_basics
#endif //CPPBASICS_POINTERS_UTILS_H
