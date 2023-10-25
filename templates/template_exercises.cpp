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

    // swap 2 vectors v1=a,b,c  v2=x,y,z
    std::vector<char> text1 {'a', 'b', 'c'};
    std::vector<char> text2 {'x', 'y', 'z', 'f'};
    myTemplates::SwapData(text1, text2);
    std::cout << " vec1 = " << text1.at(0) << std::endl;
    std::cout << " vec2 = " << text2.at(0) << std::endl;

    // sum all elements in a C Array
    float float_data[5] {3.14, -2.71, 1.33, -7.77, 5.1};
    int int_data[5] {10,20,30,40,50};
    std::cout << "Sum float_data = " << myTemplates::sum(float_data, 5) << std::endl;
    std::cout << "Sum int_data = " << myTemplates::sum(int_data, 5) << std::endl;

    return 0;
}