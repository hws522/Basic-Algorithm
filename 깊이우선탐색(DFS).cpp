/*
보다 깊은 것을 우선적으로 탐색하는 알고리즘.
맹목적인 탐색.
스택을 사용.
스택을 굳이 사용하지 않아도 구현 가능.(컴퓨터 구조적 특성으로 항상 스택의 원리를 사용)
그 자체로는 큰 의미가 없고, 다른 알고리즘에 적용되었을 때 의미가 있음.
*/

#include<iostream>
#include<vector>

using namespace std;

int number = 7; // 노드 갯수.
int c[8]; // 접근확인 할 때 체크하기위한 배열.
vector<int> a[8];

void dfs(int x)
{
	if (c[x]) //노드 방문처리를 했다면 리턴.
		return;

	c[x] = true; //노드 방문처리를 안했다면 방문처리.
	cout << x << ' '; //해당노드 출력.

	for (int i = 0; i < a[x].size(); i++) //인접한 노드 접근 후 반복.
	{
		int y = a[x][i];
		dfs(y);
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

	//DFS를 수행.
	dfs(1);

	return 0;
}