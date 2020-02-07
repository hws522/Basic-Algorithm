/*
다이나믹 프로그래밍을 활용한 대표적인 최단 경로 탐색 알고리즘.
특정한 하나의 정점에서 다른 모든 정점으로 가는 최단 경로를 알려줌.
음의 간선은 포함할 수 없음.
다이나믹 프로그래밍을 이용하는 이유는 최단거리는 여러 개의 최단 거리로 이루어져 있기 때문.
하나의 최단 거리를 구할 때, 그 이전까지 구했던 최단 거리 정보를 그대로 사용.(갱신함)
*/

/*
1. 출발 노드 설정.
2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장.
3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택.
4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용 갱신.
5. 3 ~ 4 반복.
*/

////선형 탐색으로 구현했을 때. 가장 간단히 구현할 수 있으나, 노드갯수에 비해
////간선이 작을 때 치명적으로 비효율적일 수 있음.
////시간복잡도는 O(N^2).

//#include<iostream>
//
//using namespace std;
//
//int number = 6;
//int INF = 10000000;
// 그래프 초기화.
//int a[6][6] = 
//{
//	{0, 2, 5, 1, INF, INF},
//	{2, 0, 3, 2, INF, INF},
//	{5, 3, 0, 3, 1, 5},
//	{1, 2, 3, 0, 1, INF},
//	{INF, INF, 1, 1, 0, 2},
//	{INF, INF, 5, INF, 2, 0}
//};
//
//bool v[6]; //방문한 노드.
//int d[6]; // 거리.
//
//최소 거리를 가지는 정점 반환.
//int getSmallIndex()
//{
//	int min = INF;
//	int index = 0;
//
//	for (int i = 0; i < number; i++)
//	{
//		if (d[i] < min && !v[i])
//		{
//			min = d[i];
//			index = i;
//		}
//	}
//
//	return index;
//}
//
//void dijkstra(int start)
//{
//	for (int i = 0; i < number; i++)
//	{
//		d[i] = a[start][i]; //시작점으로 부터 출발을 했을 때 초기 경로 비용.
//	}
//
//	v[start] = true; //방문처리.
//
//	for (int i = 0; i < number - 2; i++)
//	{
//		int current = getSmallIndex();
//		v[current] = true;
//
//		for (int j = 0; j < 6; j++)
//		{
//			if (!v[j])
//			{
//				if (d[current] + a[current][j] < d[j]) //직선거리보다 거쳐가는게 더 작았을 경우.
//				{
//					d[j] = d[current] + a[current][j];
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	dijkstra(0);
//
//	for (int i = 0; i < number; i++)
//		cout << d[i] << ' ';
//	cout << endl;
//
//	return 0;
//}

//힙구조를 활용하여 시간복잡도 O(N * logN)
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int> > a[7]; //간선 정보.
int d[7]; //최소 비용.

void dijkstra(int start)
{
	d[start] = 0; //자기자신으로 가는 간선.

	priority_queue<pair<int, int> > pq; // 최대값이 위로가는 힙 구조.

	pq.push(make_pair(start, 0));
	//가까운 순서대로 처리하므로 큐를 사용.

	while (!pq.empty())
	{
		int current = pq.top().first;
		//짧은 것이 먼저 오도록 음수화(-). (최댓값이 먼저 와있으므로)
		int distance = -pq.top().second;
		
		pq.pop();
		//최단 거리가 아닌 경우 스킵.
		if (d[current] < distance)
			continue;

		for (int i = 0; i < a[current].size(); i++)
		{
			//선택된 노드의 인접 노드.
			int next = a[current][i].first;
			//선택된 노드를 거쳐서 인접 노드로 가는 비용.
			int nextDistance = distance + a[current][i].second;
			//기존의 최소 비용보다 더 저렴하다면 교체.
			if (nextDistance < d[next])
			{
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance)); //새롭게 갱신된 값을 넣어줌.
			}
		}

	}
}

int main()
{
	//기본적으로 연결 되지 않은 경우 비용은 무한.
	for (int i = 1; i <= number; i++)
	{
		d[i] = INF;
	}

	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	dijkstra(1);

	//결과 출력.
	for (int i = 1; i <= number; i++)
		cout << d[i] << ' ';
	cout << endl;


}