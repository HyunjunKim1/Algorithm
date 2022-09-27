#include <iostream>
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