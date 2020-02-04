/*
가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘.
즉, 최소 비용 신장 트리를 만들기 위한 알고리즘.
예로 여러 도시가 있을 때 각 도시를 도로를 이용해 연결하고자 할 때, 
비용을 최소한으로 하고자 사용되는 알고리즘.

노드 = 정점 = 도시
간선 = 거리 = 비용

모든 간선 정보를 오름차순으로 정렬한 뒤,
비용이 적은 간선부터 차례로 그래프에 포함시키면 됨.
사이클이 발생하면 안됨. 사이클 발생여부는 Union-find 적용.
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//부모 노드 가져오기. Union-Find 그대로 적용.
int getParent(int set[], int x)
{
	if (set[x] == x)
		return x;

	return set[x] = getParent(set, set[x]);
}

//부모 노드 병합.
void unionParent(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);
	//더 숫자가 작은 부모로 병합.
	if (a < b)
		set[b] = a;
	else
		set[a] = b;
}

//같은 부모를 가지는 지 확인.
int find(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);

	if (a == b)
		return 1;
	else
		return 0;
}

//간선 클래스 선언.
class Edge
{
public:
	int node[2];
	int distance;

	Edge(int a, int b, int distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge &edge)
	{
		return this->distance < edge.distance;
	}
};

int main()
{
	const int n = 7;
	int m = 11;

	vector<Edge> v;

	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	//간선의 비용기준으로 오름차순 정렬.
	sort(v.begin(), v.end());

	//각 정점이 포함된 그래프가 어디인지 저장.
	int set[n];
	for (int i = 0; i < n; i++)
	{
		set[i] = i; //각 노드의 부모노드를 그 자신으로 설정.
	}

	//거리의 합을 0으로 초기화.
	int sum = 0;

	for (int i = 0; i < v.size(); i++)
	{
		//동일한 부모를 가르키지 않는 경우, 즉 사이클이 발생하지 않을 때만 선택.
		if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1))//-1을 하는 이유는 set[] 의 인덱스가 0부터 시작하기 때문.
		{
			sum += v[i].distance;
			unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	cout << sum << endl;

	return 0;
}