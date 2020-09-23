//
// Created by fell2 on 14.09.2020.
//

#ifndef SORTING_LAB_1_ORDERING_H
#define SORTING_LAB_1_ORDERING_H

class Ordering {
public:
    static bool int_ascending(int n1, int n2) {
        return n1 >= n2;
    }

    static bool int_descending(int n1, int n2) {
        return n1 <= n2;
    }

    static bool double_ascending(double n1, double n2) {
        return n1 >= n2;
    }

    static bool double_descending(double n1, double n2) {
        return n1 <= n2;
    }
};

#endif //SORTING_LAB_1_ORDERING_H
