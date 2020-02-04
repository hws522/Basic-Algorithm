/*
�ϳ��� ������ �� �ѹ��� Ǯ���� �ϴ� �˰���.
�ܼ� ���� �������� Ǯ�� �� �� �ɰ��� ��ȿ������ ����.(���İ� ���� ��� ��� ����)
�Ǻ���ġ ������ ��ǥ��.
ū ������ ���� ������ ���� �� ���� �� ��밡��.
���� �������� ���� ���� �װ��� �����ϴ� ū ���������� ������ �� ��밡��.
�̹� ����� ����� �迭�� ��� ����. ������ ��� �� ����� �� ��ȯ.
*/

#include<iostream>

using namespace std;

//�⺻ �Ǻ���ġ ����.
//���� Ŀ���� ������ ����.(����Ƚ�� �� 2^n)
int Fibonacci(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 1;

	return Fibonacci(x - 1) + Fibonacci(x - 2);
}

//dp ����.
int d[100]; //����ߴ� ���� �����ϴ� �迭.

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