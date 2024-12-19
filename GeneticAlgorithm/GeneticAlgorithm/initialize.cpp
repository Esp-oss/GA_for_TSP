#include "GA.hpp"
#include <vector>
#include <random>
#include <iostream>
using namespace std;

int input() {
    cout << "输入种群规模并进行初始化" << endl;
    int N;
    cin >> N;
    return N;
}

// 种群初始化
vector<int> initializePopulation(int N) {
    vector<int> population;
    random_device rd;
    mt19937 gen(rd()); // 梅森旋转引擎
    for (int i = 0; i < N; ++i) {
        int num = gen();
        if (num < 0) {
            num *= -1;
        }
        population.push_back(num);
    }
    return population;
}

vector<vector<bool>> transform(int N, const vector<int>& population) {
    vector<vector<bool>> trans(N, vector<bool>(33, 0));
    for (int i = 0; i < N; i++) {
        long long num = population[i];
        for (int j = 0; j < 32; ++j) {
            trans[i][32 - j] = (num >> j) & 1; // 右移并通过与1做与运算获取二进制位
        }
    }
    return trans;
}

// 打印十进制编码
void print_DEC_encoding(int N, const vector<int>& DEC_population) {
    cout << "十进制编码:\n";
    for (int i = 0; i < N; i++) {
        cout << i << "号个体:";
        cout << DEC_population[i] << "\n";
    }
}

// 打印二进制编码
void print_BIN_encoding(int N, const vector<vector<bool>>& BIN_population) {
    cout << "二进制编码:\n";
    for (int i = 0; i < N; i++) {
        cout << i << "号个体:";
        for (bool j : BIN_population[i]) {
            cout << j;
        }
        cout << "\n";
    }
}