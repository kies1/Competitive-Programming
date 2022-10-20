#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 2;
vector<int> adj[MN];
vector<bool> visited (MN, false);

int dfs(int node, int parent){
    int days = 0;
    visited[node] = true;
    int numChilds = adj[node].size();

    if(parent == 0)numChilds++;
    int x = 1;
    while(x < numChilds){
        x *= 2;
        days++;
    }

    for(auto child: adj[node]){
        if(!visited[child] && child != parent){
            days += dfs(child, node) + 1;
        }
    }    

    return days;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dfs(1, 0) << endl;
}
