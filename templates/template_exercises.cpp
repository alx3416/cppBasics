#include "template_exercises.h"

int main(){

    int x {255};
    int y {-127};
    myTemplates::SwapData(x, y);
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    double* ptr1 = new double(3.1416);
    double* ptr2 = new double(2.7182);
    myTemplates::SwapData(ptr1, ptr2);
    std::cout << " ptr1 = " << *ptr1 << std::endl;
    std::cout << " ptr2 = " << *ptr2 << std::endl;
    delete ptr1;
    delete ptr2;
}