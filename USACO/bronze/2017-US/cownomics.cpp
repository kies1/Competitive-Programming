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
    setIO("cownomics");
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<char> > spotty (n, std::vector<char> (m));
    std::vector<std::vector<char> > plain (n, std::vector<char> (m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> spotty[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> plain[i][j];
        }
    }

    int ans = 0;

    for(int i = 0; i < m; i++){
        std::set<char> charSpotty;
        std::set<char> charPlain;

        for(int j = 0; j < n; j++){
            charSpotty.insert(spotty[j][i]);
            charPlain.insert(plain[j][i]);
        }

        bool ok = true;
        for(auto spottyGene: charSpotty){
            for(auto plainGene: charPlain){
                if(spottyGene == plainGene) ok = false;
            }
        }

        if(ok) ans++;
    }

    std::cout << ans << nl;
}   



