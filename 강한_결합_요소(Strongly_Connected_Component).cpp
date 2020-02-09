/*
���� �׷������� ��� ������ ��� �ٸ������� ���� ���� ������ ���, 
���ϰ� ���� �Ǿ��ٶ�� ��. ���� ���� ��Ҵ� �κ� �׷����� ��� ������ ���ϰ� ����� 
������ ����׷����� ������. �׷����� ���ϰ� ����Ǿ�����, �׷������� ���� ���� ��Ҹ� 
ã�� ���� �����ð��� ����.
SCC �˰����̶� �Ҹ�.
SCC�� ���� SCC�� ���ϴ� �� ������ ���� ������ �����ϴٴ� Ư¡�� ����.
����Ŭ�� �߻��ϴ� ��� ������ SCC.

SCC�� �����ϴ� �˰��򿡴� �ڻ���� �˰���� Ÿ�� �˰����� ����.
������ �ڻ���ְ� ���� ������ Ÿ���� ����.

Ÿ�� �˰����� ��� ������ ���� DFS�� �����Ͽ� SCC�� ã�� �˰���.
�θ𿡼� �ڽ����� ���ư��� �˰������� DFS�˰����� ����.

SCC ��ü�δ� ū �ǹ̰� ������, ���� ���İ� �Բ� ��� ���� �� �ǹ̰� ����.
��� SCC�� ���ѵ� �� SCC�� �� �������� ���� �� �������� �� �� ����.
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 10001 //�ִ� ��� ����.

using namespace std;

int id, d[MAX]; //�� ��帶�� ������ȣ �Ҵ�.
bool finished[MAX]; //���� Ư���� ��忡 ���� DFS�� �������� Ȯ��.
vector<int> a[MAX]; //���������� ������ ��带 ��� �迭.
vector<vector<int> > SCC; //�� �׷������� ������ ���� �� �����Ƿ� 2����.
stack<int> s; //SCC�� ����� ����.

//DFS�� �� ������ ������ŭ ����.
int dfs(int x)
{
	d[x] = ++id; // ��帶�� ������ ��ȣ �Ҵ�.
	s.push(x); // ���ÿ� �ڱ� �ڽ� ����.

	int parent = d[x];

	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];

		if (d[y] == 0)
		{
			parent = min(parent, dfs(y)); // �湮 ���� ���� �̿��� ���� �� ���� �θ���� ��ü.
		}

		else if (!finished[y])
		{
			parent = min(parent, d[y]); // ó������ �̿��� ���� ������� ������ ������ ��ü.
		}
	}

	// �θ��尡 �ڱ� �ڽ��� ���.
	if (parent == d[x])
	{
		vector<int> scc;

		while (1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;

			if (t == x) //�ڱ��ڽ��� ���������.
				break;
		}

		SCC.push_back(scc); //������� scc�� ��ü SCC�� ����.
	}

	//�ڽ��� �θ� ���� ��ȯ.
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

	cout << "SCC�� ���� : " << SCC.size() << endl;

	for (int i = 0; i < SCC.size(); i++)
	{
		cout << i + 1 << "��° SCC : ";
		for (int j = 0; j < SCC[i].size(); j++)
		{
			cout << SCC[i][j] << ' ';
		}

		cout << endl;
	}

	return 0;
}
