//범위조건이 있는 경우에 한해서 굉장히 빠른 알고리즘.
//시간복잡도 O(N).
//크기를 기준으로 갯수를 세는 것.

#include<iostream>

using namespace std;

int main()
{
	int count[5] = { 0, };
	int array[30] = { 1, 3, 2, 4, 3, 2, 5, 3, 1, 2, 3, 4, 4, 3, 5, 1, 2, 3, 5, 2, 3, 1, 4, 3, 5, 1, 2, 1, 1, 1 };

	for (int i = 0; i < 30; i++)
	{
		count[array[i] - 1]++;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			cout << i + 1 << ' ';
		}
	}

	cout << endl;

	return 0;
}