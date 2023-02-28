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

#define MAXN 202
int n;
std::vector<int> power(MAXN);
std::vector<std::pair<int, int> > coords(MAXN);
std::vector<std::vector<int> > adj(MAXN);
std::vector<bool> vis(MAXN);

int dfs(int node){
    int cnt = 0;
    cnt++;
    vis[node] = true;

    for(auto child: adj[node]){
        if(!vis[child]){
            cnt += dfs(child);
        }
    }

    return cnt;
}

void solve(){
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> coords[i].x >> coords[i].y;
        std::cin >> power[i];        
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int xdist = std::abs(coords[i].x - coords[j].x);
            int ydist = std::abs(coords[i].y - coords[j].y);
            
            if(xdist * xdist + ydist * ydist <= power[i] * power[i]){
                adj[i].push_back(j);
            }

            if(xdist * xdist + ydist * ydist <= power[j] * power[j]){
                adj[j].push_back(j);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        std::fill(vis.begin(), vis.end(), false);
        ans = std::max(ans, dfs(i));
    }

    std::cout << ans << nl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    setIO("moocast");
    solve();
}   
