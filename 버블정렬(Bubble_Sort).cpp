/*
다음의 숫자들을 오름차순으로 정렬하세요.
1 10 5 8 7 6 4 3 2 9
*/

//버블정렬 또한 선택정렬과 마찬가지로 몹시 직관적인 해결방법.
//옆에 있는 값과 비교하여 더 작은 값을 반복적으로 앞으로 보내는 정렬.
//정렬 알고리즘 중 구현이 가장 쉽지만 그만큼 가장 비효율적인 알고리즘.
//시간 복잡도는 O(N^2)
//선택정렬과 같은 시간 복잡도이지만 실제로는 선택정렬보다도 느리다.

#include<iostream>
using namespace std;

int main()
{
    int temp;
    int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 9 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}