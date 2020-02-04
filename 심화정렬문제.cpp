//���� 1181 
// ù° �ٿ� �ܾ��� ���� n�� �־�����. (1 <= n <= 20,000)
// ��° �ٺ��� m���� �ٿ� ���� ���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����.
// �־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.
// ���� �ܾ ������ �Էµ� ��쿡�� �� ������ ����Ѵ�.
/*
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string a[20000];

bool compare(string a, string b)
{
	//���̰� ª�� �ܾ� ����.
	if (a.length() < b.length())
		return 1;
	else if (a.length() > b.length())
		return 0;
	//���̰� ���� ���� ������.
	else
		return a < b;
}

int main()
{
	int number;
	

	cin >> number;
	
	for (int i = 0; i < number; i++)
	{
		cin >> a[i];
	}

	sort(a, a + number, compare);

	for (int i = 0; i < number; i++)
	{
		if (i > 0 && a[i] == a[i - 1])
			continue;

		cout << a[i] << endl;
	}
	return 0;
}