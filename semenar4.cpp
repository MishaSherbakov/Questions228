//
// Created by misha on 30/06/2020.
//
#include <>
class Array {
public:
    explicit Array(size_t size, int value = 0) { //explicit нужен,чтобы конструктор автоматически не преобразовывал int в size_t(например)
        data_ = new int[size]; // объявление массива int-ов размера size
        size_ = size;
        for (size_t i = 0; i < size; ++i) {
            data_[i] = value;
        }
    }

    Array(const Array& rhs) /* : Array(rhs.size_) проинициализирует data_ и size_ автоматически */  {
        data_ = new int[rhs.size_];
        size_ = rhs.size;
        for (size_t i = 0; i < size_ ; ++i) {
            data_[i] = rhs.data_[i];
        }
    }

    /*Array& operator = (const Array& rhs) {
        if (this == &rhs) {
            return *this;
        }
        delete[] data_;
        data_ = new int[rhs.size_];
        size_ = rhs.size_;
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = rhs.data_[i];
        }
        return *this;
    } */

    Array& operator=(Array rhs) {
        delete[] data_;
        data_ = rhs.data_;
        size_ = rhs.size_;
        rhs.data_ = nullptr;
        return *this;
    }

    Array(Array&& rhs) {
        data_ = rhs.data_;
        size_ = rhs.size_;
        rhs data_ = nullptr;
    }

    size_t Size() const {
        return size_;
    }
    ~Array() {
        delete[] data_;
    }

    class Iterator {
    public:
        Iterator(int *ptr) {
            ptr_ = ptr;
        }

        Iterator& operator++() {
            ++ptr_;
            return *this;
        }

        Iterator operator++(int) {
            Iterator cpy(*this);
            ++ptr_;
            return cpy;
        }

        int& operator*() {
            return *ptr_;
        }

        bool operator==(const Iterator& rhs) const {
            return ptr_ == rhs.ptr_;
        }
    private:
        int* ptr_;
    };

    Iterator begin() {
        return Iterator(data_);
    }

    Iterator end() {
        return Iterator(data_ + size_);
    }

private:
    int* data_;
    size_t size_;
};

int main() {
    Array a(5);
    Array b(a);
    Array c(std::move(b))
    return 0;
    a = b; // b останется жив
    c = std::move(a); // а умрет
}