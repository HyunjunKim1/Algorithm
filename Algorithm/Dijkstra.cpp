
// �⺻Ž��
/*
#include <iostream>

using namespace std;

int number = 6;
int INF = 10000000;

// �׷��� �ʱ�ȭ

int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0},
};

// �湮 ��� ����
bool _isVisit[6]; 
// �Ÿ�
int _distance[6];

// �ش� index���� �ּҰŸ� ���� ��ȯ

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

// ���� �̾��ֱ�
vector<pair<int, int>> a[7];
// �ּҺ��
int d[7];

void Dijkstra(int StartNode)
{
	d[StartNode] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(StartNode, 0));

	// ����� ������� ó���ϱ⿡, �켱���� ť�� ����� ���ĵ� ������ �̿�
	while (!pq.empty())
	{
		int current = pq.top().first;
		// �Ÿ��� ª������ ���������� ����ȭ(-)

		int distance = -pq.top().second;
		pq.pop();

		//�ִ� �Ÿ��� �ƴϸ� �ѱ��
		if (d[current] < distance) continue;

		for (int i = 0; i < a[current].size(); i++)
		{
			// ���õ� ���� �������
			int next = a[current][i].first;
			// ���õ� ��带 ���� ���� ���ļ� ���� ���
			int nextDistance = distance + a[current][i].second;

			// ���� �ּҺ�뺸�� ������ �� ��ü
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