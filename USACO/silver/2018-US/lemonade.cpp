#include <bits/stdc++.h>
#include <complex>
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


void solve(){
    int n; std::cin >> n;
    std::vector<ll> cows(n);

    for(int i = 0; i < n; i++){
        std::cin >> cows[i];
    }

    std::sort(cows.rbegin(), cows.rend());

    int in_line = 0;
    for(int i = 0; i < n; i++){
        if(cows[i] < in_line) continue;
        else in_line++;
    }

    std::cout << in_line << nl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    setIO("lemonade");
    solve();
    
}   





