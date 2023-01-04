#include <bits/stdc++.h>
#include <cmath>
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    setIO("pails");

    int x, y, m;
    std::cin >> x >> y >> m;

    int ans = 0;
    for(int i = 0; i <= m; i+=x){
        for(int j = 0; j <= m && i + j <= m; j+=y){
            int curr = i + j;
            ans = std::max(curr, ans);
        }
    }

    std::cout << ans << nl;
}   



