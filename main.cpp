#include <iostream>
#include "src/pmtk.h"
#include <cstring>
#include <chrono>
#define BENCHMARK_ITER 1000000

int main()
{
    const char *cmd = "PGKC115,1";
    char buff_1[3];
    char buff_2[3];

    sprintf(buff_1, "%X", getContolSum(cmd));
    sprintf(buff_2, "%X", getContolSum(cmd, strlen(cmd)));
    std::cout << "Checksum v1: " << buff_1 << std::endl;
    std::cout << "Checksum v2: " << buff_2 << std::endl;

    const auto now_v1 = std::chrono::high_resolution_clock::now();
    for(auto i = 0; i < BENCHMARK_ITER; ++i) getContolSum(cmd);
    const auto res_v1 = std::chrono::high_resolution_clock::now() - now_v1;

    const auto now_v2 = std::chrono::high_resolution_clock::now();
    for(auto i = 0; i < BENCHMARK_ITER; ++i) getContolSum(cmd, strlen(cmd));
    const auto res_v2 = std::chrono::high_resolution_clock::now() - now_v2;

    std::cout << "Benchmark iterations: " << BENCHMARK_ITER << std::endl;
    std::cout << "Benchmark v1:         " << std::chrono::duration_cast<std::chrono::nanoseconds>(res_v1).count() / static_cast<double>(BENCHMARK_ITER) << " ns" << std::endl;
    std::cout << "Benchmark v2:         " << std::chrono::duration_cast<std::chrono::nanoseconds>(res_v2).count() / static_cast<double>(BENCHMARK_ITER) << " ns" << std::endl;

    return 0;
}
