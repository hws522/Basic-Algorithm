//시간 복잡도 O(N^2) 인 정렬들은 데이터 갯수가 10만개만
//넘어가도 사용하기가 어려움. 더 빠른 알고리즘이 필요.
//대표적인 알고리즘인 퀵정렬 알고리즘.
//'분할정복' 알고리즘으로 평균속도가 O(N*logN).
//특정값을 기준으로 큰 숫자와 작은 숫자를 교환한 뒤 배열을 반으로 나눔.

#include<iostream>

using namespace std;

int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void show()
{
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void quick_sort(int* data, int start, int end)
{
    if(start >= end)
        return;

    int key = start;
    int i = start + 1, j = end, temp;

    while(i <= j)
    {
        while(i <= end && arr[i] <= arr[key])
            i++;

        while(j > start && arr[j] >= arr[key])
            j--;

        if(i > j)
        {
            temp = arr[j];
            arr[j] = arr[key];
            arr[key] = temp;
        }

        else
        {
            temp = arr[i];
            arr[i] = arr[key];
            arr[key] = temp;
        }

    }

    quick_sort(arr, start, j - 1);
    quick_sort(arr, j + 1, end);
}



int main()
{
    quick_sort(arr, 0, 9);
    show();

    return 0;
}