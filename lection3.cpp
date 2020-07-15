//
// Created by misha on 26/06/2020.
//
#include <iostream>

class Vector {
public:
    void push_back(int x);

private:
    int* begin_;
};
/* Vector v;
 * v.begin_ = nullptr; будет ошибка */
struct User {
    std::string username;
    int age;


    bool IsOldEnough()
    {
        return age > 18;
    } //Метод

    User(std::string name, int age) : username(name)
    {
        age = age;
    } //Конструктор
};

int main() {
    User userу;
    usery.name = "Joe";
    usery.age = 19;
    if (!userу.IsOldEnough()) {
        return 0;
    }
}