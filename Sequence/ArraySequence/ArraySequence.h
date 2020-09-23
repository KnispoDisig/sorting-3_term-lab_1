//
// Created by fell2 on 14.09.2020.
//

#include "../Sequence.h"
#include "DynamicArray/DynamicArray.h"

#ifndef SORTING_LAB_1_ARRAYSEQUENCE_H
#define SORTING_LAB_1_ARRAYSEQUENCE_H

template<class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> *array;
public:
    ArraySequence(T *items, int count);

    ArraySequence();

    ArraySequence(const ArraySequence<T> &list);

    void print() override;

    int getLength() const override;

    T getFirst() const override;

    T getLast() const override;

    T get(const int i) const override;

    Sequence<T> *getSubsequence(const int startIndex, const int endIndex) const override;

    void append(T value) override;

    void prepend(T value) override;

    void insertAt(const int index, T value) override;

    virtual Sequence<T> *concat(Sequence<T> *list) override;

    virtual void set(int index, T value) override;

    ~ArraySequence() = default;
};



#endif //SORTING_LAB_1_ARRAYSEQUENCE_H
