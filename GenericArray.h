#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <stdexcept>

template <typename T>
class GenericArray {
private:
    T* data;
    size_t array_size;

public:
    GenericArray();
    ~GenericArray();
    
    void addElement(T element);
    T at(int index) const;
    size_t size() const;
    T sum() const;
    T max() const;
    T min() const;
    T* slice(int begin, int end) const;
};

template <typename T>
GenericArray<T>::GenericArray() : data(nullptr), array_size(0) {}

template <typename T>
void GenericArray<T>::addElement(T element) {
    T* new_data = new T[array_size + 1];
    for (size_t i = 0; i < array_size; ++i) {
        new_data[i] = data[i];
    }
    new_data[array_size] = element;
    if (data != nullptr) {
        delete[] data;
    }
    data = new_data;
    array_size++;
}

template <typename T>
GenericArray<T>::~GenericArray() {
    if (data != nullptr) {
        delete[] data;
    }
}

template <typename T>
T GenericArray<T>::at(int index) const {
    if (index < 0 || index >= static_cast<int>(array_size)) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
size_t GenericArray<T>::size() const {
    return array_size;
}

template <typename T>
T GenericArray<T>::max() const {
    if (array_size == 0) {
        throw std::runtime_error("Array is empty");
    }
    T max_val = data[0];
    for (size_t i = 1; i < array_size; ++i) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }
    return max_val;
}

template <typename T>
T GenericArray<T>::min() const {
    if (array_size == 0) {
        throw std::runtime_error("Array is empty");
    }
    T min_val = data[0];
    for (size_t i = 1; i < array_size; ++i) {
        if (data[i] < min_val) {
            min_val = data[i];
        }
    }
    return min_val;
}

template <typename T>
T* GenericArray<T>::slice(int begin, int end) const {
    if (begin < 0 || end >= static_cast<int>(array_size)) {
        throw std::out_of_range("Slice indices out of bounds");
    }
    if (begin > end) {
        throw std::invalid_argument("Begin index must be <= end index");
    }
    int slice_size = end - begin + 1;
    T* sliced = new T[slice_size];
    for (int i = 0; i < slice_size; ++i) {
        sliced[i] = data[begin + i];
    }
    return sliced;
}

template <typename T>
T GenericArray<T>::sum() const {
    T total = 0;
    for (size_t i = 0; i < array_size; ++i) {
        total += data[i];
    }
    return total;
}

#endif
