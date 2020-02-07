/*
소수를 판별하는 알고리즘.
기본 소수 판별 알고리즘의 시간 복잡도는 O(N).
모든 경우의 수를 판별해야 하기 때문에 비효율적.
결과적으로만 봤을 때, 특정한 숫자의 제곱근까지만 약수의 여부를 검증하면 됨.
에라토스테네스의 체는 대량의 소수를 한번에 판별하고자 할 때 사용함.
*/

#include<iostream>

using namespace std;

int main()
{
	int number = 100000;
	int a[100001];


	for (int i = 2; i <= number; i++) //인덱스 안에 숫자 모두 넣어줌.
	{
		a[i] = i;
	}

	for (int i = 2; i <= number; i++) //인덱스 안에 삭제처리가 되었으면 넘어가고, 아니면 삭제처리.
	{
		if (a[i] == 0)
			continue;

		for (int j = 2 * i; j <= number; j += i)
		{
			a[j] = 0;
		}
	}

	for (int i = 2; i <= number; i++) //인덱스가 삭제되지 않은 것만 출력.
	{
		if (a[i] != 0)
			cout << a[i] << ' ';
	}
	

	return 0;
}