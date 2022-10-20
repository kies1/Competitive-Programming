/*
    Tree traversal,
    you will need to have enough cows for all the childs and the current node, if not then double until you have enough
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = (int) 1e9+7;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void fastRead(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int MN = 1e5 + 2;
vector<int> adj[MN];
vector<bool> visited (MN, false);

int dfs(int node, int parent){
    int days = 0;
    visited[node] = true;
    int numChilds = adj[node].size();

    if(parent == 0)numChilds++; //root needs to include itself
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
