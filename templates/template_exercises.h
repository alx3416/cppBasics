#ifndef CPPBASICS_TEMPLATE_EXERCISES_H
#define CPPBASICS_TEMPLATE_EXERCISES_H
#include <iostream>
#include <vector>

namespace myTemplates {

    template<typename Type_data>
    Type_data myMax(Type_data x, Type_data y) {
        return (x > y) ? x : y;
    }

    template<typename Type_data>
    void SwapData (Type_data &x, Type_data &y){
        Type_data temp;
        temp = x;
        x = y;
        y = temp;
    }

    void myfun (int x[]){
        ;
    }

    template<typename T>
    T sum(T a[], int length)
    {
        T ret = a[0];
        for (int i = 1; i < length; i ++)
            ret += a[i];

        return ret;
    }
    template<class T>
    class Number {
    private:
        // Variable of type T
        T num;

    public:
        Number(T n) : num(n) {}   // constructor

        T getNum() {
            return num;
        }
    };

} // myTemplates
#endif //CPPBASICS_TEMPLATE_EXERCISES_H
