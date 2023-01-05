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
    setIO("lifeguards");
    
    int n; std::cin >> n;
    std::vector<std::pair<int, int> > time(n);

    for(int i = 0; i < n; i++){
        std::cin >> time[i].x >> time[i].y;
    }
    std::sort(time.begin(), time.end());

    int ans = 0;

    for(int i = 0; i < n; i++){
        int small = 1000;
        int big = 0;
        int timeOff = 0;
        int prevLeftOff = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;

            small = std::min(small, time[j].x);
            big = std::max(big, time[j].y);

            if(j > 0){
                timeOff += std::max(time[j].x - prevLeftOff, 0);
                prevLeftOff = time[j].y;
            }else{
                prevLeftOff = time[j].y;
            }
        }
        ans = std::max(big - small - timeOff, ans);
    }

    std::cout << ans << nl;
}   



