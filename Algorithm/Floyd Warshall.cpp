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
	// �׷��� �ʱ�ȭ
	int d[4][4];

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			d[i][j] = a[i][j];
		}
	}

	// k = ���İ��� ���
	for (int k = 0; k < num; k++)
	{
		// i = ��� ���
		for (int i = 0; i < num; i++)
		{
			// j = ���� ���
			for (int j = 0; j < num; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// ���
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