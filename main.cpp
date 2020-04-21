#include "ReadWriter.h"
#include "MergeSort.h"
//iostream, fstream включены в ReadWriter.h

//Не рекомендуется добавлять собственные вспомогательные классы и методы.
//Необходимо использовать уже имеющиеся классы и методы, добавив реализацию, соответствующую описанию.
using namespace std;

//Описание методов на английском языке имеется в классе MergeSort, в файле MergeSort.h
void MergeSort::sort(int *arr, int length)
{
    divide_and_merge(arr, 0, length - 1);
}

void MergeSort::merge(int* arr, int first, int second, int end)
{
    int left_size = second - first + 1, right_size = end - second, k;
    int *leftArr = new int[left_size];
    int *rightArr = new int[right_size];

    for (int i = 0; i < left_size; i++)
    {
        leftArr[i] = arr[first + i];
    }

    for (int i = 0; i < right_size; i++)
    {
        rightArr[i] = arr[second + i + 1];
    }

    int left_index = 0, right_index = 0;
    for (k = first; left_index < left_size && right_index < right_size; k++)
    {
        if (leftArr[left_index] < rightArr[right_index])
            arr[k] = leftArr[left_index++];
        else
            arr[k] = rightArr[right_index++];
    }

    while (left_index < left_size)
        arr[k++] = leftArr[left_index++];

    while (right_index < right_size)
        arr[k++] = rightArr[right_index++];

    delete[] leftArr;
    delete[] rightArr;
}

void MergeSort::divide_and_merge(int *arr, int left, int right)
{
    int middle;
    if (left < right)
    {
        middle = (left + right) / 2;
        divide_and_merge(arr, left, middle);
        divide_and_merge(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main()
{
    ReadWriter rw;

    int *brr = nullptr;
    int length;

    //Read data from file
    length = rw.readInt();

    brr = new int[length];
    rw.readArray(brr, length);

    //Start sorting
    MergeSort s;

    s.sort(brr, length);

    //Write answer to file
    rw.writeArray(brr, length);

    delete[] brr;

    return 0;
}
