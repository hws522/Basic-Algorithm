/*
네트워크 플로우는 특정한 지점에서 다른 지점으로
데이터가 얼마나 많이 흐르고 있는가를 측정하는 알고리즘.

일반적으로 최대 유량(Max Flow) 문제라고 정의함.
최대 유량 문제는 각 간선에 정해진 용량이 있을 때, 
A 에서 B로 최대로 보낼 수 있는 유량의 크기를 구하는 문제.

기본적으로 최대 유량 문제는 단순하게 가능한 모든 경우의 수를 탐색하는데,
이 때 BFS(너비 우선 탐색)을 일반적으로 이용.
이것을 에드몬드 카프(Edmonds-Karp) 알고리즘이라 함.

최대 유량 알고리즘은 순서가 상관 없음.
남아있는 양이 1이 넘으면 계속해서 흘려 보내주면 알아서 최적화.

기본적으로 BFS를 사용하여 모든 가능한 경로를 다 찾아서 남아있는 용량만큼
유량을 흘려 보내주는 것을 반복.
음의 유량도 함께 처리.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 100
#define INF 1000000000

using namespace std;

int n = 6, result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> a[MAX];

void maxFlow(int start, int end)
{
	while (1)
	{
		fill(d, d + MAX, -1);

		queue<int> q;
		
		q.push(start);

		while (!q.empty())
		{
			int x = q.front();
			q.pop();

			for (int i = 0; i < a[x].size(); i++)
			{
				int y = a[x][i];
				// 방문하지 않은 노드 중에 용량이 남은 경우.
				if (c[x][y] - f[x][y] > 0 && d[y] == -1)
				{
					q.push(y);
					d[y] = x; // 경로 기억.
					
					if (y == end)
						break; //도착지에 도달한 경우
				}
			}
		}

		if (d[end] == -1)
			break; // 모든 경로를 찾은 뒤 탈출.
		int flow = INF;

		for (int i = end; i != start; i = d[i])
		{
			//거꾸로 최소 유량 탐색.
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}

		//최소 유량만큼 추가.
		for (int i = end; i != start; i = d[i])
		{
			f[d[i]][i] += flow;
			f[i][d[i]] += flow;
		}

		result += flow;
	}
}

int main()
{
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;

	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;

	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;

	maxFlow(1, 6);

	cout << result << endl;
}