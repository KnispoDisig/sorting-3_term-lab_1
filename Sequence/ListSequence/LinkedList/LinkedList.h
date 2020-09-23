//
// Created by fell2 on 14.09.2020.
//

#ifndef SORTING_LAB_1_LINKEDLIST_H
#define SORTING_LAB_1_LINKEDLIST_H

template<typename T>
class LinkedList {
private:
    typedef struct Element {
        T value;
        Element *next;
    } Element;

    Element *head;
    int count{};
public:
    LinkedList(T *items, int count);

    LinkedList();

    LinkedList(const LinkedList<T> &list);

    T getFirst();

    T getLast();

    T get(int index);

    LinkedList<T> *getSubList(int startIndex, int endIndex);

    int getLength();

    void append(T item);

    void prepend(T item);

    void set(int index, T value);

    void insertAt(int index, T item);

    LinkedList<T> *concat(LinkedList<T> *list);

    void print();

    T *getItems();

    ~LinkedList() = default;
};


#endif //SORTING_LAB_1_LINKEDLIST_H
