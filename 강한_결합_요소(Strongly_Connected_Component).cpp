/*
유향 그래프에서 모든 정점이 모든 다른정점에 대해 도달 가능한 경우, 
강하게 연결 되었다라고 함. 강한 결합 요소는 부분 그래프의 모든 정점이 강하게 연결된 
임의의 유향그래프의 분할임. 그래프가 강하게 연결되었는지, 그래프에서 강한 연결 요소를 
찾는 것은 선형시간에 가능.
SCC 알고리즘이라 불림.
SCC는 같은 SCC에 속하는 두 정점은 서로 도달이 가능하다는 특징이 있음.
사이클이 발생하는 경우 무조건 SCC.

SCC를 추출하는 알고리즘에는 코사라주 알고리즘과 타잔 알고리즘이 있음.
구현은 코사라주가 쉽고 적용은 타잔이 쉬움.

타잔 알고리즘은 모든 정점에 대해 DFS를 수행하여 SCC를 찾는 알고리즘.
부모에서 자식으로 나아가는 알고리즘으로 DFS알고리즘이 사용됨.

SCC 자체로는 큰 의미가 없으나, 위상 정렬과 함께 사용 했을 때 의미가 있음.
모든 SCC를 구한뒤 그 SCC를 각 정점으로 봤을 때 위상정렬 할 수 있음.
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 10001 //최대 노드 갯수.

using namespace std;

int id, d[MAX]; //각 노드마다 고유번호 할당.
bool finished[MAX]; //현재 특정한 노드에 대한 DFS가 끝났는지 확인.
vector<int> a[MAX]; //실질적으로 인접한 노드를 담는 배열.
vector<vector<int> > SCC; //한 그래프에서 여러개 나올 수 있으므로 2차원.
stack<int> s; //SCC에 사용할 스택.

//DFS는 총 정점의 갯수만큼 실행.
int dfs(int x)
{
	d[x] = ++id; // 노드마다 고유한 번호 할당.
	s.push(x); // 스택에 자기 자신 삽입.

	int parent = d[x];

	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];

		if (d[y] == 0)
		{
			parent = min(parent, dfs(y)); // 방문 하지 않은 이웃에 대해 더 작은 부모노드로 교체.
		}

		else if (!finished[y])
		{
			parent = min(parent, d[y]); // 처리중인 이웃에 대해 현재까지 구해진 값으로 교체.
		}
	}

	// 부모노드가 자기 자신인 경우.
	if (parent == d[x])
	{
		vector<int> scc;

		while (1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;

			if (t == x) //자기자신이 나왔을경우.
				break;
		}

		SCC.push_back(scc); //만들어진 scc를 전체 SCC에 삽입.
	}

	//자신의 부모 값을 반환.
	return parent;
}

int main()
{
	int v = 11;

	a[1].push_back(2);

	a[2].push_back(3);

	a[3].push_back(1);

	a[4].push_back(2);
	a[4].push_back(5);

	a[5].push_back(7);

	a[7].push_back(6);

	a[6].push_back(5);

	a[8].push_back(5);
	a[8].push_back(9);

	a[9].push_back(10);

	a[10].push_back(11);

	a[11].push_back(3);

	a[11].push_back(8);

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == 0)
			dfs(i);
	}

	cout << "SCC의 갯수 : " << SCC.size() << endl;

	for (int i = 0; i < SCC.size(); i++)
	{
		cout << i + 1 << "번째 SCC : ";
		for (int j = 0; j < SCC[i].size(); j++)
		{
			cout << SCC[i][j] << ' ';
		}

		cout << endl;
	}

	return 0;
}
