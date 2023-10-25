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

} // myTemplates
#endif //CPPBASICS_TEMPLATE_EXERCISES_H
