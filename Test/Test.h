//
// Created by fell2 on 17.09.2020.
//

#include <cassert>
#include "../Sorter.h"
#include "../Ordering.h"

#ifndef SORTING_LAB_1_TEST_H
#define SORTING_LAB_1_TEST_H

class Test {
private:
    static void saySuccess(string test_name) {
        std::cout << test_name << " success\n";
    }

    static void sayFail(string test_name) {
        std::cout << test_name << " failed\n";
    }

    static void print_sort_info(pair<int, int> sortInfo) {
        cout << "Spent time: " << sortInfo.first << " ms\n"<< "Count of comparisons: " << sortInfo.second << "\n";
    }

public:
    static ArraySequence<int> *generateArray(int count) {
        srand(time(NULL));
        int randArray[count];

        for (int i = 0; i < count; i++) {
            randArray[i] = rand();
        }

        return new ArraySequence<int>(randArray, count);
    }

    static LinkedListSequence<int> *generateList(int count) {
        srand(time(NULL));
        int randArray[count];

        for (int i = 0; i < count; i++) {
            randArray[i] = rand();
        }

        return new LinkedListSequence<int>(randArray, count);
    }

    static void test_one_element() {
        int array[] = {1};
        LinkedListSequence<int> *sequence = new LinkedListSequence<int>(array, 1);

        BubbleSorter<int> *bubbleSorter = new BubbleSorter<int>(Ordering::int_ascending);
        MergeSorter<int> *mergeSorter = new MergeSorter<int>(Ordering::int_ascending);
        QuickSorter<int> *quickSorter = new QuickSorter<int>(Ordering::int_ascending);

        bubbleSorter->sort(sequence);
        mergeSorter->sort(sequence);
        quickSorter->sort(sequence);
        assert(sequence->get(0) == array[0]);
        saySuccess("test_one_element");
    }

    static void test_custom_array() {
        BubbleSorter<int> *bubbleSorter = new BubbleSorter<int>(Ordering::int_ascending);
        MergeSorter<int> *mergeSorter = new MergeSorter<int>(Ordering::int_ascending);
        QuickSorter<int> *quickSorter = new QuickSorter<int>(Ordering::int_ascending);

        int array0[] = {-231, 35, -4, -500, 10, 0, 70, 12, 43, -7, 313};
        Sequence<int> *sequence0_0 = new ArraySequence<int>(array0, 11);
        Sequence<int> *sequence0_1 = sequence0_0;
        Sequence<int> *sequence0_2 = sequence0_0;
        int array1[] = {-500, -231, -7, -4, 0, 10, 12, 35, 43, 70, 313};
        Sequence<int> *sequence1 = new ArraySequence<int>(array1, 11);

        bubbleSorter->sort(sequence0_0);
        mergeSorter->sort(sequence0_1);
        quickSorter->sort(sequence0_2);

        int i = 0;
        for (i = 0; i < sequence1->getLength(); i++) {
            if (!(sequence1->get(i) == sequence0_0->get(i) &&
                  sequence1->get(i) == sequence0_1->get(i) && 
                  sequence1->get(i) == sequence0_2->get(i))) {
                break;
            }
        }
        
        if (i == sequence1->getLength()) {
            saySuccess("custom_array_sequence");
        } else {
            std::cout << "custom_array_sequence failed\n";
        }
    }

    static void test_efficiency() {
        const int ARRAY_STEP = 500;
        const int INITIAL_ARRAY_COUNT = 1000;
        const int MAX_ARRAY_COUNT = 20000;

        const int LIST_STEP = 200;
        const int INITIAL_LIST_COUNT = 200;
        const int MAX_LIST_COUNT = 2500;

        auto *bubbleSorter = new BubbleSorter<int>();
        auto *mergeSorter = new MergeSorter<int>();
        auto *quickSorter = new QuickSorter<int>();

        cout << "*** TESTING ARRAY ***\n";
        for (int sorterNum = 0; sorterNum < 3; sorterNum++) {
            if (sorterNum == 0) {
                cout << "** BUBBLE SORT **\n";
                for (int count = INITIAL_ARRAY_COUNT; count < MAX_ARRAY_COUNT; count += ARRAY_STEP) {
                    cout << "Count of elements: " << count << "\n";
                    bubbleSorter->sort(generateArray(count));
                    print_sort_info(bubbleSorter->get_sort_info());
                    cout << "\n";
                }
            } else if (sorterNum == 1) {
                cout << "** MERGE SORT **\n";
                for (int count = INITIAL_ARRAY_COUNT; count < MAX_ARRAY_COUNT; count += ARRAY_STEP) {
                    cout << "Count of elements: " << count << "\n";
                    mergeSorter->sort(generateArray(count));
                    print_sort_info(mergeSorter->get_sort_info());
                    cout << "\n";
                }
            } else {
                cout << "** QUICK SORT **\n";
                for (int count = INITIAL_ARRAY_COUNT; count < MAX_ARRAY_COUNT; count += ARRAY_STEP) {
                    cout << "Count of elements: " << count << "\n";
                    quickSorter->sort(generateArray(count));
                    print_sort_info(quickSorter->get_sort_info());
                    cout << "\n";
                }
            }
        }

        cout << "*** TESTING LIST ***\n";
        for (int sorterNum = 1; sorterNum < 3; sorterNum++) {
            if (sorterNum == 0) {
                cout << "** BUBBLE SORT **\n";
                for (int count = INITIAL_LIST_COUNT; count < MAX_LIST_COUNT; count += LIST_STEP) {
                    cout << "Count of elements: " << count << "\n";
                    bubbleSorter->sort(generateList(count));
                    print_sort_info(bubbleSorter->get_sort_info());
                    cout << "\n";
                }
            } else if (sorterNum == 1) {
                cout << "** MERGE SORT **\n";
                for (int count = INITIAL_LIST_COUNT; count < MAX_LIST_COUNT; count += LIST_STEP) {
                    cout << "Count of elements: " << count << "\n";
                    mergeSorter->sort(generateList(count));
                    print_sort_info(mergeSorter->get_sort_info());
                    cout << "\n";
                }
            } else {
                cout << "** QUICK SORT **\n";
                for (int count = INITIAL_LIST_COUNT; count < MAX_LIST_COUNT; count += LIST_STEP) {
                    cout << "Count of elements: " << count << "\n";
                    quickSorter->sort(generateList(count));
                    print_sort_info(quickSorter->get_sort_info());
                    cout << "\n";
                }
            }
        }
    }

    static void test_empty_sequence() {
        auto *bubbleSorter = new BubbleSorter<int>();
        auto *mergeSorter = new MergeSorter<int>();
        auto *quickSorter = new QuickSorter<int>();
        Sequence<int> *empty_sequence = new LinkedListSequence<int>();

        bubbleSorter->sort(empty_sequence);
        mergeSorter->sort(empty_sequence);
        quickSorter->sort(empty_sequence);

        if (empty_sequence->getLength() == 0) {
            saySuccess("test_empty_sequence");
        } else {
            sayFail("test_empty_sequence");
        }
    }

    static void launch_all_tests() {
        test_one_element();
        test_custom_array();
        test_empty_sequence();
        test_efficiency();
    }
};


#endif //SORTING_LAB_1_TEST_H
