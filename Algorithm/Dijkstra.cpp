
// 기본탐색
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

