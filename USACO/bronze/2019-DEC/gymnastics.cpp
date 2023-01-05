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
    setIO("gymnastics");
    
    int k, n; std::cin >> k >> n;

    std::vector<std::vector<int> > results(k, std::vector<int> (n));

    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            std::cin >> results[i][j];
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int iW = 0;
            int jW = 0;
            for(int x = 0; x < k; x++){
                int iindex = 0;
                int jindex = 0;
                for(int y = 0; y < n; y++){
                    if(results[x][y] == i) iindex = y;
                    if(results[x][y] == j) jindex = y;
                }
                if(iindex > jindex) iW++;
                else jW++;
            }
            if(iW == k || jW == k) ans++;
        }
    }

    std::cout << ans << nl;
}   



