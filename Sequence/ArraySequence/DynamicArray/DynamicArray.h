//
// Created by fell2 on 14.09.2020.
//

#ifndef SORTING_LAB_1_DYNAMICARRAY_H
#define SORTING_LAB_1_DYNAMICARRAY_H

template<class T>
class DynamicArray {
private:
    T *items;
    int count{};
public:
    DynamicArray();

    DynamicArray(T *items, int count);

    DynamicArray(int count);

    DynamicArray(const DynamicArray<T> &dynamicArray);

    T get(int index);

    int getSize();

    T *getItems();

    DynamicArray<T> *getSubArray(int startIndex, int endIndex);

    void set(int index, T value);

    void resize(int newSize);

    void print();

    ~DynamicArray() = default;
};


#endif //SORTING_LAB_1_DYNAMICARRAY_H
