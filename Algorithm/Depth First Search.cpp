#include <iostream>
#include <vector>
using namespace std;

// �湮 ���θ� Ȯ���ϴ� �迭�� ���� ������ �׸��� �迭 �ΰ��� ����.
bool isVisited[9];
vector<int> graph[9];

void DFS(int idx)
{
    isVisited[idx] = true;
    cout << idx << " ";

    // �ش� ����� ũ�⸸ŭ, ��, �ش� ���� ������ ������ ������ŭ �ݺ�
    for (int i = 0; i < graph[idx].size(); i++)
    {
        int dist = graph[idx][i];

        // �湮���� �ʾ����� �� isVisited�� False�� �� not�� ���ָ� True�� �ǹǷ� �Ʒ� dfs ����
        if (!isVisited[dist])
            DFS(dist);
    }
}

int main(void)
{
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

    DFS(1);
}