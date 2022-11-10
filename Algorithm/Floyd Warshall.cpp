#include <iostream>
using namespace std;

int num = 4;
int INF = 10000000;

// Initialize

int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void FloydWarshall()
{
	// 그래프 초기화
	int d[4][4];

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			d[i][j] = a[i][j];
		}
	}

	// k = 거쳐가는 노드
	for (int k = 0; k < num; k++)
	{
		// i = 출발 노드
		for (int i = 0; i < num; i++)
		{
			// j = 도착 노드
			for (int j = 0; j < num; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// 결과
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << "  " << d[i][j] <<  " ";
		}
		cout << "\n";
	}
}
void main()
{
	FloydWarshall();
}