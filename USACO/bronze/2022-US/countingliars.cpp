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

    int n; std::cin >> n;
    std::vector<char> dir(n);
    std::vector<int> len(n);

    for(int i = 0; i < n; i++){
        std::cin >> dir[i] >> len[i];
    }

    int ans = 1000;

    for(int i = 0; i < n; i++){
        int lie = 0;
        for(int j = 0; j < n; j++){
            if(dir[j] == 'G'){
                if(!(len[i] >= len[j])) lie++;
            }else{
                if(!(len[i] <= len[j])) lie++;
            }
        }
        ans = std::min(ans, lie);
    }

    std::cout << ans << nl;
}   



