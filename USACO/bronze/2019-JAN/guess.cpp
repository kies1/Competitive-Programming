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
    setIO("guess");
    int n; std::cin >> n;
    std::vector<std::vector<std::string> > traits(n);

    for(int i = 0; i < n; i++){
        std::string name; std::cin >> name;
        int k; std::cin >> k;
        traits[i].resize(k);
        for(int j = 0; j < k; j++){
            std::cin >> traits[i][j];
        }

        std::sort(traits[i].begin(), traits[i].end());
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
                int cnt = 0;
                for(const auto& x: traits[i]){
                    for(const auto& y: traits[j]){
                        if(x == y){
                            cnt++;
                            break;
                        }
                    }
                }
                ans = std::max(ans, cnt);
        }
    }

    std::cout << ans + 1 << nl;
}   



