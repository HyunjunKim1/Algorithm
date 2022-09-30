/*#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<vector<int> > adj;


vector<bool> visited;
vector<int> order;
void dfs(int here) {
	visited[here] = true;

	for (int there = 0; there < adj.size(); there++) {
		if (adj[here][there] && !visited[there])
			dfs(there);
	}
	//위의 정점이 다 종료된 후에 이 곳의 정점(here)이 추가가 되어야함
	order.push_back(here);
}


void topologicalSort() {
	int n = adj.size();
	visited = vector<bool>(N, false);

	order.clear();

	//들어오는 간선이 없을 경우가 있을 수 있으므로 모두 DFS 탐색
	for (int i = 0; i < N; i++)
		if (!visited[i]) dfs(i);

	//종료된 순서를 거꾸로 만든다.
	reverse(order.begin(), order.end());
}

void printOrder() {
	for (int i = 0; i < order.size(); i++)
		printf("%c ", order[i] + 'A');
	printf("\n");
}
int main() {
	printf("정점의 갯수 : ");
	cin >> N;

	printf("간선의 갯수 : ");
	cin >> M;

	visited = vector<bool>(N, false);
	adj = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < M; i++) {
		char from, to;
		printf("정점1 -> 정점2 : ");
		cin >> from >> to;
		adj[from - 'A'][to - 'A'] = 1;
	}

	topologicalSort();
	printOrder();
}
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define NODECOUNT 7				// 노드의 갯수

int inDegree[NODECOUNT + 1];		// 진입 차수 

vector<int> Nodes[NODECOUNT + 1]; // 모든 Node의 Edge 정보

void topologySort() {
	int sortedNode[NODECOUNT + 1];// 위상정렬을 수행한 Node 순서 결과
	queue<int> Q;

	// 진입 차수가 0인 Node를 Queue에 모두 추가
	for (int i = 1; i <= NODECOUNT; i++) {
		if (inDegree[i] == 0) {
			Q.push(i);
		}
	}

	// 모든 Node 방문하여 간선이 없을 때까지 순서화된 Node 결과를 얻음
	for (int i = 1; i <= NODECOUNT; i++) {
		// N개의 모든 노드를 방문하기 전에 Queue가 empty이면 cycle이 발생함을 의미
		if (Q.empty()) {
			cout << "there may be a cycle node" << endl;
			return;
		}

		int x = Q.front();
		Q.pop();
		sortedNode[i] = x;

		// 연결이 되어있는 모든 정점들을 확인하면서 간선제거 
		for (int j = 0; j < Nodes[x].size(); j++) {
			int y = Nodes[x][j];

			// 진입차수가 '0'인 노드 큐에 추가
			if (--inDegree[y] == 0) {
				Q.push(y);
			}
		}
	}

	for (int i = 1; i <= NODECOUNT; i++) {
		cout << "Ordered Node:" << sortedNode[i] << endl;

		Nodes[i].clear();
	}

}

void addEdge(int start, int end)
{
	// Edge 연결, 방향성을 갖음
	Nodes[start].push_back(end);

	// 진입 차수 증가
	inDegree[end]++;
}

void solve()
{
	addEdge(1, 2);
	addEdge(1, 5);
	addEdge(2, 3);
	addEdge(2, 6);
	addEdge(3, 4);
	addEdge(4, 7);
	addEdge(5, 6);
	addEdge(6, 4);

	topologySort();
}

int main()
{
	solve();
	return 0;
}
