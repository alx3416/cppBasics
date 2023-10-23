#include <iostream>

// One function works for all data types.  This would work
// even for user defined types if operator '>' is overloaded
template<typename Type_data>
Type_data myMax(Type_data x, Type_data y) {

    if (x > y) {
        return x;
    } else {
        return y;
    }
    // terniary operator option
    // return (x > y) ? x : y;
}

// C++ program to demonstrate the use of class templates
// Class template
template<class Type_data>
class Number {
private:
    // Variable of type Type_data
    Type_data num;

public:
    Number(Type_data n) : num(n) {}   // constructor

    Type_data getNum() {
        return num;
    }
};


int main() {
    // Function template example
    // Call myMax for int
    std::cout << myMax<int>(3, 7) << std::endl;
    // call myMax for double
    std::cout << myMax<double>(3.0, 7.0) << std::endl;
    // call myMax for char
    std::cout << myMax<char>('g', 'e') << std::endl;

    // Class template example
    // create object with int type
    Number<int> numberInt(7);

    // create object with double type
    Number<double> numberDouble(7.7);

    std::cout << "int Number = " << numberInt.getNum() << std::endl;
    std::cout << "double Number = " << numberDouble.getNum() << std::endl;

    // Directivas en C++ por default
    std::cout << "C++ Compiler Version : " << __cplusplus;
    std::cout << "\nDate : " << __DATE__;
    std::cout << "\nTime : " << __TIME__;
    std::cout << "\nFile Name : " << __FILE__;
    std::cout << "\nLine Number : " << __LINE__;
    std::cout << "\nSTDC_HOSTED : " << __STDC_HOSTED__;

    return 0;
}
