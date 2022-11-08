
// 기본탐색
/*
#include <iostream>

using namespace std;

int number = 6;
int INF = 10000000;

// 그래프 초기화

int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0},
};

// 방문 노드 여부
bool _isVisit[6]; 
// 거리
int _distance[6];

// 해당 index에서 최소거리 정점 반환

int getSmallidx() 
{
	int min = INF;
	int idx = 0;
	for (int i = 0; i < number; i++)
	{
		if (_distance[i] < min && !_isVisit[i])
		{
			min = _distance[i];
			idx = i;
		}
	}
	return idx;
}

void Dijkstra(int StartNode)
{
	for (int i = 0; i < number; i++)
	{
		_distance[i] = a[StartNode][i];
	}

	_isVisit[StartNode] = true;

	for (int i = 0; i < number - 2; i++)
	{
		int current = getSmallidx();
		_isVisit[current] = true;

		for (int j = 0; j < 6; j++)
		{
			if (!_isVisit[j])
			{
				if (_distance[current] + a[current][j] < _distance[j])
				{
					_distance[j] = _distance[current] + a[current][j];
				}
			}
		}
	}
}

int main()
{
	Dijkstra(0);
	for (int i = 0; i < number; i++)
	{
		cout << _distance[i];
	}
}
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

// 간선 이어주기
vector<pair<int, int>> a[7];
// 최소비용
int d[7];

void Dijkstra(int StartNode)
{
	d[StartNode] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(StartNode, 0));

	// 가까운 순서대로 처리하기에, 우선순위 큐를 사용해 정렬된 순으로 이용
	while (!pq.empty())
	{
		int current = pq.top().first;
		// 거리가 짧은것이 먼저오도록 음수화(-)

		int distance = -pq.top().second;
		pq.pop();

		//최단 거리가 아니면 넘기기
		if (d[current] < distance) continue;

		for (int i = 0; i < a[current].size(); i++)
		{
			// 선택된 노드와 인접노드
			int next = a[current][i].first;
			// 선택된 노드를 인접 노드로 거쳐서 가는 비용
			int nextDistance = distance + a[current][i].second;

			// 기존 최소비용보다 저렴할 시 교체
			if (nextDistance < d[next])
			{
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main(void)
{
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

	Dijkstra(1);

	for (int i = 1; i <= number; i++)
	{
		cout << d[i] << " ";
	}
}