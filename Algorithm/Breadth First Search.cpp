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
        // 큐에서 하나의 원소를 뽑아 출력
        int idx = q.front();
        q.pop();
        cout << idx << ' ';
        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
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