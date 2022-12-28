/*
Just DFS with a twist, if r is greater than k, then you can visit the other node.
*/
#include <bits/stdc++.h>
#include <tuple>
using namespace std;

typedef long long ll;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

const int MOD = (int) 1e9+7;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void fastRead(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int MN = 5002;
vector<pair<int, int> > adj[MN];
vector<bool> visited (MN, false);
int ans = 0;
int v, k;

void dfs(int node){
	if(visited[node]) return;
	visited[node] = true;
	for(auto child: adj[node]){
		if(visited[child.first]) continue;
		if(child.second >= k){
			ans++;
			dfs(child.first);
		}
	}

}


int main() {
    fastRead();
    setIO("mootube");
	int n, q; cin >> n >> q;

	for(int i = 1; i < n; i++){
		int a, b, r;
		cin >> a >> b >> r;
		adj[a].push_back(make_pair(b, r));
		adj[b].push_back(make_pair(a, r));
	}

	for(int i = 1; i <= q; i++){
		cin >> k >> v;
		fill(visited.begin(), visited.end(), false);
		ans = 0;
		dfs(v);
		cout << ans << endl;
	}
}
