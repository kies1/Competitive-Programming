#include <bits/stdc++.h>
#include <numeric>
typedef long long ll;
const int MOD  = 1e9 + 7;
#define x first
#define y second
#define nl '\n';
#define dbg(v)                                                                 \
    std::cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';

void setIO(std::string s) { 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

#define MAXN 3002
std::vector<bool> vis(MAXN);
std::vector<std::vector<int> > adj(MAXN);
std::vector<int> order(MAXN);
std::vector<int> closed(MAXN);
int n, m;
int cnt = 0;

void dfs(int node){
    if(vis[node] || closed[node]){
        return;
    }

    vis[node] = true;
    cnt++;

    for(auto child: adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

void solve(){
    std::cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        std::cin >> order[i];
    }

    dfs(1);
    if(cnt == n){
        std::cout << "YES" << nl;
    }else{
        std::cout << "NO" << nl;
    }

    for(int i = 0; i < n - 1; i++){
        cnt = 0;
        std::fill(vis.begin(), vis.end(), false);
        closed[order[i]] = true;
        dfs(order[n - 1]);

        if(cnt == n - i - 1){
            std::cout << "YES" << nl;
        }else{
            std::cout << "NO" << nl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

	setIO("closing");
    solve();
}   