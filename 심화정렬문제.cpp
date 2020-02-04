//백준 1181 
// 첫째 줄에 단어의 갯수 n이 주어진다. (1 <= n <= 20,000)
// 둘째 줄부터 m개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다.
// 주어지는 문자열의 길이는 50을 넘지 않는다.
// 같은 단어가 여러번 입력된 경우에는 한 번씩만 출력한다.
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
	//길이가 짧은 단어 먼저.
	if (a.length() < b.length())
		return 1;
	else if (a.length() > b.length())
		return 0;
	//길이가 같을 때는 사전순.
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