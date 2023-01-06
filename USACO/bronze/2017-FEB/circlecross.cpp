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
    setIO("circlecross");
    
    std::string s; std::cin >> s;
    int n = s.length();

    std::vector<int> start(26, -1);
    std::vector<int> end(26);

    for(int i = 0; i < n; i++){
        if(start[s[i] - 'A'] == -1){
            start[s[i] - 'A'] = i;
        }else{
            end[s[i] - 'A'] = i;
        }
    }

    int ans = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(start[i] < start[j] && start[j] < end[i] && end[i] < end[j]){
                ans++;
            }
        }
    }

    std::cout << ans << nl;
}   



