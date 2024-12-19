#include "GA_TSP.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<City> read_TSP(){
    ifstream inputFile("D:\\GA\\xqf131.txt");  // 打开文件
    if (!inputFile) {
        cerr << "无法打开文件" << endl;
        exit(0);
    }

    string line;
    string name;
    int dimension = 0;//不知道怎么读取数据
    vector<City> cities;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string key;
        if (iss >> key) {
            if (key == "NAME") {
                cout << 1;
                getline(iss, name);  // 读取名称
                name.erase(name.begin());  // 移除冒号后的空格
            }
            else if (key == "NODE_COORD_SECTION") {
                // 开始读取城市坐标信息
                while (getline(inputFile, line) && line != "EOF") {
                    dimension++;
                    City city;
                    istringstream cityIss(line);
                    if (!(cityIss >> city.id >> city.x >> city.y)) {
                        cerr << "错误：无法解析城市坐标信息：" << line << endl;
                        continue;
                    }
                    cities.push_back(city);
                }
            }
        }
    }

    inputFile.close();

    // 输出读取到的信息
    cout << "数据集名称: " << name << endl;
    cout << "维度（城市数量）: " << dimension << endl;
    cout << "城市坐标信息如下：" << endl;
    for (const auto& city : cities) {
        cout << "城市编号: " << city.id << "，坐标: (" << city.x << ", " << city.y << ")" << endl;
    }
    return cities;
}