//
// Created by fell2 on 14.09.2020.
//

#include "LinkedListSequence.h"
#include "LinkedList/LinkedList.cpp"

template<class T>
LinkedListSequence<T>::LinkedListSequence(T *items, int count) {
    this->list = new LinkedList<T>(items, count);
}

template<class T>
LinkedListSequence<T>::LinkedListSequence() {
    this->list = new LinkedList<T>();
}

template<class T>
LinkedListSequence<T>::LinkedListSequence(const LinkedListSequence<T> &linkedList) {
    T* temp = new T[linkedList.getLength()];
    for (int i = 0; i < linkedList.getLength(); i++) {
        temp[i] = linkedList.get(i);
    }
    list = new LinkedList<T>(temp, linkedList.getLength());
}

template<class T>
int LinkedListSequence<T>::getLength() const {
    return this->list->getLength();
}

template<class T>
T LinkedListSequence<T>::getFirst() const {
    return this->list->getFirst();
}

template<class T>
T LinkedListSequence<T>::getLast() const {
    return this->list->getLast();
}

template<class T>
T LinkedListSequence<T>::get(const int i) const {
    return this->list->get(i);
}

template<class T>
Sequence<T> *LinkedListSequence<T>::getSubsequence(const int startIndex, const int endIndex) const {
    const int listSize = endIndex - startIndex + 1;
    LinkedList<T> *newList = this->list->getSubList(startIndex, endIndex);

    return new LinkedListSequence(newList->getItems(), listSize);
}

template<class T>
void LinkedListSequence<T>::append(T value) {
    this->list->append(value);
}

template<class T>
void LinkedListSequence<T>::prepend(T value) {
    this->list->prepend(value);
}

template<class T>
void LinkedListSequence<T>::insertAt(const int index, T value) {
    this->list->insertAt(index, value);
}

template<class T>
Sequence<T> *LinkedListSequence<T>::concat(Sequence<T> *sequence) {
    const int listSize = this->getLength() + sequence->getLength();
    T *tempArray = new T[listSize];
    int j = 0;

    for (int i = 0; i < this->getLength(); i++) {
        tempArray[j] = this->get(i);
        j++;
    }
    for (int i = 0; i < sequence->getLength(); i++) {
        tempArray[j] = sequence->get(i);
        j++;
    }

    return new LinkedListSequence(tempArray, listSize);
}

template<class T>
void LinkedListSequence<T>::print() {
    this->list->print();
}

template<class T>
void LinkedListSequence<T>::set(int index, T value) {
    this->list->set(index, value);
}