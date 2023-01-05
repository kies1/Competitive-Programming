#include <bits/stdc++.h>
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
    setIO("diamond");
    
    int n, k;
    std::cin >> n >> k;
    std::vector<int> diamonds(n);
    
    for(int i = 0; i < n; i++) std::cin >> diamonds[i];

    std::sort(diamonds.begin(), diamonds.end());

    int ans = 0;

    for(int i = 0; i < n; i++){
        int curr = 1;
        for(int j = i + 1; j < n; j++){
            if(diamonds[j] - diamonds[i] <= k) curr++;
            else break;
        }
        ans = std::max(ans, curr);
    }

    std::cout << ans << nl;
}   



