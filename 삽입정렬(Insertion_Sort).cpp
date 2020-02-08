//다음 숫자들을 오름차순으로 정렬하는 프로그램을 작성하세요.
// 1 10 5 8 7 6 4 3 2 9
//비교적 느린 정렬 알고리즘. 조금 복잡한 구조.
//기본적으로 '정렬이 되어있다고 가정'을 한다는 점에서 경우에 따라 굉장히 빠름.
//소스상 반복문이 두 번 들어가 있다는 점에서 시간복잡도는 O(N^2).

#include<iostream>

using namespace std;

int main()
{   
    int j; 
    int temp;
    int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    for(int i = 0; i < 9; i++)
    {
        j = i;
        while(j >= 0 && arr[j] > arr[j + 1])
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            j--;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}