#include <bits/stdc++.h>
using namespace std;

constexpr int MN = 3002;
vector<vector<int>> adj(MN);
vector<bool> visited(MN,false);
vector<bool> closed(MN,false);
vector<int> order(MN);
int nodeCnt = 0;

void dfs (int node){

	if(closed[node] || visited[node]) return;

	visited[node]=true;\
	nodeCnt++;

	for(auto child: adj[node]){
		if(visited[child]==false){
			dfs(child);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
        cin.tie(nullptr);
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	int n, m;
	cin>>n>>m;

	for(int i = 0; i < m;i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	if(nodeCnt==n)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	for(int i = 0; i <n; i++){
		cin>>order[i];
	}

	for(int i = 0; i < n-1; i++){
		fill(visited.begin(),visited.end(),false);
		nodeCnt=0;
		closed[order[i]]=true;
		dfs(order[n-1]);
		if(nodeCnt==n-i-1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
