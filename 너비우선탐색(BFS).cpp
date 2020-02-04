/*
탐색을 할 때 너비를 우선으로 하여 탐색을 수행하는 탐색 알고리즘.
맹목적인 탐색.
치단 경로를 찾아준다는 점에서 최단 길이를 보장해야 할 때 많이 사용.
큐를 사용.
그 자체로는 큰 의미가 없고, 다른 알고리즘에 적용되었을 때 의미가 있음.
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int number = 7; //원소의 갯수
int c[7]; //방문처리를 위한 배열
vector<int> a[8]; //인덱스를 1부터 처리할려고 8.

void bfs(int start)
{
	queue<int> q;
	q.push(start);

	c[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';

		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if (!c[y])
			{
				q.push(y);
				c[y] = true;
			}
		}
	}
}

int main()
{
	//1과 2를 연결.
	a[1].push_back(2);
	a[2].push_back(1);

	//1과 3을 연결.
	a[1].push_back(3);
	a[3].push_back(1);

	//2와 3을 연결.
	a[2].push_back(3);
	a[3].push_back(2);

	//2와 4를 연결.
	a[2].push_back(4);
	a[4].push_back(2);

	//2와 5를 연결.
	a[2].push_back(5);
	a[5].push_back(2);

	//3과 6을 연결.
	a[3].push_back(6);
	a[6].push_back(3);

	//3과 7을 연결.
	a[3].push_back(7);
	a[7].push_back(3);

	//4와 5를 연결.
	a[4].push_back(5);
	a[5].push_back(4);

	//6과 7을 연결.
	a[6].push_back(7);
	a[7].push_back(6);

	//BFS를 수행.
	bfs(1);

	return 0;
}