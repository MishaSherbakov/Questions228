//
// Created by misha on 14/06/2020.
//
#include <iostream>
#include <vector>
#include <unordered_map>

namespace my_space
{
    int value = 0;
}

int main() {
    my_space::value = 1;
    int value = 2;
    int* pvalue = &value;
    *pvalue = 3;
    std::vector<int> data = {1, 2, 3};
    std::unordered_map<int, int> counts;
    for (size_t i=0; i < data.size();++i) {
        counts[data[i]] += 2;
    }
    for (auto pair : counts)
    {
        std::cout<< pair.first << " " << pair.second << "\n";
    }
//    for (auto it = counts.begin();
//    it != counts.end(); ++it) {
//        std::cout<< it->first<<" "<<it->second << "\n";
//    }
}

