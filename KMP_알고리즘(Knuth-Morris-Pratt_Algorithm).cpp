/*
대표적인 문자열 매칭 알고리즘.
기본적으로 문자열 매칭 알고리즘이란 특정한 글이 있을 때,
그 안에서 하나의 문자열을 찾는 알고리즘.

단순 비교 문자열 매칭 알고리즘은 말그대로 하나하나 모두 확인하는 알고리즘으로
가장 간단한 형태의 알고리즘. 하지만 최악의 경우 시간이 많이 소요됨으로 비효율적.

KMP 알고리즘은 접두사와 접미사의 개념을 활용하여 반복되는 연산을 얼마나 줄일 수 있는지
판별하여 매칭할 문자열을 빠르게 점프하는 기법.

접두사와 접미사를 구하게 됐을 때, 접두사와 접미사가 일치하는 경우에 한해서는 점프하여 수행.
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> makeTable(string pattern)
{
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);

	int j = 0;

	for (int i = 1; i < patternSize; i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = table[j - 1];
		}

		if (pattern[i] == pattern[j])
		{
			table[i] = ++j;
		}
	}

	return table;
}

void KMP(string parent, string pattern)
{
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();

	int j = 0;

	for (int i = 0; i < parentSize; i++)
	{
		while (j > 0 && parent[i] != pattern[j])
		{
			j = table[j - 1];
		}

		if (parent[i] == pattern[j])
		{
			if (j == patternSize - 1)
			{
				cout << i - patternSize + 2 << "번째에서 찾았습니다." << endl;
				
				j = table[j];
			}

			else
			{
				j++;
			}
		}
	}
}

int main()
{
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";

	KMP(parent, pattern);

	return 0;
}