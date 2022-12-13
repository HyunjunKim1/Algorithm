#include <iostream>
#include <vector>
using namespace std;

// 방문 여부를 확인하는 배열과 실제 간선을 그리는 배열 두개를 선언.
bool isVisited[9];
vector<int> graph[9];

void DFS(int idx)
{
    isVisited[idx] = true;
    cout << idx << " ";

    // 해당 노드의 크기만큼, 즉, 해당 노드와 인접한 노드들의 갯수만큼 반복
    for (int i = 0; i < graph[idx].size(); i++)
    {
        int dist = graph[idx][i];

        // 방문하지 않았으면 즉 isVisited가 False일 때 not을 해주면 True가 되므로 아래 dfs 실행
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