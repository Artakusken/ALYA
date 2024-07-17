#include "alya.hpp"
#include <iostream>
#include <chrono>

namespace alya {
    template <typename Value1, typename Value2>
    void Print(Value1 first, Value2 second, const char* end) {
        if (!second) {std::cout << first << end;}
        else {std::cout << first << " " << second << end;}
    }

    template <typename Value>
    void ArrayPrint(Value* arr, unsigned int len, unsigned int start) {
        for (int i=start; i<len; i++) {
            Print<Value>(arr[i], 0, " ");
        }
        std::cout << "\n";
    }

    template <typename Value>
    void MySwap(Value* arr, unsigned int left, unsigned int right) {  // 47 13
        arr[right] += arr[left];  // 47 60
        arr[left] = arr[right] - arr[left];  // 13 60
        arr[right] -= arr[left];  // 13 47
    }

    template <typename Value>
    Value* BubbleSort(Value* arr, unsigned int len, bool reversed) { // Всё, это - база. Фундамент.
        if (!reversed) {
            for (unsigned int i = 0; i < len-1; i++) {
                for (unsigned int j = 0; j < len-1-i; j++) {
                    if (arr[j] > arr[j+1]) {
                        MySwap(arr, j, j+1);
                    }
                }
            }
        }
        else {
            for (unsigned int i = len-1; i > 0; i--) {
                for (unsigned int j = 0; j < i-1; j++) {
                    if (arr[j] < arr[j+1]) {
                        MySwap(arr, j, j+1);
                    }
                }
            }
        }
        return arr;
    }

    template <typename Value>
    Value* SelectionSort(Value* arr, unsigned int len, bool reversed) {
        if (!reversed) {
            int min_val;
            int min;
            for (unsigned int i = 0; i < len - 1; i++) {
                min_val = arr[i];
                min = i;
                for (unsigned int j = i + 1; j < len; j++) {
                    if (arr[j] < min_val) {
                        min_val = arr[j];
                        min = j;
                    }
                }
                if (min != i) {
                    MySwap(arr, i, min);
                }
            }
        }
        else {
            int max_val;
            int max;
            for (int i = 0; i < len - 1; i++) {
                max_val = arr[i];
                max = i;
                for (unsigned int j = i + 1; j < len; j++) {
                    if (arr[j] > max_val) {
                        max_val = arr[j];
                        max = j;
                    }
                }
                if (max != i) {
                    MySwap(arr, i, max);
                }
            }
        }
        return arr;
    }

    template <typename Value>
    Value* ShakerSort(Value* arr, unsigned int len, bool reversed) {
        unsigned int left = 0;
        unsigned int right = len-1;
        bool ok;
        if (!reversed) {
            for (unsigned int i = 0; i < right; i++) {
                ok = true;
                for (unsigned int j = i; j < right; j++) {
                    if (arr[j] > arr[j+1]) {
                        MySwap(arr, j, j+1);
                        ok = false;
                    }
                }
                if (ok) {break;}
                ok = true;
                right--;
                i = right;
                for (unsigned int j = i; j > left; j--) {
                    if (arr[j] < arr[j-1]) {
                        MySwap(arr, j-1, j);
                        ok = false;
                    }
                }
                if (ok) { break;}
                i = left;
                left++;
            }
        }
        else {
            for (unsigned int i = 0; i < right; i++) {
                ok = true;
                for (unsigned int j = i; j < right; j++) {
                    if (arr[j] < arr[j+1]) {
                        MySwap(arr, j, j+1);
                        ok = false;
                    }
                }
                if (ok) {break;}
                ok = true;
                right--;
                i = right;
                for (unsigned int j = i; j > left; j--) {
                    if (arr[j] > arr[j-1]) {
                        MySwap(arr, j-1, j);
                        ok = false;
                    }
                }
                if (ok) { break;}
                i = left;
                left++;
            }
        }
        return arr;
    }

    template <typename Value>
    Value* QuickSort(Value* arr, unsigned int start, unsigned int end, bool reversed) {
        if (start < end) {
            if (!reversed) {
                Value baza = (arr[(end + start) / 2] + arr[start] + arr[end - 1]) / 3;
                unsigned int eless = start;
                unsigned int bigger = end;
                while (true) {
                    while (arr[eless] < baza) { eless++; }  // Пропускаем элементы в левой части, которые < опорного элемента
                    while (arr[bigger] > baza) { bigger--; }  // Пропускаем элементы в правой части, которые > опорного элемента
                    if (eless >= bigger) {
                        break;
                    }
                    MySwap(arr, eless, bigger);
                }
                QuickSort(arr, start, bigger);
                QuickSort(arr, bigger + 1, end);
            }
            else {
                int baza = (arr[(end + start) / 2] + arr[start] + arr[end - 1]) / 3;
                unsigned int eless = start;
                unsigned int bigger = end;
                while (true) {
                    while (arr[eless] >
                           baza) { eless++; }  // Пропускаем элементы в левой части, которые < опорного элемента
                    while (arr[bigger] <
                           baza) { bigger--; }  // Пропускаем элементы в правой части, которые > опорного элемента
                    if (eless >= bigger) {
                        break;
                    } else { MySwap(arr, bigger, eless); }
                }
                QuickSort(arr, start, bigger, true);
                QuickSort(arr, bigger + 1, end, true);
            }
        }
        return arr;
    }

    template <typename Value>
    Value* InsertionSort(Value* arr, unsigned int len, bool reversed) {
        Value key;
        if (!reversed) {
            for (unsigned int i = 1; i < len; i++) {
                key = arr[i];
                unsigned int j = i;
                while (j > 0 and arr[j - 1] > key) {  // сдвиг вправо всех отсортированных элементов больших key
                    arr[j] = arr[j - 1];
                    j--;
                }
                arr[j] = key;  // вставка элемента из неотсортрованной части массива в отсортированную
            }
        }
        else {
            for (unsigned int i = 1; i < len; i++) {
                key = arr[i];
                unsigned int j = i;
                while (j > 0 and arr[j - 1] < key) {  // сдвиг вправо всех отсортированных элементов меньших key
                    arr[j] = arr[j - 1];
                    j--;
                }
                arr[j] = key;  // вставка элемента из неотсортрованной части массива в отсортированную
            }
        }
        return arr;
    }

    template <typename Value>
    Value* ShellSort(Value* arr, unsigned int len, bool reversed) {
        if (!reversed) {
            for (unsigned int d = len / 2; d > 0; d /= 2) {
                for (unsigned int i = d; i < len; ++i) {
                    for (int j = i - d; j >= 0 and arr[j] > arr[j + d]; j -= d) {
                        MySwap(arr, j, j + d);
                    }
                }
            }
        }
        else {
            for (unsigned int d = len / 2; d > 0; d /= 2) {
                for (unsigned int i = d; i < len; ++i) {
                    for (int j = i - d; j >= 0 and arr[j] < arr[j + d]; j -= d) {
                        MySwap(arr, j, j + d);
                    }
                }
            }
        }
        return arr;
    }

    template <typename Value>
    Value* ShellSortModified(Value* arr, unsigned int len, unsigned int* steps, unsigned int steps_len, bool reversed) {
        if (!reversed) {
            for (unsigned int s = steps_len; s > 0; s--) {
                unsigned int d = steps[s-1];
                for (unsigned int i = d; i < len; ++i) {
                    for (int j = i - d; j >= 0 and arr[j] > arr[j + d]; j -= d) {
                        MySwap(arr, j, j + d);
                    }
                }
            }
        }
        else {
            for (unsigned int s = steps_len; s > 0; s--) {
                unsigned int d = steps[s-1];
                for (unsigned int i = d; i < len; ++i) {
                    for (int j = i - d; j >= 0 and arr[j] < arr[j + d]; j -= d) {
                        MySwap(arr, j, j + d);
                    }
                }
            }
        }
        return arr;
    }

    template <typename Value>
    Value* MergeSort(Value* arr, unsigned int len, bool reversed) {
        if (len < 2) {return arr;}
        unsigned int i=0;
        unsigned int left_len = len/2;
        unsigned int right_len = len - left_len;
        Value left[left_len];
//        auto* left = new Value[left_len];
//        for (auto i = 0; i < left_len; i++)
//            left[i] = arr[i];
        while (i < left_len) {
            left[i] = arr[i];
            i++;
        }
        Value right[right_len];
//        auto* right = new Value[right_len];
//        for (auto i = 0; i < len; i++)
//            right[i] = arr[i+left_len];
        while (i < len) {
            right[i-left_len] = arr[i];
            i++;
        }
        Value* sorted_left = MergeSort(left, left_len, reversed);
        Value* sorted_right = MergeSort(right, right_len, reversed);
        i = 0;
        unsigned int j = 0, k = 0;
        if (!reversed)  {
            while (i < left_len and j < right_len) {
                if (sorted_left[i] <= sorted_right[j]) {arr[k] = sorted_left[i]; i++;}
                else {arr[k] = sorted_right[j]; j++;}
                k++;
            }
            while (i < left_len) {
                arr[k] = sorted_left[i]; i++; k++;
            }
            while (j < right_len) {
                arr[k] = sorted_right[j]; j++; k++;
            }
        }
        else {
            while (i < left_len and j < right_len) {
                if (sorted_left[i] >= sorted_right[j]) {arr[k] = sorted_left[i]; i++;}
                else {arr[k] = sorted_right[j]; j++;}
                k++;
            }
            while (i < left_len) {
                arr[k] = sorted_left[i]; i++; k++;
            }
            while (j < right_len) {
                arr[k] = sorted_right[j]; j++; k++;
            }
        }
//        delete[] left;
//        delete[] right;
        return arr;
    }

    template <typename Value>
    Value* HeapSort(Value* arr, unsigned int len, bool reversed) {
        for (unsigned int i = len/2; i < len; i--) {
            Heapify(arr, len, i, reversed);
        }
        for (unsigned int i = len-1; i > 0; i--) {
            MySwap(arr, 0, i);
            len--;
            Heapify(arr, len, 0, reversed);
        }
        return arr;
    }

    template <typename Value>
    void Heapify(Value* arr, unsigned int len, unsigned int index, bool reversed) {
        unsigned int left = 2*index+1;
        unsigned int right = left+1;
        unsigned int max=index;
        if (!reversed) {
            if (left < len and arr[left] > arr[index]) {
                max = left;
            }
            if (right < len and arr[right] > arr[max]) {
                max = right;
            }
        }
        else {
            if (left < len and arr[left] < arr[index]) {
                max = left;
            }
            if (right < len and arr[right] < arr[max]) {
                max = right;
            }
        }
        if (max != index) {
            MySwap(arr, index, max);
            Heapify(arr, len, max, reversed);
        }
    }
}

template <typename Value>
void Check(Value arr[], unsigned int len) {
    Value new_arr[len];
    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
    alya::Print("BubbleSort: ", 0, ""); alya::ArrayPrint<Value>(alya::BubbleSort(new_arr, len), len);
    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
//    alya::ArrayPrint<Value>(new_arr, len);
    alya::Print("SelectionSort: ", 0, ""); alya::ArrayPrint<Value>(alya::SelectionSort(new_arr, len), len);
    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
//    alya::ArrayPrint<Value>(new_arr, len);
    alya::Print("ShakerSort: ", 0, ""); alya::ArrayPrint<Value>(alya::ShakerSort(new_arr, len), len);
    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
//    alya::ArrayPrint<Value>(new_arr, len);
    alya::Print("InsertionSort: ", 0, ""); alya::ArrayPrint<Value>(alya::InsertionSort(new_arr, len), len);
    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
//    alya::ArrayPrint<Value>(new_arr, len);
    alya::Print("ShellSort: ", 0, ""); alya::ArrayPrint<Value>(alya::ShellSort(new_arr, len), len);
    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
//    alya::ArrayPrint<Value>(new_arr, len);
    alya::Print("QuickSort: ", 0, ""); alya::ArrayPrint<Value>(alya::QuickSort(new_arr, 0, len), len);
    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
//    alya::ArrayPrint<Value>(new_arr, len);
    alya::Print("MergeSort: ", 0, ""); alya::ArrayPrint<Value>(alya::MergeSort(new_arr, len), len);
    for (unsigned int i=0; i < len; i++) {new_arr[i] = arr[i];}
//    alya::ArrayPrint<Value>(new_arr, len);
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
    std::cout << "Time of sorting: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " milliseconds" << std::endl;
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