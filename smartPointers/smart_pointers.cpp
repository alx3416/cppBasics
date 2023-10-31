#include "smart_pointers_utils.h"
#include <memory>

int main()
{
    std::cout << "Ejemplo 1, intuición principal de smart pointers" << std::endl;

    smartPtrs::SmartPtr ptr(new int());
    *ptr = 20;
    std::cout << *ptr << std::endl;

    std::cout << "Ejemplo 2, idea general sobre auto_ptr (not available in C++17 and later))" << std::endl;
    int *i = new int;
    std::auto_ptr<int> x(i);
    std::auto_ptr<int> y;

    y = x;

    std::cout << x.get() << std::endl; // Print NULL
    std::cout << y.get() << std::endl; // Print non-NULL address i

    std::cout << "Ejemplo 3 unique_ptr" << std::endl;

    std::unique_ptr<smartPtrs::Rectangle> P1(new smartPtrs::Rectangle(10, 5));
    std::cout << P1->area() << std::endl; // This'll print 50

    // unique_ptr<Rectangle> P2(P1);
    std::unique_ptr<smartPtrs::Rectangle> P2;
    P2 = std::move(P1);

    // This'll print 50
    std::cout << P2->area() << std::endl;
    // std::cout<<P1->area()<<std::endl; // error P1 was moved

    std::cout << "Ejemplo 4 shared_ptr" << std::endl;
    std::shared_ptr<smartPtrs::Rectangle> sharedP1(new smartPtrs::Rectangle(7, 12));
    // This'll print 50
    std::cout << sharedP1->area() << std::endl;

    std::shared_ptr<smartPtrs::Rectangle> sharedP2;
    sharedP2 = sharedP1;

    // This'll print 50
    std::cout << sharedP2->area() << std::endl;

    // This'll now not give an error,
    std::cout << sharedP1->area() << std::endl;

    // This'll also print 50 now
    // This'll print 2 as Reference Counter is 2
    std::cout << sharedP1.use_count() << std::endl;

    std::cout << "Ejemplo 5 weak_ptr" << std::endl;
    std::shared_ptr<smartPtrs::Rectangle> sharedP3 = std::make_shared<smartPtrs::Rectangle>(11, 10);

    // create weak ptr
    std::weak_ptr<smartPtrs::Rectangle> weakP1 = sharedP3;

    std::cout << weakP1.use_count() << std::endl;

    // This'll print 1 as Reference Counter is 1
    std::cout << sharedP3.use_count() << std::endl;
    std::cout << sharedP3->area() << std::endl;
    if (auto locked_wp = weakP1.lock()) {
        std::cout << locked_wp->area() << std::endl;
    }

    // Smart Pointers and Arrays
    auto ptr_array = std::make_unique<int[]>(10);
    std::cout << ptr_array[0] << '\n';
    std::cout << ptr_array[9] << '\n';

    auto ptr_array_large = std::make_unique<int[]>(10000000);
    std::cout << ptr_array_large[0] << '\n';
    std::cout << ptr_array_large[9999999] << '\n';

    // 2D array and smart pointers
    std::unique_ptr<std::unique_ptr<int[]>[]>     smartPtr2D;
    std::unique_ptr<int[]>                        smartPtr1D;

    int dataCounter = 0;

    smartPtr2D = std::make_unique< std::unique_ptr<int[]>[] >(4);
    for (int i = 0; i<4; i++)
    {
        smartPtr1D = std::make_unique<int[]>(3);
        for (int j = 0; j<3; j++)
        {
            smartPtr1D[j] = dataCounter;
            dataCounter++;
        }
        smartPtr2D[i] = move(smartPtr1D);
    }

    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<3; j++)
        {
            std::cout << smartPtr2D[i][j] << ' ';
        }
        std::cout << '\n';
    }


    return 0;
}