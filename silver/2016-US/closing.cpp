#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 3002;

vector<vector<int>> adj(MAX_N);
vector<int> visited(MAX_N);
vector<int> closed(MAX_N);
int nodes = 0;


void dfs(int node) {
	if (visited[node] || closed[node]) return;

	nodes++;
	visited[node] = true;
	
	for (int u : adj[node]) {
		if (!visited[u]) dfs(u);
	}
}

int main() {
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	int n,m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<int> order(MAX_N);
	for (int i = 0; i < n; i++){
		int x; cin>>x;
		order[i]=x;
	}

	dfs(1);

	if (nodes == n) {
		cout << "YES"<<endl;
	} else {
		cout << "NO"<<endl;
	}
	
	for (int i = 0; i < n - 1; i++) {
		nodes = 0;
		closed[order[i]] = true;
		fill(visited.begin(), visited.end(), false);

		dfs(order[n - 1]);
		if (nodes == n - i - 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
