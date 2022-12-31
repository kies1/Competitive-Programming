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
    setIO("shuffle");

    int n; std::cin >> n;
    std::vector<int> order(n);
    std::vector<int> id(n);
    
    for(int i = 0; i < n; i++) std::cin >> order[i];
    for(int i = 0; i < n; i++) std::cin >> id[i];

    std::vector<int> ans(n);

    for(int j = 0; j < 3; j++){
        for(int i = 0; i < n; i++){
            ans[i] = id[order[i] -1];
        }
        id = ans;
    }
    
    for(int i = 0; i < n; i++){
        std::cout << ans[i] << nl;
    }
    
    
}