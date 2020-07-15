

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int x;
    while( std::cin >> x ) {
        vec.push_back(x);
    }
    for (const auto& element : vec) {
        std::cout << element << std::endl;
    }
    std::cout << x << std::endl;
    std::cout << &x << std::endl;
    int* addr = &x;
    int** addr_2 = &addr;
    *addr = 88;
    std::cout << x << addr_2 << std::endl;
    double* yyy = nullptr;
    return 0;
}
