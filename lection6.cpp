//
// Created by misha on 02/07/2020.
//
#include <string>
#include <vector>
#include <iostream>
#include <optional>
#include <algorithm>

template <typename Iterator, typename Callback, typename Predicate>
void ForeachIf(Iterator first, Iterator last, Callback callback, Predicate predicate) {
    while (first != last) {
        if (predicate(*first)) {
            callback(*first);
        }
        ++first;
    }
}

void Increment(int& value) {
    ++value;
}

class Functor {
public:
    explicit Functor(std::vector<int>* data): data_(data) {}

    void operator()(int value) {
        data_->push_back(value);
    }
private:
    std::vector<int>* data_;
};

template <class Key, class Value>
class StaticMap {
public:
    using Pair = std::pair<Key, Value>;
    explicit StaticMap(const std::vector<std::pair<Key, Value>>& data): data_(data) {
        std::sort(data_.begin(), data_.end(), [](const Pair& lhs, const Pair& rhs){return lhs.first < rhs.first;});
    }

    std::optional<Value> Get(const Key& key) const {
        if (cache_.key && *cache_.key == key) {
            return *(cache_.value);
        }
        auto it = std::lower_bound(data_.begin(), data_.end(), key, [](const Key& lhs, const Pair& rhs) {
            return lhs < rhs.first;
            });
        if (it == data_.end() || it->first != key) {
            return std::nullopt;
        }
        cache_.key = &it->first;
        cache_.value = &it->second;
        return it->second;
    }
private:
    std::vector<std::pair<Key, Value>> data_;

    struct Cache {
        const Key* key = nullptr;
        const Value* value = nullptr;
    };

    mutable Cache cache_;// в конст методе мы можем менять cache_
};

/*template<typename T>
void Swap(T& x, T& y) {
    T t = x;
    x = y;
    y = t;
}

template <>
void Swap<std::string>(std::string& x, std::string& y) {
    std::string t = std::move(x);
    x = std::move(y);
    y = std::move(t);
} //Просто перегрузить функцию нельзя */

int main() {
  /*  std::vector<std::string> a;
    a.reserve(32);// Мы взаранее устанавливаем размер вектора
    a.push_back(6);// Элементт где-то создается и копируется в конец вектора
    a.emplace_back(6);// Элемент создается прямо в конце вектора */


    std::vector<int> data{1, 3, 4, 6};
    std::vector<int> odd_elements;
    ForeachIf(data.begin(), data.end(), /*Functor(&odd_elements)*/ [&odd_elements](int value) {odd_elements.push_back(value);}, [](int value) -> bool { return value % 2 == 1;});
}