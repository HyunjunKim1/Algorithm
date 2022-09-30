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
	//���� ������ �� ����� �Ŀ� �� ���� ����(here)�� �߰��� �Ǿ����
	order.push_back(here);
}


void topologicalSort() {
	int n = adj.size();
	visited = vector<bool>(N, false);

	order.clear();

	//������ ������ ���� ��찡 ���� �� �����Ƿ� ��� DFS Ž��
	for (int i = 0; i < N; i++)
		if (!visited[i]) dfs(i);

	//����� ������ �Ųٷ� �����.
	reverse(order.begin(), order.end());
}

void printOrder() {
	for (int i = 0; i < order.size(); i++)
		printf("%c ", order[i] + 'A');
	printf("\n");
}
int main() {
	printf("������ ���� : ");
	cin >> N;

	printf("������ ���� : ");
	cin >> M;

	visited = vector<bool>(N, false);
	adj = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < M; i++) {
		char from, to;
		printf("����1 -> ����2 : ");
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

#define NODECOUNT 7				// ����� ����

int inDegree[NODECOUNT + 1];		// ���� ���� 

vector<int> Nodes[NODECOUNT + 1]; // ��� Node�� Edge ����

void topologySort() {
	int sortedNode[NODECOUNT + 1];// ���������� ������ Node ���� ���
	queue<int> Q;

	// ���� ������ 0�� Node�� Queue�� ��� �߰�
	for (int i = 1; i <= NODECOUNT; i++) {
		if (inDegree[i] == 0) {
			Q.push(i);
		}
	}

	// ��� Node �湮�Ͽ� ������ ���� ������ ����ȭ�� Node ����� ����
	for (int i = 1; i <= NODECOUNT; i++) {
		// N���� ��� ��带 �湮�ϱ� ���� Queue�� empty�̸� cycle�� �߻����� �ǹ�
		if (Q.empty()) {
			cout << "there may be a cycle node" << endl;
			return;
		}

		int x = Q.front();
		Q.pop();
		sortedNode[i] = x;

		// ������ �Ǿ��ִ� ��� �������� Ȯ���ϸ鼭 �������� 
		for (int j = 0; j < Nodes[x].size(); j++) {
			int y = Nodes[x][j];

			// ���������� '0'�� ��� ť�� �߰�
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
	// Edge ����, ���⼺�� ����
	Nodes[start].push_back(end);

	// ���� ���� ����
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
