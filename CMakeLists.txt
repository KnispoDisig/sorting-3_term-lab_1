cmake_minimum_required(VERSION 3.16)
project(sorting_lab_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(sorting_lab_1 main.cpp Sorter.h Sequence/Sequence.h Sequence/ArraySequence/ArraySequence.cpp Sequence/ArraySequence/ArraySequence.h Sequence/ArraySequence/DynamicArray/DynamicArray.cpp Sequence/ArraySequence/DynamicArray/DynamicArray.h Sequence/ListSequence/LinkedListSequence.cpp Sequence/ListSequence/LinkedListSequence.h Sequence/ListSequence/LinkedList/LinkedList.cpp Sequence/ListSequence/LinkedList/LinkedList.h Ordering.h Test/Test.h)