/*
���� ���� ���� �켱������ Ž���ϴ� �˰���.
�͸����� Ž��.
������ ���.
������ ���� ������� �ʾƵ� ���� ����.(��ǻ�� ������ Ư������ �׻� ������ ������ ���)
�� ��ü�δ� ū �ǹ̰� ����, �ٸ� �˰��� ����Ǿ��� �� �ǹ̰� ����.
*/

#include<iostream>
#include<vector>

using namespace std;

int number = 7; // ��� ����.
int c[8]; // ����Ȯ�� �� �� üũ�ϱ����� �迭.
vector<int> a[8];

void dfs(int x)
{
	if (c[x]) //��� �湮ó���� �ߴٸ� ����.
		return;

	c[x] = true; //��� �湮ó���� ���ߴٸ� �湮ó��.
	cout << x << ' '; //�ش��� ���.

	for (int i = 0; i < a[x].size(); i++) //������ ��� ���� �� �ݺ�.
	{
		int y = a[x][i];
		dfs(y);
	}
}

int main()
{
	//1�� 2�� ����.
	a[1].push_back(2);
	a[2].push_back(1);

	//1�� 3�� ����.
	a[1].push_back(3);
	a[3].push_back(1);

	//2�� 3�� ����.
	a[2].push_back(3);
	a[3].push_back(2);

	//2�� 4�� ����.
	a[2].push_back(4);
	a[4].push_back(2);

	//2�� 5�� ����.
	a[2].push_back(5);
	a[5].push_back(2);

	//3�� 6�� ����.
	a[3].push_back(6);
	a[6].push_back(3);

	//3�� 7�� ����.
	a[3].push_back(7);
	a[7].push_back(3);

	//4�� 5�� ����.
	a[4].push_back(5);
	a[5].push_back(4);

	//6�� 7�� ����.
	a[6].push_back(7);
	a[7].push_back(6);

	//DFS�� ����.
	dfs(1);

	return 0;
}