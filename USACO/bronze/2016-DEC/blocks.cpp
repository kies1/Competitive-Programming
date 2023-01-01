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
    setIO("blocks");
    
    int n; std::cin >> n;

    std::vector<int> ans(26, 0);

    while(n--){
        std::string a, b; std::cin >> a >> b;
        std::vector<int> freqA(26, 0);
        std::vector<int> freqB(26, 0);

        for(int i = 0; i < a.length(); i++){
            freqA[a[i] - 'a']++;
        }

        for(int i = 0; i < b.length(); i++){
            freqB[b[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            ans[i] += std::max(freqA[i], freqB[i]);
        }
    }

    for(int i = 0; i < 26; i++){
        std::cout << ans[i] << nl;
    }
}



