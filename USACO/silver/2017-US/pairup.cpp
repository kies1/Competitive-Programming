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


void solve(){
    int n; std::cin >> n;
    std::vector<std::pair<ll, ll> > milk;

    ll x, y;
    for(int i = 0; i < n; i++){
        std::cin >> x >> y;
        milk.push_back({y, x});
    }

    std::sort(milk.begin(), milk.end());

    ll lo = 0, hi = n - 1;
    ll maxTime = 0;
    while(lo <= hi){
        ll cmin = std::min(milk[lo].second, milk[hi].second);
        maxTime = std::max(milk[lo].first + milk[hi].first, maxTime);
        
        milk[lo].second -= cmin;
        milk[hi].second -= cmin;
        if(milk[lo].second == 0 && milk[hi].second == 0){
            lo++;
            hi--;
        }else if(milk[lo].second == 0){
            lo++;
        }else{
            hi--;
        }
    }

    std::cout << maxTime;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    setIO("pairup");
    solve();
        
}   





