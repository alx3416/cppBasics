#ifndef CPPBASICS_TEMPLATE_EXERCISES_H
#define CPPBASICS_TEMPLATE_EXERCISES_H
#include <iostream>

namespace myTemplates {

    template<typename Type_data>
    Type_data myMax(Type_data x, Type_data y) {
        return (x > y) ? x : y;
    }

} // myTemplates
#endif //CPPBASICS_TEMPLATE_EXERCISES_H
