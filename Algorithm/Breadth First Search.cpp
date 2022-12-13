#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isVisited[9];
vector<int> graph[9];

void BFS(int start) 
{
    queue<int> q;
    q.push(start); 
    isVisited[start] = true;

    while (!q.empty()) 
    {
        // ť���� �ϳ��� ���Ҹ� �̾� ���
        int idx = q.front();
        q.pop();
        cout << idx << ' ';
        // �ش� ���ҿ� �����, ���� �湮���� ���� ���ҵ��� ť�� ����
        for (int i = 0; i < graph[idx].size(); i++)
        {
            int dist = graph[idx][i];
            if (!isVisited[dist])
            {
                q.push(dist);
                isVisited[dist] = true;
            }
        }
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

    BFS(1);
}