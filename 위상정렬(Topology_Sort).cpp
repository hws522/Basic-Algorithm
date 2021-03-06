/*
순서가 정해져 있는 작업을 차례로 수행해야 할 때,
그 순서를 결정해 주기 위해 사용하는 알고리즘.
위상 정렬 알고리즘은 두가지 답을 알 수 있음.
현재 그래프가 위상 정렬이 가능한 그래프인지 , 
가능하다면 결과는 무엇인지.

예시) 대학생 되기 >> 학과 사이트 가입하기 >> 4학년 되기 >>
정보처리기사 합격하기 >> 자격 서류 제출하기 >> 졸업시험 신청하기 >> 졸업

위상 정렬은 여러 개의 답이 존재할 수 있다는 점에서 매력적.
위상 정렬은 DAG(Directed Acyclic Graph)에만 적용 가능.
즉, 사이클이 없는 방향 그래프.

위상 정렬은 스택, 큐 모두 이용가능.

1. 진입차수가 0인 정점을 큐에 삽입.
2. 큐에서 원소를 꺼내 연결된 모든 간선 제거.
3. 간선 제거 이후 진입차수가 0이 된 정점을 큐에 삽입.
4. 큐가 빌 때까지 2 ~ 3 과정 반복.
5. 모든 원소를 방문하기 전 큐가 빈다면 사이클이 존재.
   모든 원소를 방문했다면 큐에서 꺼낸 순서가 위상 정렬의 결과.
*/

#include<iostream>
#include<vector>
#include<queue>
#define MAX 10

using namespace std;

int n, inDegree[MAX];
vector<int> a[MAX];

void topologySort()
{
	int result[MAX];
	queue<int> q;
	//진입 차수가 0인 노드를 큐에 삽입.
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	//정렬이 완전히 수행되려면 정확히 n개의 노드를 방문.
	for (int i = 1; i <= n; i++)
	{
		//n개를 모두 방문하기 전에 큐가 비어버리면 사이클이 발생한 것.
		if (q.empty())
		{
			cout << "사이클 발생. ";
			return;
		}

		int x = q.front();
		q.pop();

		result[i] = x;

		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			//새롭게 진입차수가 0이 된 정점을 큐에 삽입.
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << ' ';
	}
}

int main()
{
	n = 7;

	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;

	a[2].push_back(3);
	inDegree[3]++;

	a[3].push_back(4);
	inDegree[4]++;

	a[4].push_back(6);
	inDegree[6]++;

	a[5].push_back(6);
	inDegree[6]++;

	a[6].push_back(7);
	inDegree[7]++;

	topologySort();

	return 0;
}
