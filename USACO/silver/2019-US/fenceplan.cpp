//DFS so you have a connected component
//Then find the maximum x and y of all those components to find perimeter
//Answer is the minimum perimeter for all connected components

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
    cin.tie(nullptr);
}

const int MN = 1e5+2;
int ans = MOD; //perimeter 
int max_x = 1, max_y = 1, min_x = MOD, min_y = MOD;

vector<vector<int> > adj(MN);
vector<pair<int, int> > coords(MN);
vector<bool> visited (MN, false);

void dfs(int node){
    visited[node]=true;
    max_x = max(max_x,coords[node].first);
    max_y = max(max_y,coords[node].second);
    min_x = min(min_x, coords[node].first);
    min_y = min(min_y, coords[node].second);

    for(auto child: adj[node]){
        if(visited[child]==false){
            dfs(child);
        }
    }
}

int main() {
    fastRead();
    setIO("fenceplan");
    
    int n,m;
    cin>>n>>m;

    for(int i = 0; i<n; i++){
        int x,y;
        cin>>x>>y;
        coords[i+1]=make_pair(x,y);
    }

    while(m--){
        int a,b; 
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i<=n; i++){
        max_x = 1; max_y = 1; min_x = MOD; min_y = MOD;
        if(visited[i]==false){
            dfs(i);
            ans = min(ans, (max_x-min_x)*2 + (max_y-min_y)*2);
        }
    }

    cout<<ans<<endl;
}
