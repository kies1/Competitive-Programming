#include <bits/stdc++.h>
#include <numeric>
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
    int n, q; std::cin >> n >> q;
    std::vector<ll> loci(n);

    for(int i = 0; i < n; i++){
        std::cin >> loci[i];
    }

    std::sort(loci.begin(), loci.end());

    while(q--){
        ll l, r;
        std::cin >> l >> r;

        auto itl = std::lower_bound(loci.begin(), loci.end(), l);
        auto itr = std::lower_bound(loci.begin(), loci.end(), r);
        int left = itl - loci.begin();
        int right = itr - loci.begin();

        if(*itr != r){
            right--;
        }
        std::cout << right - left + 1 << nl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    setIO("haybales");
    solve();
} 