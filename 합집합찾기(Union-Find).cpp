/*
Union-Find�� ��ǥ���� �׷��� �˰���.
������ã���� �ǹ�.
���μ� ����(Disjoint-Set)�˰����̶�� �θ�.
���� ��尡 ������ ��, �ΰ��� ��带 �����ؼ�
���� �� ��尡 ���� ���� �׷����� ���ϴ��� �Ǻ��ϴ� �˰���.
��ΰ� ������� ���� ���� �ڱ� �ڽŸ��� ������ ���ҷ� ������ ���� ��,
��� ���� �ڱ� �ڽ��� ����Ű���� ����.(��, �ڽ��� �ڽ��� �θ���)
1 �� 2 �� ���� �Ǿ��� �� �̷��� ���Ἲ�� ���α׷��� ���� ��� 
ǥ���� �� ���� ���� ���� ������ �ٷ� union-find.
��� �Լ��� ���� union(��ħ)�� �ϼ�.
�Ϲ������� �θ� ��ĥ ���� �� ���� �� ������ ��ħ.
find�˰����� �ΰ��� ����� �θ� ��带 Ȯ���Ͽ� ���� ���� ���տ� ���ϴ���
Ȯ���ϴ� �˰���.
*/

#include<iostream>

using namespace std;

int getParent(int parent[], int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = getParent(parent, parent[x]);
}

//�� �θ� ��带 ��ħ.
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b)
		parent[b] = a;

	else
		parent[a] = b;
}

//���� �θ� ��带 �������� Ȯ��.
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

	cout << "1�� 5�� ����Ǿ� �ִ°� " << findParent(parent, 1, 5) << endl;

	unionParent(parent, 1, 5); cout << "��� ��ħ ��" << endl;

	cout << "1�� 5�� ����Ǿ� �ִ°� " << findParent(parent, 1, 5) << endl;

}