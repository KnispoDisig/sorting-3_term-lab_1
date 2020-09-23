#include <iostream>
#include "string"
#include "Sorter.h"
#include "Sequence/ListSequence/LinkedListSequence.cpp"
#include "Sequence/ArraySequence/ArraySequence.cpp"
#include "Ordering.h"
#include "cstdlib"
#include "Test/Test.h"

void hello_world() {
    cout << R"(
  _           _       _  _  __    _____            _   _
 | |         | |    _| || |/_ |  / ____|          | | (_)
 | |     __ _| |__ |_  __  _| | | (___   ___  _ __| |_ _ _ __   __ _
 | |    / _` | '_ \ _| || |_| |  \___ \ / _ \| '__| __| | '_ \ / _` |
 | |___| (_| | |_) |_  __  _| |  ____) | (_) | |  | |_| | | | | (_| |
 |______\__,_|_.__/  |_||_| |_| |_____/ \___/|_|   \__|_|_| |_|\__, |
                                                                __/ |
                                                               |___/
                                                                        )" << "\n";
}

string firstWord(string str) {
    std::string word;
    int i = 0;
    while (str[i] != ' ' && i != str.length()) {
        word += str[i];
        i++;
    }
    return word;
}

void removeFirstWord(string *str) {
    int i = 0;
    while ((*str)[i] != ' ' && i != (*str).length()) {
        i++;
    }
    if (i == (*str).length()) {
        (*str) = "";
    } else {
        (*str).erase(0, i + 1);
    }
}

void println(string str) {
    std::cout << str << "\n";
}

void print(string str) {
    std::cout << str;
}

void print_info() {
    println("sorting  -  create array/list of integers and sort it");
    println("test  -  launching the module tests");
    println("random  -  create random array/list of integers and sort it");
    println("end  -  finish the program");
}

bool array_or_list() {
    string kind;
    println("Please, choose implementation: \n- array\n- list");
    do {
        getline(cin, kind);
    } while (kind != "array" && kind != "list");

    return kind == "array";
}

ArraySequence<int> *make_array(int count) {
    string line;
    int array[count];
    println("Enter the array");
    println("Example: 1 -34 100 0 9");

    getline(cin, line);

    for (int i = 0; i < count; i++) {
        array[i] = stoi(firstWord(line));
        removeFirstWord(&line);
    }

    return new ArraySequence<int>(array, count);
}

LinkedListSequence<int> *make_list(int count) {
    string line;
    int list[count];
    println("Enter the list");
    println("Example: 1 -34 100 0 9");

    getline(cin, line);

    for (int i = 0; i < count; i++) {
        list[i] = stoi(firstWord(line));
        removeFirstWord(&line);
    }

    return new LinkedListSequence<int>(list, count);
}

int choose_count_of_elements() {
    int count;
    string helperLine;
    println("Please, enter the count of elements");
    getline(cin, helperLine);
    count = stoi(helperLine);
    return count;
}

void print_sort_info(pair<int, int> sortInfo) {
    print("Spent time: ");
    cout << sortInfo.first << " ms\n";
    print("Count of comparisons: ");
    cout << sortInfo.second << "\n";
}

string choose_sorting_kind() {
    string kind;
    println("Choose the kind of sorting (enter the word): ");
    println("- bubble\n- merge\n- quick");
    getline(cin, kind);
    return kind;
}


int main() {
    hello_world();

    string request;
    pair<int, int> sorting_info;

    do {
        print_info();
        println("Enter the request: ");
        getline(cin, request);

        if (request == "test") {
            Test::launch_all_tests();

        } else if (request == "sorting") {
            string kind;
            do {
                kind = choose_sorting_kind();

                if (kind == "bubble") {
                    auto *bubbleSorter = new BubbleSorter<int>(Ordering::int_ascending);
                    if (array_or_list()) {
                        Sequence<int> *arraySequence = make_array(choose_count_of_elements());
                        bubbleSorter->sort(arraySequence);
                        sorting_info = bubbleSorter->get_sort_info();
                        println("Sorted array: ");
                        arraySequence->print();
                    } else {
                        Sequence<int> *listSequence = make_list(choose_count_of_elements());
                        bubbleSorter->sort(listSequence);
                        sorting_info = bubbleSorter->get_sort_info();
                        println("Sorted list: ");
                        listSequence->print();
                    }
                } else if (kind == "merge") {
                    auto *mergeSorter = new MergeSorter<int>(Ordering::int_ascending);
                    if (array_or_list()) {
                        Sequence<int> *arraySequence = make_array(choose_count_of_elements());
                        mergeSorter->sort(arraySequence);
                        sorting_info = mergeSorter->get_sort_info();
                        println("Sorted array: ");
                        arraySequence->print();
                    } else {
                        Sequence<int> *listSequence = make_list(choose_count_of_elements());
                        mergeSorter->sort(listSequence);
                        sorting_info = mergeSorter->get_sort_info();
                        println("Sorted list: ");
                        listSequence->print();
                    }
                } else if (kind == "quick") {
                    auto *quickSorter = new QuickSorter<int>(Ordering::int_ascending);
                    if (array_or_list()) {
                        Sequence<int> *arraySequence = make_array(choose_count_of_elements());
                        quickSorter->sort(arraySequence);
                        sorting_info = quickSorter->get_sort_info();
                        println("Sorted array: ");
                        arraySequence->print();
                    } else {
                        Sequence<int> *listSequence = make_list(choose_count_of_elements());
                        quickSorter->sort(listSequence);
                        sorting_info = quickSorter->get_sort_info();
                        println("Sorted list: ");
                        listSequence->print();
                    }

                } else {
                    println("");
                    println("Wrong input, try one more time");
                }

                if (kind == "bubble" || kind == "merge" || kind == "quick") {
                    println("");
                    print_sort_info(sorting_info);
                }
            } while (!(kind == "bubble" || kind == "merge" || kind == "quick"));

        } else if (request == "random") {
            string kind = choose_sorting_kind();
            int count = choose_count_of_elements();
            do {
                if (kind == "bubble") {
                    auto *bubbleSorter = new BubbleSorter<int>(Ordering::int_ascending);
                    if (array_or_list()) {
                        Sequence<int> *arraySequence = Test::generateArray(count);
                        bubbleSorter->sort(arraySequence);
                        sorting_info = bubbleSorter->get_sort_info();
                        println("Sorted array: ");
                        arraySequence->print();
                    } else {
                        Sequence<int> *listSequence = Test::generateList(count);
                        bubbleSorter->sort(listSequence);
                        sorting_info = bubbleSorter->get_sort_info();
                        println("Sorted array: ");
                        listSequence->print();
                    }
                } else if (kind == "merge") {
                    auto *mergeSorter = new MergeSorter<int>(Ordering::int_ascending);
                    if (array_or_list()) {
                        Sequence<int> *arraySequence = Test::generateArray(count);
                        mergeSorter->sort(arraySequence);
                        sorting_info = mergeSorter->get_sort_info();
                        println("Sorted array: ");
                        arraySequence->print();
                    } else {
                        Sequence<int> *listSequence = Test::generateList(count);
                        mergeSorter->sort(listSequence);
                        sorting_info = mergeSorter->get_sort_info();
                        println("Sorted array: ");
                        listSequence->print();
                    }
                } else if (kind == "quick") {
                    auto *quickSorter = new QuickSorter<int>(Ordering::int_ascending);
                    if (array_or_list()) {
                        Sequence<int> *arraySequence = Test::generateArray(count);
                        quickSorter->sort(arraySequence);
                        sorting_info = quickSorter->get_sort_info();
                        println("Sorted array: ");
                        arraySequence->print();
                    } else {
                        Sequence<int> *listSequence = Test::generateList(count);
                        quickSorter->sort(listSequence);
                        sorting_info = quickSorter->get_sort_info();
                        println("Sorted array: ");
                        listSequence->print();
                    }
                } else {
                    println("");
                    println("Wrong input, try one more time");
                }

                if (kind == "bubble" || kind == "merge" || kind == "quick") {
                    println("");
                    print_sort_info(sorting_info);
                }

            } while (!(kind == "bubble" || kind == "merge" || kind == "quick"));
        }

        println("");
    } while (request != "end");

}
