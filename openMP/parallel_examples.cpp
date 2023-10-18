#include <iostream>
#include <cmath>
#include <omp.h>
#include <chrono>
#include <vector>

int main() {

#pragma omp parallel for num_threads(2)
    for (int i = 1; i <= 20; i++) {
        int tid = omp_get_thread_num();
        std::cout << "The thread " << tid << " executes i = " << i << std::endl;
    }

    float count {0};
    std::cout << "\ncreating 2D array: " << std::endl;
    float myMatrix[10000][10000];

    auto startTime = std::chrono::high_resolution_clock::now();
#pragma omp parallel for num_threads(2)
    for(int i=0; i<10000; i++) {
        for (int j = 0; j < 10000; j++) {
            myMatrix[i][j] = static_cast<float>(i*j);
            count++;
        }
    }
    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
    std::cout << "Time taken by C-Array OpenMP: " << duration.count() << " microseconds" << std::endl;
    float sum_total {0};

#pragma omp parallel for num_threads(2)
    for(int i=0; i<10000; i++) {
        for (int j = 0; j < 10000; j++) {
            sum_total += myMatrix[i][j];
        }
    }
    std::cout << "2D array created" << std::endl;
    std::cout << "sum_total = " << sum_total << std::endl;

    return 0;
}

