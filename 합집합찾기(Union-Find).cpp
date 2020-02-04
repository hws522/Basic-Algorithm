/*
Union-Find는 대표적인 그래프 알고리즘.
합집합찾기라는 의미.
서로소 집합(Disjoint-Set)알고리즘이라고도 부름.
여러 노드가 존재할 때, 두개의 노드를 선택해서
현재 두 노드가 서로 같은 그래프에 속하는지 판별하는 알고리즘.
모두가 연결되지 않은 각자 자기 자신만을 집합의 원소로 가지고 있을 때,
모든 값이 자기 자신을 가리키도록 만듬.(즉, 자신이 자신의 부모노드)
1 과 2 가 연결 되었을 때 이러한 연결성을 프로그래밍 언어로 어떻게 
표현할 수 있을 지에 대한 내용이 바로 union-find.
재귀 함수를 통해 union(합침)이 완성.
일반적으로 부모를 합칠 때는 더 작은 값 쪽으로 합침.
find알고리즘은 두개의 노드의 부모 노드를 확인하여 현재 같은 집합에 속하는지
확인하는 알고리즘.
*/

#include<iostream>

using namespace std;

int getParent(int parent[], int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = getParent(parent, parent[x]);
}

//각 부모 노드를 합침.
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b)
		parent[b] = a;

	else
		parent[a] = b;
}

//같은 부모 노드를 가지는지 확인.
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b)
		return 1;

	else
		return 0;
}

int main()
{
	int parent[11];

	for (int i = 1; i <= 10; i++)
	{
		parent[i] = i;
	}

	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	cout << "1과 5는 연결되어 있는가 " << findParent(parent, 1, 5) << endl;

	unionParent(parent, 1, 5); cout << "노드 합침 후" << endl;

	cout << "1과 5는 연결되어 있는가 " << findParent(parent, 1, 5) << endl;

}