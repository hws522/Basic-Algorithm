/*
하나의 문제는 단 한번만 풀도록 하는 알고리즘.
단순 분할 정복으로 풀게 될 시 심각한 비효율성을 낳음.(정렬과 같은 몇몇 요소 제외)
피보나치 수열이 대표적.
큰 문제를 작은 문제로 나눌 수 있을 때 사용가능.
작은 문제에서 구한 답은 그것을 포함하는 큰 문제에서도 동일할 때 사용가능.
이미 계산한 결과를 배열에 잠시 저장. 동일한 계산 시 저장된 값 반환.
*/

#include<iostream>

using namespace std;

//기본 피보나치 수열.
//수가 커지면 에러가 난다.(연산횟수 약 2^n)
int Fibonacci(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 1;

	return Fibonacci(x - 1) + Fibonacci(x - 2);
}

//dp 적용.
int d[100]; //계산했던 값을 저장하는 배열.

int dpFibonacci(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 1;
	if (d[x] != 0)
		return d[x];

	return d[x] = dpFibonacci(x - 1) + dpFibonacci(x - 2);
}

int main()
{
	cout << dpFibonacci(30) << endl;

	return 0;
}