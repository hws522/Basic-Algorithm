/*
이분 매칭은 네트워크 플로우 알고리즘과 연계되는 개념.
A 집단이 B 집단을 선택하는 방법에 대한 알고리즘.
효과적으로 매칭시키다라는 말은 최대매칭을 의미.
이분 매칭 알고리즘은 각 용량을 1로 설정한 네트워크 플로우문제로 표현 가능.
네트워크 플로우 에드몬드 카프 알고리즘은 시간복잡도가 O(V * E^2).
하지만 이분 매칭에 한해 더 빠르고 효율적으로 알고리즘 설계 가능.
DFS 사용.
이분 매칭을 간단히 풀 때의 시간 복잡도는 O(V * E).
*/

#include<iostream>
#include<vector>
#define MAX 101 //정점의 갯수

using namespace std;

vector<int> a[MAX];
int d[MAX]; //특정한 정점을 점유하고 있는 노드의 정보를 담는 배열.
bool c[MAX]; //특정한 정점을 처리했는지 여부를 확인하는 배열.
int n = 3;

//매칭에 성공한 경우 true, 실패한 경우 false.
bool dfs(int x)
{
	//연결된 모든 노드에 대해서 들어갈 수 있는지 시도.
	for (int i = 0; i < a[x].size(); i++)
	{
		int t = a[x][i]; //t 에 연결된 노드를 담아줌.
		
		if (c[t]) // 이미 처리한 노드는 더 이상 볼 필요 없음.
			continue;

		c[t] = true;
		//비어있거나 점유 노드에 더 들어갈 공간이 있는 경우.
		if (d[t] == 0 || dfs(d[t]))
		{
			d[t] = x;
			return true;
		}
	}

	return false;
}

int main()
{
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);

	a[2].push_back(1);

	a[3].push_back(2);

	int count = 0; //최대 매칭의 갯수.

	for (int i = 1; i <= n; i++)
	{
		//최대한 넣기.
		fill(c, c + MAX, false); //매칭할 때 마다 처리되지 않은 상태로 초기화.

		if (dfs(i))
			count++;
	}

	cout << count << "개의 매칭이 이루어졌습니다. " << endl;

	for (int i = 1; i <= 100; i++)
	{
		if (d[i] != 0)
		{
			cout << d[i] << " -> " << i << endl;
		}
	}
}