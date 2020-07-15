//
// Created by misha on 29/06/2020.
//
#include <iostream>

class User
{
public:
    User(const std::string& user) : name_(new std::string{user})
    { }

    ~User()
    {
        delete name_;
    }

private:
    std::string* name_;
};

void f() {
    User u("Fedor");
    // ~User автоматически вызывается в конце жизни объекта
}
