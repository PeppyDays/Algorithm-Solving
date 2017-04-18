#include <iostream>
using namespace std;

void mergeSort(int* array, int start, int end);

int main() {
    int array[5] = {3, 1, 5, 0, 2};
    mergeSort(array, 0, 5);

    for (int i = 0; i < 5; ++i)
        cout << array[i] << ' ';

    return 0;
}

void mergeSort(int* array, int left, int right) {
    int mid = (left + right) / 2;

    if (left < right - 1) {
        mergeSort(array, left, mid);
        mergeSort(array, mid, right);

        int li = left, ri = mid, ti = 0;
        int tempArray[right - left];

        while (li < mid && ri < right) {
            if (array[li] < array[ri])
                tempArray[ti++] = array[li++];
            else
                tempArray[ti++] = array[ri++];
        }

        if (li == mid) {
            while (ri < right)
                tempArray[ti++] = array[ri++];
        }
        else {
            while (li < mid)
                tempArray[ti++] = array[li++];
        }

        for (int i = left; i < right; i++)
            array[i] = tempArray[i - left];
    }

    return;
}
