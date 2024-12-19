#ifndef GA_TSP_HPP
#define GA_TSP_HPP

#include <vector>

struct City {
    int id;
    int x;
    int y;
};
//vector前需要添加std::
std::vector <City> read_TSP();
int input();
std::vector<int> initializePopulation(int N);
std::vector<std::vector<bool>> transform(int N, const std::vector<int>& population);
void print_DEC_encoding(int N, const std::vector<int>& DEC_population);
void print_BIN_encoding(int N, const std::vector<std::vector<bool>>& BIN_population);

#endif // GA_HPP