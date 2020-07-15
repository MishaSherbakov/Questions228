//
// Created by misha on 02/07/2020.
//
#include <string>

struct Block {
    int strong_count;
    int weak_count;
};

class SharedPtr {
public:
    SharedPtr() {
        obj_ = nullptr;
        counter_ = new int(1);
    }

    SharedPtr(std::string* obj) {
        obj_ = obj;
        counter_ = new Block{1, 0};
    }

    SharedPtr(const SharedPtr& ptr) {
        obj_ = ptr.obj_;
        counter_ = ptr.counter_;
        ++counter_->strong_count;
    }

    SharedPtr& operator=(SharedPtr ptr) {
        Swap(ptr);
        return *this;
    }

    void Swap(SharedPtr& ptr) {
        std::swap(obj_, ptr.obj_);
        std::swap(counter_, ptr.counter_);
    }
    ~SharedPtr() {
        if (counter_ == nullptr) {
            return;
        }
        --counter_->strong_count;
        if (counter_->strong_count == 0) {
            delete obj_;
        }
        if (counter_->strong_count + counter_->weak_count == 0) {
            delete counter_;
        }
    }

    SharedPtr(SharedPtr&& ptr) {
        obj_ = ptr.obj_;
        counter_ = ptr.counter_;
        ptr.obj_ = nullptr;
        ptr.counter_ = nullptr;
    }

    std::string* Get() {
        return obj_;
    };

    std::string& operator*() {
        return *obj_;
    }

    std::string *operator->() {
        return obj_; // b -> size() "(b.operator->())->size()" - то,что происходит на самом деле
    }
private:
    std::string* obj_;
    Block* counter_;

    friend class WeakPtr;
};

class WeakPtr {
public:
    WeakPtr(std::string*) = delete;
    WeakPtr(const SharedPtr& ptr) {
// Здесь нужно кинуть исключение на nullptr ptr
        obj_ = ptr.obj_;
        counter_ = ptr.counter_;
        ++counter_->weak_count;
    }

    bool Expired() const {
        return counter_->strong_count == 0;
    }

    SharedPtr Lock() {
        if (Expired()) {
            return SharedPtr();
        }
        return SharedPtr(*this);//В SharedPtr нужно дописать конструктор с WeakPtr
    }
private:
    std::string* obj_;
    Block* counter_;
};