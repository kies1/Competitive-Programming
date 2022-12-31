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
    setIO("blist");

    int n; std::cin >> n;
    std::vector<std::array<int, 3> > cows(n);

    for(int i = 0; i < n; i++){
        std::cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }
    
    int maxBuckets = 0;

    for(int time = 1; time <= 1000; time++){
        int cbuckets = 0;
        for(int i = 0; i < n; i++){
            if(time >= cows[i][0] && time <= cows[i][1]){
                cbuckets += cows[i][2];
            }
        }

        maxBuckets = std::max(maxBuckets, cbuckets);
    }

    std::cout << maxBuckets << nl;
}