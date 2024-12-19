#include "GA_TSP.hpp"
#include <iostream>
#include <vector>
using namespace std;

int N; // 种群规模

int main() {
    vector<City>Data = read_TSP();
    int N = input();
    vector<int> DEC_population = initializePopulation(N);
    vector<vector<bool>> BIN_population = transform(N, DEC_population);
    // 打印测试信息
    print_DEC_encoding(N, DEC_population);
    print_BIN_encoding(N, BIN_population);
}