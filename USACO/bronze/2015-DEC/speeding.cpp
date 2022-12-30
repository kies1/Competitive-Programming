#include <bits/stdc++.h>
typedef long long ll;
const int MOD  = 1e9 + 7;
#define nl '\n';
#define dbg(v)                                                                 \
    std::cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';

void setIO(std::string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    setIO("speeding");

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int> > road(n);
    std::vector<std::pair<int, int> > route(m);

    for(int i = 0; i < n; i++){
        std::cin >> road[i].first >> road[i].second;
    }

    for(int i = 0; i < m; i++){
        std::cin >> route[i].first >> route[i].second;
    }

    int ans = 0;
    int roadIndex = 0;
    int routeIndex = 0;
    int roadTotal  = road[0].first;
    int routeTotal = route[0].first;
    for(int i = 1; i <= 100; i++){
        if(i > roadTotal){
            roadIndex++;
            roadTotal += road[roadIndex].first;
        }
        if(i > routeTotal){
            routeIndex++;
            routeTotal += route[routeIndex].first;
        }

        ans = std::max(ans, route[routeIndex].second - road[roadIndex].second);
    }

    std::cout << ans << nl;
}