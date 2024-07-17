#pragma once
#include <iostream>

//extern "C" {
//    template <typename Value1, typename Value2>
//    __declspec(dllexport) void Print(Value1 first, Value2 second=0, const char* end="\n");
//}

namespace alya {
    template <typename Value1, typename Value2>
    void Print(Value1 first, Value2 second=0, const char* end="\n");

    template <typename Value>
    void ArrayPrint(Value* arr, unsigned int len, unsigned int start=0);

    template <typename Value>
    void MySwap(Value* arr, unsigned int left, unsigned int right);

    template <typename Value>
    Value* MergeSort(Value* arr, unsigned int len, bool reversed= false);

    template <typename Value>
    Value* BubbleSort(Value* arr, unsigned int len, bool reversed=false);

    template <typename Value>
    Value* SelectionSort(Value* arr, unsigned int len, bool reversed=false);

    template <typename Value>
    Value* ShakerSort(Value* arr, unsigned int len, bool reversed=false);

    template <typename Value>
    Value* QuickSort(Value* arr, unsigned int start, unsigned int end, bool reversed=false);

    template <typename Value>
    Value* InsertionSort(Value* arr, unsigned int len, bool reversed=false);

    template <typename Value>
    Value* ShellSort(Value* arr, unsigned int len, bool reversed=false);

    template <typename Value>
    Value* ShellSortModified(Value* arr, unsigned int len, unsigned int* steps, unsigned int steps_len, bool reversed=false);

    template <typename Value>
    Value* HeapSort(Value* arr, unsigned int len, bool reversed=false);

    template <typename Value>
    void Heapify(Value* arr, unsigned int len, unsigned int index, bool reversed=false);
}