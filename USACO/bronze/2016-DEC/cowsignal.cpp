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
    setIO("cowsignal");
    
    int m, n, k;
    std::cin >> m >> n >> k;
    char c;
    std::string s;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::cin >> c;
            for(int x = 0; x < k; x++){
                s += c;
            }
        }
        for(int x = 0; x < k; x++){
            std::cout << s << nl;
        }
        s = "";
    }
}