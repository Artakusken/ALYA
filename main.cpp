#include "iostream"
#include "library/alya.hpp"
#include <chrono>

#pragma comment(lib, "alya.lib")

template <typename Value>
void Check(Value arr[], unsigned int len) {
    Value new_arr[len];
    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
    alya::Print("BubbleSort: ", 0, ""); alya::ArrayPrint<Value>(alya::BubbleSort(new_arr, len), len);

    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
    alya::Print("SelectionSort: ", 0, ""); alya::ArrayPrint<Value>(alya::SelectionSort(new_arr, len), len);

    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
    alya::Print("ShakerSort: ", 0, ""); alya::ArrayPrint<Value>(alya::ShakerSort(new_arr, len), len);

    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
    alya::Print("InsertionSort: ", 0, ""); alya::ArrayPrint<Value>(alya::InsertionSort(new_arr, len), len);

    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
    alya::Print("ShellSort: ", 0, ""); alya::ArrayPrint<Value>(alya::ShellSort(new_arr, len), len);

    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
    alya::Print("QuickSort: ", 0, ""); alya::ArrayPrint<Value>(alya::QuickSort(new_arr, 0, len), len);

    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
    alya::Print("MergeSort: ", 0, ""); alya::ArrayPrint<Value>(alya::MergeSort(new_arr, len), len);

    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
    alya::Print("HeapSort: ", 0, ""); alya::ArrayPrint<Value>(alya::HeapSort(new_arr, len), len);
}

void BigArraySort() {
    const int size = 500'000;
    int* randomNumbers = new int[size];

    for (int i = 0; i < size; ++i) {
        randomNumbers[i] = rand() % 500000;
    }

    auto start = std::chrono::high_resolution_clock::now();
    alya::InsertionSort(randomNumbers, size);
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "Time taken by someFunction: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " milliseconds" << std::endl;
}

int main() {
    int array_random1[] = {121, 12, 56, 47, 505, 435, 345, 7, 80 , 897, 200, 0, -2390};
    float array_random2[] = {-595.1181,1693.1444,-1032.6443,1167.0169,1154.3723,1440.2057,1478.5260,775.7770,125.0442,979.3221};
    int array_random3[] = {1407,3040,8085,7039,8764,5056,4412,7608,4771,8309,3500,3041};
    int array_random4[] = {-4585,-4495,-3568,-3126,-956,-739,1397,1452,2155,3487,3524,3624};
    int array_random5[] = {4365,3899,2683,1792,1141,1136,861,-2271,-2549,-2992,-3631,-4288};

    alya::Print("Array of random integer", 0);
    Check(array_random1, sizeof(array_random1)/sizeof(array_random1[0]));
    alya::Print("Array of random float", 0);
    Check(array_random2, sizeof(array_random2)/sizeof(array_random2[0]));
    alya::Print("Array of random unsigned integer", 0);
    Check(array_random3, sizeof(array_random3)/sizeof(array_random3[0]));
    alya::Print("Array of ordered integer", 0);
    Check(array_random4, sizeof(array_random4)/sizeof(array_random4[0]));
    alya::Print("Array of inverse ordered integer", 0);
    Check(array_random5, sizeof(array_random5)/sizeof(array_random5[0]));

    BigArraySort();
}