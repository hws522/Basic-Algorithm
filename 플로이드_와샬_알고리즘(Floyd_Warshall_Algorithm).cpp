/*
모든 정점에서 모든 정점으로의 최단 경로를 구할 때 쓰임.
가장 적은 비용을 하나씩 선택해야 했던 다익스트라 알고리즘과는 다르게 
플로이드 와샬 알고리즘은 기본적으로 거쳐가는 정점을 기준으로 알고리즘을 수행.
플로이드 와샬 알고리즘 또한 다이나믹 프로그래밍 기술에 의거.
*/

#include<iostream>

using namespace std;

const int number = 4;
int INF = 10000000;

//자료 배열 초기화.
int a[4][4] =
{
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall()
{
	//결과 그래프 초기화.
	int d[number][number];
	
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			d[i][j] = a[i][j];
		}
	}

	//k = 거쳐가는 노드.(중심이 되는 노드)
	for (int k = 0; k < number; k++)
	{
		// i = 출발 노드.
		for (int i = 0; i < number; i++)
		{
			//j = 도착 노드.
			for (int j = 0; j < number; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	//결과 출력.
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
}


int main()
{
	floydWarshall();

	return 0;
}
