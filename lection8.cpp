//
// Created by misha on 10/07/2020.
//
#include <string>
#include <vector>
#include <variant>
#include <iostream>

class Any {
    struct Base {
        virtual ~Base() = default;
        virtual std::unique_ptr<Base> Clone() = 0;
    };

    template <typename T>
    struct Derived : public Base {
        Derived(T value_) : value(std::move(value_)) {}

        T value;

        std::unique_ptr<Base> Clone() override {
            return std::make_unique<Derived<T>>(value);
        }
    };

    std::unique_ptr<Base> ptr_;
public:
    Any() = default;

    template<typename T>
    Any(T value) {
        ptr_ = std::make_unique<Derived<T>>(std::move(value));//make_unique - метод из класса unique_ptr
    }

    template <typename T>
    const T& get() const {
        return (dynamic_cast<const Derived<T>&>(*ptr_)).value;
    }

    Any(const Any& rhs) {
        ptr_ = rhs.ptr_->Clone();
    }
};

int main() {
    /*std::variant<std::string, std::vector<int>> v;
    v = "test";
    //std::vector<int> b(5);
    std::string s = std::get<std::string>(v);

    std::string* ptr = std::get_if<0>(v);*/

    Any a(5);
    Any b("GAGAGA");
    Any c(b);

    std::cout << c.get() ;
    //wtf?
}