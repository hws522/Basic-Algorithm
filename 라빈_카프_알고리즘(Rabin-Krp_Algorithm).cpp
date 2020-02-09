/*
특이한 문자열 매칭 알고리즘.
항상 빠르지는 않으나, 일반적인경우 빠르게 작동하는 간단한 구조의 문자열 매칭 알고리즘.
해시(Hash) 기법을 사용. 
Hash는 긴 데이터를 그것을 상징하는 짧은 데이터로 바꾸어주는 기법.
보통 문자열 매칭은 연속적인 문자열이 이어지는 경우에 기반하기 때문에 
Hash또한 연속적인 경우에 더 빠르게 구할 수 있는 알고리즘을 채택하여 적용한다면 빠르게 연산 가능.

해시함수는 각 문자의 아스키코드 값에 2의 제곱 수를 차례로 곱하여 더해준 것.
문자열이 달라지면 결과로 출력되는 해시 값도 바뀜.
해시 값이 중복되어 충돌이 일어나는 경우도 있으나, 발생률이 높지 않아 무시.
충돌이 일어날 경우 포인터를 이용해 연결 자료구조로 해결.

즉, 라빈 카프 알고리즘은 여러 개의 문자열을 비교할 때 항상 해시 값을 구하여 비교하고,
해시 값은 거의 일치 하는 일이 없기 때문에 긴 글과 부분 문자열의 해시 값이 일치하는 경우에만 
문자열을 재검사하여 정확히 일치 하는지 확인 하는 알고리즘.

라빈 카프 알고리즘의 시간복잡도는 O(N).
*/

#include<iostream>

using namespace std;

void findString(string parent, string pattern)
{
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0;
	int patternHash = 0;
	int power = 1; //제곱수를 의미.

	for (int i = 0; i <= parentSize - patternSize; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < patternSize; j++) //기본 해시값을 구함.
			{
				parentHash += parent[patternSize - 1 - j] * power;
				patternHash += pattern[patternSize - 1 - j] * power;

				if (j < patternSize - 1)
					power = power * 2;
			}
		}

		else
		{
			parentHash = 2 * (parentHash - parent[i - 1] * power) +
							parent[patternSize - 1 + i];
		}

		if (parentHash == patternHash) //해시값이 같을 경우 모든 문자열 비교.
		{
			bool finded = true;

			for (int j = 0; j < patternSize; j++)
			{
				if (parent[i + j] != pattern[j])
				{
					finded = false;
					break;
				}
			}
			if (finded)
			{
				cout << i + 1 << "번째에서 발견했습니다. " << endl;
			}
		}
	}
}

int main()
{
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";

	findString(parent, pattern);

	return 0;
}