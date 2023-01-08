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
    
    int n, m; 
    std::cin >> n >> m;

    std::vector<std::vector<int> > spotty (n, std::vector<int>(m));
    std::vector<std::vector<int> > plain (n, std::vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; std::cin >> c;
            if(c == 'A'){
                spotty[i][j] = 0;
            }else if(c == 'G'){
                spotty[i][j] = 1;
            }else if(c == 'C'){
                spotty[i][j] = 2;
            }else{
                spotty[i][j] = 3;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; std::cin >> c;
            if(c == 'A'){
                plain[i][j] = 0;
            }else if(c == 'G'){
                plain[i][j] = 1;
            }else if(c == 'C'){
                plain[i][j] = 2;
            }else{
                plain[i][j] = 3;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            for(int k = j + 1; k < m; k++){
                std::vector<bool> ids(64);

                for(int col = 0; col < n; col++){
                    int total = (spotty[col][i] * 16 +
                        spotty[col][j] * 4 +
                        spotty[col][k]);
                    ids[total] = true;
                }

                bool ok = true;
                for(int col = 0; col < n; col++){
                    int total = (plain[col][i] * 16 +
                        plain[col][j] * 4 +
                        plain[col][k]);
                    if(ids[total]){
                            ok = false;
                            break;
                        }
                }
                ans += ok;
            }
        }
    }

    std::cout << ans << nl;
}   



