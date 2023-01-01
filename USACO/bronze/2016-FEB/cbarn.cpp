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
    setIO("cbarn");

    int n; std::cin >> n;

    std::vector<ll> cows(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        std::cin >> cows[i];
        sum += cows[i];
    }

    ll ans = 200000000;
    for(int i = 0; i < n; i++){
        ll total = sum;
        ll moves = 0;
        for(int j = i; j < n + i; j++){
            total -= cows[j % n];
            moves += total;
        }
        ans = std::min(ans, moves);
    }

    std::cout << ans << nl;
}



