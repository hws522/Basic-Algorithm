//대표적 분할정복 알고리즘.
//퀵정렬과 동일한 시간 복잡도 O(N * logN).
//최악의 경우에도 시간 복잡도 유지.
//병합정렬의 기본 아이디어는 정확히 반으로 나누고 정렬하는 것.
//기존의 데이터를 담을 추가 공간이 필요하다는 단점.
//퀵정렬보다는 느리지만 시간복잡도가 변하지 않는다는 점에서 매우 효율적.

//7 6 5 8 3 5 9 1 정렬하기.

#include<iostream>

using namespace std;

int size; int sorted[8];
int count = 0; int number = 8;

void merge(int a[], int m, int middle, int n)
{
    int i = m;
    int j = middle + 1;
    int k = m;

    while(i <= middle && j <= n) 
    {
        if(a[i] <= a[j])
        {
            sorted[k] = a[i];
            i++;
        }

        else
        {
            sorted[k] = a[j];
            j++;
        }

        k++;
    }

    if(i > middle)
    {
        for(int t = j; t <= n; t++)
        {
            sorted[k] = a[t];
            k++;
        }
    }

    else
    {
        for(int t = i; t<= middle; t++)
        {
            sorted[k] = a[t];
            k++;
        }
    }

    for(int t = m; t <= n; t++)
    {
        a[t] = sorted[t];
    }
}

void mergeSort(int a[], int m, int n)
{
    if(m < n)
    {
        int middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}



int main()
{
    int array[number] = {7, 6, 5, 8, 3, 5, 9, 1};

    mergeSort(array, 0, number - 1);

    for(int i = 0; i < number; i++)
    {
        cout << array[i] << ' ';
    }

    cout << endl;

    return 0;
}